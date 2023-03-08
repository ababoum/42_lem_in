/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:09:34 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 18:09:43 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_room(t_room *room)
{
    ft_printf("id: %d, name: %s, [%d, %d]\n", room->id, room->name, room->x, room->y);
}