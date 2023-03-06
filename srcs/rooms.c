#include "../inc/lem_in.h"
#include "../libft/libft.h"

t_room *new_room(const char *name, int x, int y, t_room_type type)
{
    static size_t id = 0;

    t_room *room = malloc(sizeof(t_room));
    if (!room)
        return (NULL);
    room->id = id++;
    room->name = ft_strdup(name);
    room->type = type;
    room->x = x;
    room->y = y;

    return room;
}

char **split_room_line(const char *line)
{
    char **line_items = ft_split(line, ' ');
    if (line_items && tab_len(line_items) == 3)
    {
        if (!ft_is_signed_numeric(line_items[1]) ||
            !ft_is_signed_numeric(line_items[2]))
        {
            ft_putstr_fd("Error: invalid room coordinates\n", STDERR_FILENO);
            return (NULL);
        }
    }
    else
    {
        ft_putstr_fd("Error: invalid room line\n", STDERR_FILENO);
        return (NULL);
    }
    return (line_items);
}