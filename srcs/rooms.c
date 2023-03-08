#include "../inc/lem_in.h"

t_room *new_room(const char *name, int x, int y)
{
    static size_t id = 0;

    t_room *room = malloc(sizeof(t_room));
    if (!room)
        return (NULL);
    room->id = id++;
    room->name = ft_strdup(name);
    room->x = x;
    room->y = y;

    return room;
}

char **split_room_line(const char *line)
{
    char **line_items = ft_strsplit(line, ' ');

    if (!line_items) {
        ft_putstr_fd("Error: invalid room line\n", STDERR_FILENO);
        return (NULL);
    }
    else if (tab_len(line_items) == 3)
    {
        if (!ft_is_signed_numeric(line_items[1]) ||
            !ft_is_signed_numeric(line_items[2]))
        {
            ft_putstr_fd("Error: invalid room coordinates\n", STDERR_FILENO);
            free_tab(line_items);
            return (NULL);
        }
    }
    else
    {
        ft_putstr_fd("Error: invalid room line\n", STDERR_FILENO);
        free_tab(line_items);
        return (NULL);
    }
    return (line_items);
}

size_t get_room_id(t_data *data, const char *name)
{
    for (size_t i = 0; i < data->rooms_number; ++i)
    {
        if (ft_strcmp(data->rooms_tab[i].name, name) == 0)
            return (i);
    }
    return (-1);
}

char **split_link_line(const char *line)
{
    char **line_items = ft_strsplit(line, '-');
    if (line_items && tab_len(line_items) == 2)
    {
        return (line_items);
    }
    else
    {
        ft_putstr_fd("Error: invalid link line\n", STDERR_FILENO);
        return (NULL);
    }
}

void free_room(void *room)
{
    free(((t_room *)room)->name);
    free(room);
}