/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:47:37 by marwa             #+#    #+#             */
/*   Updated: 2023/03/10 12:57:01 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_path(t_data *data, t_path *path)
{
	t_path		*tmp;
	t_path		*prev;

	// ft_printf("\033[35mAdding Path with size %d\033[0m\n", path->len);
	data->path_size++;
	if (data->path_lst == NULL)
	{
		data->path_lst = path;
		return;
	}
	tmp = data->path_lst;
	prev = data->path_lst;
	while (tmp != NULL && tmp->len <= path->len)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = path;
	path->next = tmp;
}