/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:50:50 by marwa             #+#    #+#             */
/*   Updated: 2023/03/09 01:09:32 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				free_queue(t_queue *queue)
{
    t_room  *tmp;

	while (!is_empty(queue))
    {
        tmp = pop(queue);
        free(tmp->name);
        free(tmp);
    }
}


t_list              *pathfinder(t_data *data)
{
    t_queue     *queue;
    t_queue     *to_free;
    t_room      *current;
    t_room      *tmp;
    t_path      *path;
    size_t      idx;
    char        *visited;

    ft_printf("start idx: %d\n", data->start_idx);
    ft_printf("end idx: %d\n", data->end_idx);
    ft_printf("\n\n");

    queue = malloc(sizeof(t_queue));
    to_free = malloc(sizeof(t_queue));
    visited = malloc(data->rooms_number);
    for (size_t i = 0; i <data->rooms_number; i++)
        visited[i] = 0;
    initialize(queue);
    initialize(to_free);
    current = data->rooms_tab + data->start_idx;
    push(queue, current, 1);
    push(to_free, current, 0);
    // print_room(current);
    while (!is_empty(queue))
    {
        current = pop(queue);
        push(to_free, current, 0);
        idx = current->id;
        // ft_printf("\033[32mCurrent Room: %s\n\033[0m", current->name);
        if (current->id == data->end_idx)
        {
            // ft_printf("\033[36mReached end: %s\n\033[0m", current->name);
            path = create_path(current);
            add_path(data, path);
            visited[data->start_idx] = 0;
            visited[data->end_idx] = 0;
            continue;
        }
        visited[idx] = 1;
        for (size_t i = 0; i < data->rooms_number; i++)
        {
            if (data->room_links[idx][i] == 1)
            {
                tmp = data->rooms_tab + i;
                // ft_printf("%d Room has connection to %d\n", idx, i);
                if (!visited[i])
                {
                    tmp->parent = current;
                    push(queue, tmp, 1);
                    // ft_printf("Pushed %d\n", i);
                }
                // else
                    // ft_printf("\033[33mAlready visited %d\033[0m\n", i);
            }
        }
    }
    ft_printf("\n\n");
    print_all_paths(data);
    free_queue(to_free);
    free(queue);
    free(to_free);
    free(visited);
    return NULL;
}