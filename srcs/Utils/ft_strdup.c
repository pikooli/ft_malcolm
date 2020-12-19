#include "main.h"

char	*ft_strdup(const char *s1)
{
	int i;
	char*dest;

	i = 0;
	while (s1[i])
		i++;
	if (!(dest = malloc(sizeof(*s1) * (i + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = '\0';
	return (dest);
}