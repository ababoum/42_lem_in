/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:54:31 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 23:12:57 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		push(t_queue *q, t_room *node)
{
	t_node		*tmp;

	tmp = malloc(sizeof(node));
	tmp->data = duplicate_room(node);
	tmp->next = NULL;
	if(!is_empty(q))
	{
		q->rear->next = tmp;
		q->rear = tmp;
	}
	else
		q->front = q->rear = tmp;
	q->count++;
}