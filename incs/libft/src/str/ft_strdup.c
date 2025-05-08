#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	i = ft_strlen(s1);
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (cpy == 0)
		return (0);
	ft_memcpy(cpy, s1, i);
	cpy[i] = '\0';
	return (cpy);
}
