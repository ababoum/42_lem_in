/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:50:50 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 20:28:12 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static char     *created_visited(t_data *data)
// {
//     char        **visited;

//     visited = malloc(data->rooms_number * sizeof(char *));
//     for (size_t i = 0; i < data->rooms_number; i++)
//     {
//         visited[i] = malloc(data->rooms_number * sizeof(char));
//         visited[i] = 0;
//     }
//     return visited;
// }

t_list      *pathfinder(t_data *data)
{
    t_queue     *queue;
    t_room      *room;
    t_room      *tmp;
    size_t      idx;
    char        *visited;

    ft_printf("start idx: %d\n", data->start_idx);
    ft_printf("end idx: %d\n", data->end_idx);

    queue = malloc(sizeof(t_queue));
    visited = malloc(data->rooms_number);
    initialize(queue);
    room = data->rooms_tab + data->start_idx;
    push(queue, room);
    print_room(room);
    while (!is_empty(queue))
    {
        room = pop(queue);
        ft_printf("\033[32mCurrent room: %s\n\033[0m", room->name);
        idx = room->id;
        visited[idx] = 1;
        for (size_t i = 0; i < data->rooms_number; i++)
        {
            if (data->room_links[idx][i] == 1)
            {
                tmp = data->rooms_tab + i;
                ft_printf("%d Room has connection to %d\n", idx, i);
                if (!visited[i])
                {
                    push(queue, tmp);
                    ft_printf("Pushed %d\n", i);
                }
                else
                    ft_printf("\033[33mAlready visited %d\033[0m\n", i);
            }
        }
    }


    return NULL;
}