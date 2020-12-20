#include "main.h"

int main(int ac, char **av)
{   
    if (ft_check_arg(ac, av))
    {
        system("leaks a.out");
        return (0);
    }
    ft_getIpAddress();
    system("leaks a.out");
}