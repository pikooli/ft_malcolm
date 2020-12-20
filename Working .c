#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include <asm/types.h>

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>

#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>

#define BUF_SIZE 42
#define DEVICE "enp0s3" // name of the ethernet cart
#define ETH_P_NULL 0x0 
#define ETH_MAC_LEN ETH_ALEN // octer in one ethernet addr
#define ETH_ARP 0x0806  // etherType for ARP protocol 

int s = 0; // server socket 
void * buffer = NULL; // a void pointer 
long total_packets = 0; //number of packet that we receive 
long answered_packets = 0; // number of packet that we respond to 

/*   */
unsigned char * etherhead; // pointer to ethernet header
struct ethhdr *eh; /* another pointer 
                    to ethernet header */
struct sockaddr_ll socket_address; /* struct for device physical address  */

struct arp_header *ah;
unsigned char src_mac[6]; // our mac address
/*   */

void sigint(int signum);
int testSendResponce();

struct __attribute__((packed)) arp_header /* __attribute allows to tell the compiler 
how you want to manage the memory for this struct*/
{
    // this structure is for arp header 
    unsigned short arp_hd; // arp hardware type (HTYPE) 
    unsigned short arp_pr; // arp protocol type (PTYPE)
    unsigned char arp_hdl; // arp hardware length (HLEN)
    unsigned char arp_prl; // arp protocol length (PLEN)
    unsigned short arp_op; // arp operation request (request 1 reply 2)
    unsigned char arp_sha[6]; // sender hardware address (SHA) MAC
    unsigned char arp_spa[4]; // sender protocol address (SPA) ip
    unsigned char arp_dha[6]; // target hardware address (THA) MAC
    unsigned char arp_dpa[4]; // target protocol address (TPA) ip
    // 224 bits 
};

int test()
{
    printf("\n-------------- this is test ------------------\n\n");
    
    buffer = (void *)malloc(BUF_SIZE); // buffer for ethernet frame
    etherhead = buffer; 
    eh = (struct ethhdr *) etherhead; 

    unsigned char *arphead = buffer + 14; // start address of buffer + 14 bits
    /*  we jump the preamble and destination mac address because it should be null */
    
    struct ifreq ifr; /* to get device information with ioctl  */
    int ifindex = 0; /* ethernet interface index  */
    int i;
    int length;     /* length of received packet  */
    int send; 

    printf("Server started, entering initialisation phase...\n");

    /*  open socket */
    s = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if(s == -1)
    {
        perror("socket()");
        exit(1);
    }
    printf("Succeessfully opened socket: %i\n", s);

    /* retrieve ethernet interface index */
    strncpy(ifr.ifr_name, DEVICE, IFNAMSIZ);
    if (ioctl(s, SIOCGIFINDEX, &ifr) == -1) {
        perror("SIOCGIFINDEX");
        exit(1);
    }
    ifindex = ifr.ifr_ifindex;
    printf("Successfully got interface index: %i\n", ifindex);

    /*  retrieve corresponding MAC */
    if (ioctl(s, SIOCGIFHWADDR, &ifr) == -1)
    {
        perror("SIOCGIFINDEX");
        exit(1);
    }
    for(i= 0; i < 6; i++)
    {
        src_mac[i] = ifr.ifr_hwaddr.sa_data[i];
    }
    printf("Successfully got our MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
        src_mac[0],src_mac[1],src_mac[2],src_mac[3],src_mac[4],src_mac[5]);
 
    /* prepare sockaddr_ll  */
    socket_address.sll_family = PF_PACKET; /* for ip v4 address  */
    socket_address.sll_protocol = htons(ETH_P_ARP); /* this is to specify internet protocol packet  */
    socket_address.sll_ifindex = ifindex; /*  here is to retrive the network interface index,  */
    socket_address.sll_hatype = ARPHRD_ETHER; /* specify the ARP hardware type to 
                                                ethernet hardware format */
    socket_address.sll_pkttype = 0; /* PACKET_OTHERHOST */     /* to send a responce to other device, 
                                                    that we caught in promiscuous mode  */
    socket_address.sll_halen = 0;
    socket_address.sll_addr[6] = 0x00;
    socket_address.sll_addr[7] = 0x00;

    /* establish signal handler  */
    signal(SIGINT, sigint);
    printf("Successfully established signal handler for SIGINT\n");
    printf("We are in production state, waiting for incoming packets....\n");

    while(1)
    {
        /* Waiting for a incoming packet...  */
        length = recvfrom(s, buffer, BUF_SIZE, 0, NULL, NULL);
        if (length == -1)
        {
            perror("recvfrom()");
            exit(1);
        }
        printf("Here are first 5 chars only: %.10s\n", buffer);
        if(ntohs(eh->h_proto) == ETH_P_ARP) /*  check if in the buffer we got the
                                            protocols type of arp*/
        {
            ah = (struct arp_header *)arphead;
         
            if (htons(ah->arp_op) != ARPOP_REQUEST) /* check if it a request  */
                continue;

            printf("buffer is---------------- %s \n",(char*)ah);
            printf("H/D TYPE : %x PROTO TYPE : %x \n",ah->arp_hd,ah->arp_pr);
            printf("H/D leng : %x PROTO leng : %x \n",ah->arp_hdl,ah->arp_prl);
            printf("OPERATION : %x \n", ah->arp_op);
            printf("SENDER IP address: %02d:%02d:%02d:%02d\n",
                ah->arp_spa[0],
                ah->arp_spa[1],
                ah->arp_spa[2],
                ah->arp_spa[3]
            );
            printf("SENDER MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                ah->arp_sha[0],
                ah->arp_sha[1],
                ah->arp_sha[2],
                ah->arp_sha[3],
                ah->arp_sha[4],
                ah->arp_sha[5]
            );
            printf("TARGET MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                ah->arp_dha[0],
                ah->arp_dha[1],
                ah->arp_dha[2],
                ah->arp_dha[3],
                ah->arp_dha[4],
                ah->arp_dha[5]
            );
             printf("TARGET IP address: %02d:%02d:%02d:%02d\n",
                ah->arp_dpa[0],
                ah->arp_dpa[1],
                ah->arp_dpa[2],
                ah->arp_dpa[3]
            );
            printf("+++++++++++++++++++++++++++++++++++++++\n" );
            /* address mac of destinatair  */
            printf("ETHER DST MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                eh->h_dest[0],
                eh->h_dest[1],
                eh->h_dest[2],
                eh->h_dest[3],
                eh->h_dest[4],
                eh->h_dest[5]
            );
            /* address mac of source  */
             printf("ETHER SRC MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                eh->h_source[0],
                eh->h_source[1],
                eh->h_source[2],
                eh->h_source[3],
                eh->h_source[4],
                eh->h_source[5]
            );
            printf("before memcpy 1 : %02X:%02X:%02X:%02X:%02X:%02X\n",
                (etherhead)[0],
                (etherhead)[1],
                (etherhead)[2],
                (etherhead)[3],
                (etherhead)[4],
                (etherhead)[5]
            );
            /* copy address mac of source into storage where dest address was, in the ethernet frame */
            memcpy( (void*)etherhead, (const void*)(etherhead+ETH_MAC_LEN),
                ETH_MAC_LEN);
            printf("aflter memcpy 1: %02X:%02X:%02X:%02X:%02X:%02X\n",
                (etherhead)[0],
                (etherhead)[1],
                (etherhead)[2],
                (etherhead)[3],
                (etherhead)[4],
                (etherhead)[5]
            );
            
            printf("before memcpy 2: %02X:%02X:%02X:%02X:%02X:%02X\n",
                (etherhead+ETH_MAC_LEN)[0],
                (etherhead+ETH_MAC_LEN)[1],
                (etherhead+ETH_MAC_LEN)[2],
                (etherhead+ETH_MAC_LEN)[3],
                (etherhead+ETH_MAC_LEN)[4],
                (etherhead+ETH_MAC_LEN)[5]
            );    
            /* copy the mac address of our device into the place where the source mac address where  */
            memcpy( (void*)(etherhead+ETH_MAC_LEN), (const void*)src_mac,
                ETH_MAC_LEN);
            printf("after memcpy 2: %02X:%02X:%02X:%02X:%02X:%02X\n",
                (etherhead+ETH_MAC_LEN)[0],
                (etherhead+ETH_MAC_LEN)[1],
                (etherhead+ETH_MAC_LEN)[2],
                (etherhead+ETH_MAC_LEN)[3],
                (etherhead+ETH_MAC_LEN)[4],
                (etherhead+ETH_MAC_LEN)[5]
            );    
            eh->h_proto = htons(ETH_P_ARP);
            printf("%d %d %d %d\n", ah->arp_dpa[0], ah->arp_dpa[1], ah->arp_dpa[2], ah->arp_dpa[3]);
            if (ah->arp_dpa[0] == 192 && 
                ah->arp_dpa[1] == 168 &&
                ah->arp_dpa[2] == 1 &&
                ah->arp_dpa[3] == 38)
            testSendResponce();

        }                                
    }
}


int testSendResponce()
{
    unsigned char buf_arp_dha[6];
    unsigned char buf_arp_dpa[4];
    int sent;

    printf("\n\n&&&&&&&&&&&&&&&&&&&&&&&&    SEND RESPONSE  &&&&&&&&&&&&&&&&&&&&&&&&&&&& \n\n");
    
    printf("ETHER DST MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
        eh->h_dest[0],
        eh->h_dest[1],
        eh->h_dest[2],
        eh->h_dest[3],
        eh->h_dest[4],
        eh->h_dest[5]
    );
    printf("ETHER SRC MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
        eh->h_source[0],
        eh->h_source[1],
        eh->h_source[2],
        eh->h_source[3],
        eh->h_source[4],
        eh->h_source[5]
    );
    /*  Convert the arp_ */
    // ah->arp_hd = ntohs(ah->arp_hd);
    // ah->arp_pr = ntohs(ah->arp_pr);

    ah->arp_op = htons(ARPOP_REPLY); /* making the op a reply  */

    /* storing the ip of the target */
    buf_arp_dpa[0] = ah->arp_dpa[0];
    buf_arp_dpa[1] = ah->arp_dpa[1];
    buf_arp_dpa[2] = ah->arp_dpa[2];
    buf_arp_dpa[3] = ah->arp_dpa[3];

    /* placing the MAC address of sender as target   */
    ah->arp_dha[0] = ah->arp_sha[0];
    ah->arp_dha[1] = ah->arp_sha[1];
    ah->arp_dha[2] = ah->arp_sha[2];
    ah->arp_dha[3] = ah->arp_sha[3];
    ah->arp_dha[4] = ah->arp_sha[4];
    ah->arp_dha[5] = ah->arp_sha[5];

    /* placing the ip adress of source as target  */

    ah->arp_dpa[0] = ah->arp_spa[0];
    ah->arp_dpa[1] = ah->arp_spa[1];
    ah->arp_dpa[2] = ah->arp_spa[2];
    ah->arp_dpa[3] = ah->arp_spa[3];

    /* copy back the target ip address to become the sender address  */

    ah->arp_spa[0] = buf_arp_dpa[0];
    ah->arp_spa[1] = buf_arp_dpa[1];
    ah->arp_spa[2] = buf_arp_dpa[2];
    ah->arp_spa[3] = buf_arp_dpa[3];

    /* placing a fake mac address as sender that reply to the arp  */
    ah->arp_sha[0] = 0x00;
    ah->arp_sha[1] = 0x1e;
    ah->arp_sha[2] = 0x73;
    ah->arp_sha[3] = 0x78;
    ah->arp_sha[4] = 0x9e;
    ah->arp_sha[5] = 0x0d;

    socket_address.sll_addr[0] = eh->h_dest[0];
    socket_address.sll_addr[1] = eh->h_dest[1];
    socket_address.sll_addr[2] = eh->h_dest[2];
    socket_address.sll_addr[3] = eh->h_dest[3];
    socket_address.sll_addr[4] = eh->h_dest[4];
    socket_address.sll_addr[5] = eh->h_dest[5];
    printf("=======================================\n" );
    printf("SENDER MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
        ah->arp_sha[0],
        ah->arp_sha[1],
        ah->arp_sha[2],
        ah->arp_sha[3],
        ah->arp_sha[4],
        ah->arp_sha[5]
    );
    printf("SENDER IP address: %02d:%02d:%02d:%02d\n",
        ah->arp_spa[0],
        ah->arp_spa[1],
        ah->arp_spa[2],
        ah->arp_spa[3]
    );
    printf("TARGET MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
        ah->arp_dha[0],
        ah->arp_dha[1],
        ah->arp_dha[2],
        ah->arp_dha[3],
        ah->arp_dha[4],
        ah->arp_dha[5]
    );
    printf("TARGET IP address: %02d:%02d:%02d:%02d\n",
        ah->arp_dpa[0],
        ah->arp_dpa[1],
        ah->arp_dpa[2],
        ah->arp_dpa[3]
    );
    printf("H/D TYPE : %x PROTO TYPE : %x \n",ah->arp_hd,ah->arp_pr);
    printf("H/D leng : %x PROTO leng : %x \n",ah->arp_hdl,ah->arp_prl);
    printf("OPERATION : %x \n", ah->arp_op);

    sent = sendto(s, buffer, BUF_SIZE, 0, 
        (struct sockaddr *) &socket_address, sizeof(socket_address));
    if (sent == -1)
    {
        perror("sendto():");
        exit(1);
    }
}

    


void sigint(int signum) {
    /*Clean up.......*/

    struct ifreq ifr;

    if (s == -1)
        return;

    strncpy(ifr.ifr_name, DEVICE, IFNAMSIZ);
    ioctl(s, SIOCGIFFLAGS, &ifr);
    ifr.ifr_flags &= ~IFF_PROMISC;
    ioctl(s, SIOCSIFFLAGS, &ifr);
    close(s);

    free(buffer);

    printf("Server terminating....\n");

    printf("Totally received: %ld packets\n", total_packets);
    printf("Answered %ld packets\n", answered_packets);
    exit(0);
}
