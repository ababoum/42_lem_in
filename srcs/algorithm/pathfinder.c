/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:50:50 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 18:40:13 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list      *pathfinder(t_data *data)
{
    t_queue     *queue;
    t_room      *room;
    size_t      start;
    // size_t      end;
    // char        **adj_matrix;

    // adj_matrix = data->room_links;
    // queue = NULL;
    start = data->start_idx;
    // end = data->end_idx;

    queue = malloc(sizeof(t_queue));
    room = data->rooms_tab + start;
    initialize(queue);
    ft_printf("Check\n");
    print_room(room);
    return NULL;
}