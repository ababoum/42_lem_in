#include "../inc/lem_in.h"
#include "../libft/libft.h"

void print_room(t_room *room)
{
    ft_putstr_fd("id: ", 1);
    ft_putnbr_fd(room->id, 1);
    ft_putstr_fd(" name: ", 1);
    ft_putstr_fd(room->name, 1);
    ft_putstr_fd(" type: ", 1);
    ft_putnbr_fd(room->type, 1);
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
        printf("line %zu: %s\n", line_number, line);
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
                    // error
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

            // room
            if (line_items)
            {
                t_room *room = new_room(line_items[0],
                                        ft_atoi(line_items[1]),
                                        ft_atoi(line_items[2]),
                                        room_type);
                if (room)
                {
                    ft_lstadd_back(&rooms, ft_lstnew(room));
                    room_type = NORMAL;
                }
                else
                {
                    ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
                    return (EXIT_FAILURE);
                }
            }
        }
    }
    data.rooms_list = rooms;

    // show all the rooms
    // ft_lstiter(data.rooms_list, (void (*)(void *)) & print_room);

    // links
    if (!line or !ft_strchr(line, '-'))
    {
        ft_putstr_fd("Error: no links\n", STDERR_FILENO);
        return (EXIT_FAILURE);
    }

    while (line)
    {
        line = GET_NEXT_LINE(0);
    }

    return (EXIT_SUCCESS);
}