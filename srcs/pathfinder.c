/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:50:50 by marwa             #+#    #+#             */
/*   Updated: 2023/03/07 19:22:35 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list      *pathfinder(t_data *data)
{
    t_list      *queue;
    t_list      *node;
    size_t      start;
    size_t      end;
    char        **adj_matrix;

    adj_matrix = data->room_links;
    queue = NULL;
    start = data->start_idx;
    end = data->end_idx;

    node = ft_lstnew(data->rooms_tab + start)
    



}