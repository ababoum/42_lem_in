#ifndef LEM_IN_H
#define LEM_IN_H

#define BUFFER_SIZE 100

#define GET_NEXT_LINE(fd) trim_new_line(get_next_line(fd))

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef enum e_room_type
{
    NORMAL,
    START,
    END
} t_room_type;

// Structures
typedef struct s_data
{
    size_t ants_number;
    t_list *rooms_list;
    char **rooms_map;
} t_data;

typedef struct s_room
{
    size_t id;
    char *name;
    t_room_type type;
    int x;
    int y;
} t_room;

// Rooms
char **split_room_line(const char *line);
t_room *new_room(const char *name, int x, int y, t_room_type type);

// GNL
char *get_next_line(int fd);
char *trim_new_line(char *str);
#define GET_NEXT_LINE(fd) trim_new_line(get_next_line(fd))

// Utils
int ft_is_numeric(const char *str);
int ft_is_signed_numeric(const char *str);
int ft_strcmp(const char *s1, const char *s2);
size_t tab_len(char **tab);

#endif