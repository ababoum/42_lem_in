/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:10:17 by marwa             #+#    #+#             */
/*   Updated: 2023/03/09 01:04:42 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*duplicate_room(t_room *room)
{
	t_room 		*tmp;

	tmp = malloc(sizeof(t_room));
	tmp->id = room->id;
	tmp->name = ft_strdup(room->name);
	tmp->parent = room->parent;
	tmp->x = room->x;
	tmp->y = room->y;
	return (tmp);
}