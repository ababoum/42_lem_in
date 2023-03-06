#include "../inc/lem_in.h"


int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_memset(void *ptr, int val, size_t n)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = ptr;
	while (i < n)
		tmp[i++] = val;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}