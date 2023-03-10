#include "lem_in.h"

t_list *parse_rooms(t_data *data, char **ptr_line)
{
    t_list *rooms = 0;
    char *line;
    t_room_type room_type = NORMAL;

    while ((line = GET_NEXT_LINE(0)) && !ft_strchr(line, '-'))
    {
        if (line[0] == '#')
        {
            if (line[1] == '#')
            {
                if (ft_strcmp(line, "##start") == 0)
                    room_type = START;
                else if (ft_strcmp(line, "##end") == 0)
                    room_type = END;
                else
                    continue;
            }
            else
                continue;
        }
        else
        {
            char **line_items = split_room_line(line);

            if (!line_items)
            {
                free(line);
                ft_lstclear(&rooms, free_room);
                return (NULL);
            }
            // room
            else
            {
                t_room *room = new_room(line_items[0],
                                        ft_atoi(line_items[1]),
                                        ft_atoi(line_items[2]));
                free_tab(line_items);
                if (room_type == START)
                {
                    if (data->start_idx != (size_t)-1)
                    {
                        ft_dprintf(STDERR_FILENO, "Error: multiple start rooms\n");
                        free(line);
                        free_room(room);
                        ft_lstclear(&rooms, free_room);
                        return (NULL);
                    }
                    data->start_idx = room->id;
                }
                else if (room_type == END)
                {
                    if (data->end_idx != (size_t)-1)
                    {
                        ft_dprintf(STDERR_FILENO, "Error: multiple end rooms\n");
                        free(line);
                        free_room(room);
                        ft_lstclear(&rooms, free_room);
                        return (NULL);
                    }
                    data->end_idx = room->id;
                }
                if (room)
                {
                    ft_lstadd_back(&rooms, ft_lstnew(room));
                }
                else
                {
                    ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
                    free(line);
                    ft_lstclear(&rooms, free_room);
                    return (NULL);
                }
                room_type = NORMAL;
            }
            
        }
        free(line);
    }
    *ptr_line = line;
    return (rooms);
}