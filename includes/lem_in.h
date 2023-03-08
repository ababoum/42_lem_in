#ifndef LEM_IN_H
#define LEM_IN_H

#define BUFFER_SIZE 100

#define GET_NEXT_LINE(fd) trim_new_line(get_next_line(fd))

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

typedef enum            e_room_type
{
    NORMAL,
    START,
    END
}                       t_room_type;

// Structures
typedef struct          s_room
{
    size_t              id;
    char                *name;
    int                 x;
    int                 y;
    size_t              *path;
}                       t_room;

typedef struct          s_node
{
    t_room              *room;
    struct s_node       *next;
}                       t_node;

typedef struct          s_queue
{
    int                 count;
    t_node              *front;
    t_node              *rear;
}                       t_queue;

typedef struct queue queue;
typedef struct s_data
{
    size_t              ants_number;
    size_t              rooms_number;
    t_room              *rooms_tab;
    char                **room_links;
    size_t              start_idx;
    size_t              end_idx;
} t_data;

// Rooms
char                    **split_room_line(const char *line);
t_room                  *new_room(const char *name, int x, int y);
size_t                  get_room_id(t_data *data, const char *name);
char                    **split_link_line(const char *line);
void                    free_room(void *room);

// GNL
char                    *get_next_line(int fd);
char                    *trim_new_line(char *str);
#define                 GET_NEXT_LINE(fd) trim_new_line(get_next_line(fd))

// Utils
int                     ft_is_numeric(const char *str);
int                     ft_is_signed_numeric(const char *str);
size_t                  tab_len(char **tab);
void                    free_tab(char **tab);

void                    print_room(t_room *room);

// Queue
void                    initialize(t_queue *q);
size_t                  isempty(t_queue *q);

//Algorithm
t_list                  *pathfinder(t_data *data);

#endif