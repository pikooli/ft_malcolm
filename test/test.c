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

void signint(int signum);

struct __attribute__((packed)) arp_header /* __attribute allows to tell the compiler 
how you want to manage the memory for this struct*/
{
    // this structure is for arp header 
    unsigned short arp_hd; // arp hardware type (HTYPE) 
    unsigned short arp_pr; // arp protocol type (PTYPE)
    unsigned char arp_hdl; // arp hardware length (HLEN)
    unsigned char arp_prl; // arp protocol length (PLEN)
    unsigned short arp_op; // arp operation request (request 1 reply 2)
    unsigned char arp_sha[6]; // sender hardware address (SHA)
    unsigned char arp_spa[4]; // sender protocol address (SPA)
    unsigned char arp_dha[6]; // target hardware address (THA)
    unsigned char arp_dpa[6]; // target protocol address (TPA)
    // 224 bits 
};

int test()
{
    printf("\n-------------- this is test ------------------\n\n");
    
    buffer = (void *)malloc(BUF_SIZE); // buffer for ethernet frame
    unsigned char * etherhead = buffer; // pointer to ethernet header
    struct ethhdr *eh = (struct ethhdr *) etherhead; /* another pointer 
                                                        to ethernet header */

    unsigned char *arphead = buffer + 14; // start address of buffer + 14 bits

    struct arp_header *ah;

    unsigned char src_mac[6]; // our mac address
    
    struct ifreq ifr; /* to get device information with ioctl  */
    struct sockaddr_ll socket_address; /* struct for device physical address  */
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
    socket_address.sll_protocol = htons(ETH_P_IP); /* same in socket for all protocol  */
    socket_address.sll_ifindex = ifindex; /*  here is to retrive the network interface index,  */
    socket_address.sll_hatype = ARPHRD_ETHER;
    socket_address.sll_pkttype = PACKET_OTHERHOST;
    socket_address.sll_halen = 0;
    socket_address.sll_addr[6] = 0x00;
    socket_address.sll_addr[7] = 0x00;

    /* establish signal handler  */
    signal(SIGINT; signit);
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
        if (htons(eh->h_proto) == 0x806) /*  check if in the buffer we got the
                                            protocols type of arp*/
        {
            unsigned char buf_arp_dha[6];
            unsigned char buf_arp_dpa[4];
            
            ah = (struct arp_header *)arphead;
            if (htons(ah->arp_op) != 0x0001) /* check if it a request  */
            
        }                                
    }
}