/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:11:52 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 20:40:21 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*new_room(const char *name, int x, int y)
{
    static size_t id = 0;

    t_room *room = malloc(sizeof(t_room));
    if (!room)
        return (NULL);
    room->id = id++;
    room->name = ft_strdup(name);
    room->x = x;
    room->y = y;
    room->parent = NULL;

    return room;
}