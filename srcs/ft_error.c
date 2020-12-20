#include "main.h"

int ft_print_error(char *str)
{
    ft_putcolor("red");
    printf("%s\n",str);
    ft_putcolor("");

    return (1);
}