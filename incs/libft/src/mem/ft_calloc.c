#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count && size && count > (UINT_MAX / size))
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
