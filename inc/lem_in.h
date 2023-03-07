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
typedef struct s_room
{
    size_t id;
    char *name;
    int x;
    int y;
} t_room;

typedef struct s_data
{
    size_t ants_number;
    size_t rooms_number;
    t_room *rooms_tab;
    char **room_links;
    size_t start_room_id;
    size_t end_room_id;
} t_data;

// Rooms
char **split_room_line(const char *line);
t_room *new_room(const char *name, int x, int y);
size_t get_room_id(t_data *data, const char *name);
char **split_link_line(const char *line);
void free_room(void *room);

// GNL
char *get_next_line(int fd);
char *trim_new_line(char *str);
#define GET_NEXT_LINE(fd) trim_new_line(get_next_line(fd))

// Utils
int ft_is_numeric(const char *str);
int ft_is_signed_numeric(const char *str);
int ft_strcmp(const char *s1, const char *s2);
size_t tab_len(char **tab);
void free_tab(char **tab);

#endif