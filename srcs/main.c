/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:12:11 by marwa             #+#    #+#             */
/*   Updated: 2023/03/09 01:03:46 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
static void     free_all(t_data *data)
{
    free_path_lst(data);
    // free(data->rooms_tab);
    for (size_t i = 0; i < data->rooms_number; i++)
        free(data->room_links[i]);
    free(data->room_links);
    free(data->path_lst);

}

void    parse_ants_number(t_data *data)
{
    char *line;

    line = GET_NEXT_LINE(0);
    if (!ft_is_numeric(line))
    {
        ft_dprintf(STDERR_FILENO, "Error: invalid number of ants");
        free(line);
        exit(EXIT_FAILURE);
    }
    else
    {
        data->ants_number = ft_atoi(line);
        free(line);
    }
}

int             main(void)
{
    char *line;
    t_data data;
    t_list *rooms = 0;
    t_room_type room_type = NORMAL;
    size_t line_number = 1;

    data.start_idx = -1;
    data.end_idx = -1;
    data.path_lst = NULL;
    
    parse_ants_number(&data);

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
                    if (data.start_idx != (size_t)-1)
                    {
                        // ft_putstr_fd("Error: multiple start rooms\n", STDERR_FILENO);
                        ft_dprintf(STDERR_FILENO, "Error: multiple start rooms\n");
                        free(line);
                        ft_lstclear(&rooms, free_room);
                        return (EXIT_FAILURE);
                    }
                    data.start_idx = room->id;
                    room_type = NORMAL;
                }
                else if (room_type == END)
                {
                    if (data.end_idx != (size_t)-1)
                    {
                        // ft_putstr_fd("Error: multiple end rooms\n", STDERR_FILENO);
                        ft_dprintf(STDERR_FILENO, "Error: multiple end rooms\n");
                        free(line);
                        ft_lstclear(&rooms, free_room);
                        return (EXIT_FAILURE);
                    }
                    data.end_idx = room->id;
                    room_type = NORMAL;
                }
                if (room)
                {
                    ft_lstadd_back(&rooms, ft_lstnew(room));
                    room_type = NORMAL;
                }
                else
                {
                    // ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
                    ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
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
        // ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
        ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
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
        if (i == data.start_idx)
            // ft_putstr_fd("start room: ", 1);
            ft_printf("Start room: ");
        else if (i == data.end_idx)
            // ft_putstr_fd("end room: ", 1);
            ft_printf("End room: ");
        print_room(&data.rooms_tab[i]);
    }

    // prepare links matrix
    data.room_links = ft_calloc(data.rooms_number + 1, sizeof(char *));
    if (!data.room_links)
    {
        // ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
        ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
        return (EXIT_FAILURE);
    }
    else
    {
        for (size_t i = 0; i < data.rooms_number; ++i)
        {
            data.room_links[i] = ft_calloc(data.rooms_number + 1, sizeof(char));
            if (!data.room_links[i])
            {
                // ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
                ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
                free_tab(data.room_links);
                return (EXIT_FAILURE);
            }
        }
    }

    // links
    if (!line || !ft_strchr(line, '-'))
    {
        // ft_putstr_fd("Error: no links\n", STDERR_FILENO);
        ft_dprintf(STDERR_FILENO, "Error: no links\n");
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
                // ft_putstr_fd("Error: invalid link\n", STDERR_FILENO);
                ft_dprintf(STDERR_FILENO, "Error: invalid link\n");
                return (EXIT_FAILURE);
            }
            else
            {
                data.room_links[room1_id][room2_id] = 1;
                data.room_links[room2_id][room1_id] = 1;
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
            ft_printf("%d ", data.room_links[i][j]);
        }
        ft_printf("\n");
    }
    ft_printf("\n\n");
    pathfinder(&data);
    free_all(&data);

    return (EXIT_SUCCESS);
}