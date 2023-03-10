/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:17:43 by marwa             #+#    #+#             */
/*   Updated: 2023/03/10 13:20:43 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_all_paths(t_data *data)
{
	t_path		*p;

	
	ft_printf("\033[32mPath list of size %d:\033[0m\n", data->path_size);
	p = data->path_lst;
	while (p != NULL)
	{
		print_path(data, p);
		p = p->next;
	}
}