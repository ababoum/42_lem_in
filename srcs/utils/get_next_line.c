#include "lem_in.h"

static int find_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char *ft_concat(char *s1, char *s2, size_t len)
{
	char *concat;
	size_t i;

	if (len < ft_strlen(s2))
		concat = ft_calloc(ft_strlen(s1) + len + 1, 1);
	else
		concat = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	i = -1;
	while (s1[++i])
		concat[i] = s1[i];
	i = -1;
	while (s2[++i] && i < len)
		concat[ft_strlen(concat)] = s2[i];
	free(s1);
	return (concat);
}

static void get_read(char *buffer, int fd, int *read_len, int *cursor)
{
	ft_memset(buffer, 0, BUFFER_SIZE);
	*read_len = read(fd, buffer, BUFFER_SIZE);
	*cursor = 0;
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1] = {0};
	static int cs = 0;
	static int read_len = 0;
	char *output;

	if ((!cs && !read_len) || cs == read_len)
		get_read(buf, fd, &read_len, &cs);
	if (read_len == -1 || read_len == 0)
		return (NULL);
	output = ft_calloc(1, 1);
	while (cs < read_len)
	{
		if (find_char(buf + cs, '\n') == -1)
		{
			output = ft_concat(output, buf + cs, BUFFER_SIZE);
			get_read(buf, fd, &read_len, &cs);
		}
		else
		{
			output = ft_concat(output, buf + cs, 1 + find_char(buf + cs, '\n'));
			cs += 1 + find_char(buf + cs, '\n');
			break;
		}
	}
	return (output);
}
