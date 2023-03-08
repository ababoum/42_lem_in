/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:59:27 by marwa             #+#    #+#             */
/*   Updated: 2023/03/09 00:27:57 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void				free_path_lst(t_data *data)
{
	t_path		*head;
	t_path		*tmp;
	t_path		*prev;

	head = data->path_lst;
	while (head->next != NULL)
	{
		// ft_printf("\033[32m");
		// print_all_paths(data);
		// ft_printf("\033[0m");
		// ft_printf("\n\n");
		tmp = head;
		while (tmp->next != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		free(tmp->path);
		free(tmp);
		tmp = head;
	}
	free(head->path);
	free(head);
	data->path_lst = NULL;
}