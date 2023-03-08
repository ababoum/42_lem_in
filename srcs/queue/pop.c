/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:06:05 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 20:03:04 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*pop(t_queue *q)
{
    t_node		*tmp;
	t_room		*ret;

    ret = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
	if (q->count == 0)
		q->rear = NULL;
	
    free(tmp);
	
    return(ret);
}