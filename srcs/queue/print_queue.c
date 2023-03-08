/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:00:09 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 19:34:24 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_queue(t_queue *q)
{
	t_node	*rear;

	rear = q->rear;
	while (rear != NULL)
	{
		ft_printf("\033[32m]");
		print_room(rear->data);
		rear = rear->next;
	}
	ft_printf("\033[0m]");
}