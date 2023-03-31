#ifndef LEM_IN_H
#define LEM_IN_H

#define BUFFER_SIZE 100

#define GET_NEXT_LINE(fd) trim_new_line(get_next_line(fd))

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "../libft/includes/libft.h"

// Structures
typedef enum            e_room_type
{
    NORMAL,
    START,
    END
}                       t_room_type;

typedef struct          s_room
{
    size_t              id;
    char                *name;
    int                 x;
    int                 y;
    struct s_room      *parent;
}                       t_room;

typedef struct          s_path
{
    size_t              id;
    size_t              len;
    size_t              *path;
    size_t              ant_num;
    struct s_path       *next;
}                       t_path;

typedef struct          s_data
{
    size_t              ants_number;
    size_t              rooms_number;
    t_room              *rooms_tab;
    char                **room_links;
    t_path              *path_lst;
    size_t              path_size;
    size_t              *ants;
    size_t              start_idx;
    size_t              end_idx;
}                       t_data;

typedef struct          s_node
{
    t_room              *data;
    struct s_node       *next;
}                       t_node;

typedef struct          s_queue
{
    int                 count;
    t_node              *front;
    t_node              *rear;
}                       t_queue;

// Rooms
void                    free_room(void *room);
size_t                  get_room_id(t_data *data, const char *name);
t_room                  *new_room(const char *name, int x, int y);
void                    print_room(t_room *room);
char                    **split_link_line(const char *line);
char                    **split_room_line(const char *line);
t_room                  *duplicate_room(t_room *room);
void                    print_links(t_data *data);
t_list                  *parse_rooms(t_data *data, char **ptr_line);
// GNL
char                    *get_next_line(int fd);
#define                 GET_NEXT_LINE(fd) trim_new_line(get_next_line(fd))

// Utils
void                    free_tab(char **tab);
int                     ft_is_numeric(const char *str);
int                     ft_is_signed_numeric(const char *str);
size_t                  tab_len(char **tab);
char                    *trim_new_line(char *str);

//Queue
void                    initialize(t_queue *q);
size_t                  is_empty(t_queue *q);
void                    push(t_queue *q, t_room *node, char dup_flag);
// void                    push(t_queue *q, t_room *node);
t_room                  *pop(t_queue *q);
void                    print_queue(t_queue *q);


//Algorithm
t_path  	            *create_path(t_room *room);
void                    add_path(t_data *data, t_path *path);
t_list                  *pathfinder(t_data *data);
void                    print_path(t_data *data, t_path *path);
void                    print_all_paths(t_data *data);
// void                    free_path_lst(t_path *path_lst);
void                    free_path_lst(t_data *data);
void                    solve(t_data *data);

#endif