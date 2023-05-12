/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:12:11 by marwa             #+#    #+#             */
/*   Updated: 2023/05/12 18:08:35 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void     free_all(t_data *data)
{
    free_path_lst(data);
    free_tab(data->room_links);
    for (size_t i = 0; i < data->rooms_number; ++i)
    {
        free(data->rooms_tab[i].name);
    }
    free(data->ants);
    free(data->rooms_tab);
    free(data->path_lst);
}

void identity(void *elem)
{
    (void)elem;
}

static void    parse_ants_number(t_data *data)
{
    char *line = GET_NEXT_LINE(0);

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
    if (data->ants_number <= 0)
    {
        ft_dprintf(STDERR_FILENO, "Error: invalid number of ants");
        exit(EXIT_FAILURE);
    }
}

static void init_data(t_data *data)
{
    data->start_idx = -1;
    data->end_idx = -1;
    data->path_lst = NULL;
    data->rooms_tab = NULL;
    data->room_links = NULL;
    data->ants = NULL;
    data->path_size = 0;
}

static void prepare_rooms_tab(t_data *data, t_list **rooms_ptr)
{
    t_list *rooms = *rooms_ptr;
    t_list *begin = rooms;

    data->rooms_number = ft_lstsize(rooms);
    data->rooms_tab = malloc(sizeof(t_room) * data->rooms_number);
    if (!data->rooms_tab)
    {
        ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
        ft_lstclear(&rooms, free_room);
        exit(EXIT_FAILURE);
    }

    // fill rooms mapping tab
    for (size_t i = 0; i < data->rooms_number; ++i)
    {
        data->rooms_tab[i] = *(t_room *)rooms->content;
        free(rooms->content);
        rooms = rooms->next;
    }

    // delete the chained list without destroying the rooms
    ft_lstclear(&begin, identity);
}

static int prepare_links_matrix(t_data *data)
{
    data->room_links = ft_calloc(data->rooms_number + 1, sizeof(char *));
    if (!data->room_links)
    {
        ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
        return (EXIT_FAILURE);
    }
    else
    {
        for (size_t i = 0; i < data->rooms_number; ++i)
        {
            data->room_links[i] = ft_calloc(data->rooms_number + 1, sizeof(char));
            if (!data->room_links[i])
            {
                ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
                free_tab(data->room_links);
                return (EXIT_FAILURE);
            }
        }
    }
    return (EXIT_SUCCESS);
}

static int parse_links(t_data *data, char **ptr_line)
{
    char *line = *ptr_line;

    while (line)
    {
        if (line[0] == '#') // comment line
        {
            free(line);
            line = GET_NEXT_LINE(0);
            continue;
        }
        else if (!ft_strchr(line, '-')) // all link lines must contain a '-' char
        {
            ft_dprintf(STDERR_FILENO, "Error: invalid link line\n");
            free(line);
            return (EXIT_FAILURE);
        }

        char **line_items = split_link_line(line);

        // link
        if (line_items)
        {
            size_t room1_id = get_room_id(data, line_items[0]);
            size_t room2_id = get_room_id(data, line_items[1]);

            if (room1_id == (size_t)-1 || room2_id == (size_t)-1)
            {
                ft_dprintf(STDERR_FILENO, "Error: invalid link\n");
                free_tab(line_items);
                free(line);
                return (EXIT_FAILURE);
            }
            else
            {
                data->room_links[room1_id][room2_id] = 1;
                data->room_links[room2_id][room1_id] = 1;
            }
        }
        else
        {
            free(line);
            return (EXIT_FAILURE);
        }
        free_tab(line_items);
        free(line);
        line = GET_NEXT_LINE(0);
    }
    *ptr_line = line;
    return (EXIT_SUCCESS);
}

int             main(void)
{
    char *line;
    t_data data;
    t_list *rooms = 0;

    init_data(&data);
    parse_ants_number(&data);

    // rooms
    rooms = parse_rooms(&data, &line);
    if (!rooms)
    {
        return (EXIT_FAILURE);
    }

    prepare_rooms_tab(&data, &rooms);

    // show the rooms mapping tab
    for (size_t i = 0; i < data.rooms_number; ++i)
    {
        if (i == data.start_idx)
            ft_printf("Start room: ");
        else if (i == data.end_idx)
            ft_printf("End room: ");
        print_room(&data.rooms_tab[i]);
    }

    // prepare links matrix
    if (prepare_links_matrix(&data) == EXIT_FAILURE)
    {
        free_all(&data);
        return (EXIT_FAILURE);
    }

    // links
    if (!line || !ft_strchr(line, '-'))
    {
        ft_dprintf(STDERR_FILENO, "Error: no links\n");
        free_all(&data);
        return (EXIT_FAILURE);
    }

    if (parse_links(&data, &line) == EXIT_FAILURE)
    {
        free_all(&data);
        return (EXIT_FAILURE);
    }

    ft_printf("\n\n");
    pathfinder(&data);
    // ft_printf("\033[32mCheck Pathfinder\033[0m\n\n");
    solve(&data);
    // ft_printf("\033[32mCheck Solve\033[0m\n\n");
    free_all(&data);

    return (EXIT_SUCCESS);
}