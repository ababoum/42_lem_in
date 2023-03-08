/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:00:09 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 18:03:01 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_queue(t_queue *q)
{
	t_node	*rear;

	rear = q->rear;
	while (rear != NULL)
	{
		print_room(rear->room);
		rear = rear->next;
	}
}