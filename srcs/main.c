#include "../inc/lem_in.h"
#include "../libft/libft.h"

void print_room(t_room *room)
{
    ft_putstr_fd("id: ", 1);
    ft_putnbr_fd(room->id, 1);
    ft_putstr_fd(" name: ", 1);
    ft_putstr_fd(room->name, 1);
    ft_putstr_fd(" x: ", 1);
    ft_putnbr_fd(room->x, 1);
    ft_putstr_fd(" y: ", 1);
    ft_putnbr_fd(room->y, 1);
    ft_putstr_fd("\n", 1);
}

int main(void)
{
    char *line;
    t_data data;
    t_list *rooms = 0;
    t_room_type room_type = NORMAL;
    size_t line_number = 1;

    data.start_room_id = -1;
    data.end_room_id = -1;
    
    // number of ants
    line = GET_NEXT_LINE(0);
    if (!ft_is_numeric(line))
    {
        ft_putstr_fd("Error: invalid number of ants", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    else
    {
        data.ants_number = ft_atoi(line);
        free(line);
    }

    // rooms
    while ((line = GET_NEXT_LINE(0)) && !ft_strchr(line, '-'))
    {
        ++line_number;
        if (line[0] == '#')
        {
            if (line[1] == '#')
            {
                if (ft_strcmp(line, "##start") == 0)
                {
                    // start room
                    room_type = START;
                }
                else if (ft_strcmp(line, "##end") == 0)
                {
                    // end room
                    room_type = END;
                }
                else
                {
                    // comment beginning with ##
                    continue;
                }
            }
            else
            {
                // comment
                continue;
            }
        }
        else
        {
            char **line_items = split_room_line(line);

            if (!line_items)
            {
                free(line);
                ft_lstclear(&rooms, free_room);
                return (EXIT_FAILURE);
            }
            // room
            else
            {
                t_room *room = new_room(line_items[0],
                                        ft_atoi(line_items[1]),
                                        ft_atoi(line_items[2]));
                if (room_type == START)
                {
                    if (data.start_room_id != (size_t)-1)
                    {
                        ft_putstr_fd("Error: multiple start rooms\n", STDERR_FILENO);
                        free(line);
                        ft_lstclear(&rooms, free_room);
                        return (EXIT_FAILURE);
                    }
                    data.start_room_id = room->id;
                    room_type = NORMAL;
                }
                else if (room_type == END)
                {
                    if (data.end_room_id != (size_t)-1)
                    {
                        ft_putstr_fd("Error: multiple end rooms\n", STDERR_FILENO);
                        free(line);
                        ft_lstclear(&rooms, free_room);
                        return (EXIT_FAILURE);
                    }
                    data.end_room_id = room->id;
                    room_type = NORMAL;
                }
                if (room)
                {
                    ft_lstadd_back(&rooms, ft_lstnew(room));
                    room_type = NORMAL;
                }
                else
                {
                    ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
                    free(line);
                    ft_lstclear(&rooms, free_room);
                    return (EXIT_FAILURE);
                }
            }
            
        }
        free(line);
    }
    data.rooms_number = ft_lstsize(rooms);
    data.rooms_tab = malloc(sizeof(t_room) * data.rooms_number);
    if (!data.rooms_tab)
    {
        ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
        return (EXIT_FAILURE);
    }

    // fill rooms mapping tab
    for (size_t i = 0; i < data.rooms_number; ++i)
    {
        data.rooms_tab[i] = *(t_room *)rooms->content;
        rooms = rooms->next;
    }

    // free the list
    ft_lstclear(&rooms, free_room);

    // show the rooms mapping tab
    for (size_t i = 0; i < data.rooms_number; ++i)
    {
        if (i == data.start_room_id)
            ft_putstr_fd("start room: ", 1);
        else if (i == data.end_room_id)
            ft_putstr_fd("end room: ", 1);
        print_room(&data.rooms_tab[i]);
    }

    // prepare links matrix
    data.room_links = ft_calloc(data.rooms_number + 1, sizeof(char *));
    if (!data.room_links)
    {
        ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    else
    {
        for (size_t i = 0; i < data.rooms_number; ++i)
        {
            data.room_links[i] = ft_calloc(data.rooms_number + 1, sizeof(char));
            if (!data.room_links[i])
            {
                ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
                free_tab(data.room_links);
                return (EXIT_FAILURE);
            }
        }
    }

    // links
    if (!line || !ft_strchr(line, '-'))
    {
        ft_putstr_fd("Error: no links\n", STDERR_FILENO);
        return (EXIT_FAILURE);
    }

    while (line && ft_strchr(line, '-'))
    {
        ++line_number;
        char **line_items = split_link_line(line);

        // link
        if (line_items)
        {
            size_t room1_id = get_room_id(&data, line_items[0]);
            size_t room2_id = get_room_id(&data, line_items[1]);

            if (room1_id == (size_t)-1 || room2_id == (size_t)-1)
            {
                ft_putstr_fd("Error: invalid link\n", STDERR_FILENO);
                return (EXIT_FAILURE);
            }
            else
            {
                data.room_links[room1_id][room2_id] = 1;
            }
        }
        free(line);
        line = GET_NEXT_LINE(0);
    }

    // print links

    for (size_t i = 0; i < data.rooms_number; ++i)
    {
        for (size_t j = 0; j < data.rooms_number; ++j)
        {
            printf("%d ", data.room_links[i][j]);
        }
        printf("\n");
    }

    return (EXIT_SUCCESS);
}