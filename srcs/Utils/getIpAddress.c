#include "main.h"

char * getIpAddress()
{
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    char *addr;
    char *ret;

    getifaddrs (&ifap);

    for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family==AF_INET) {
            sa = (struct sockaddr_in *) ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
            if (ft_strcmp(ifa->ifa_name,"lo")){
                ret = ft_strdup(addr);
                printf("Your interface is: %s\t Your ip address is: %s\n", ifa->ifa_name, addr);

            }
        }
    }

    freeifaddrs(ifap);
    return ret;
}