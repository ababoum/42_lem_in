#ifndef LEM_IN_H
# define LEM_IN_H

# define BUFFER_SIZE 100

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);

// Utils
int		ft_strlen(char *str);
void	ft_memset(void *ptr, int val, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);


#endif