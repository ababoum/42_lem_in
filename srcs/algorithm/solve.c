/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:22:10 by marwa             #+#    #+#             */
/*   Updated: 2023/03/10 14:34:09 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void					solve(t_data *data)
// {
// 	t_path		*paths = data->path_lst;
// 	size_t		*ants = data->ants;
// 	size_t		n_ants = data->ants_number;
// 	size_t		n_paths = data->path_size;
// 	size_t		current;
	
// 	ants = malloc(n_ants * sizeof(size_t));
// 	for (size_t i = 0; i < n_ants; i++)
// 	{
// 		current = 0;
// 		for (size_t j = 1; j < n_paths; j++)
// 		{
// 			ft_printf("\033[36m[%d]+[%d] > [%d]+[%d]\033[0m\n", paths[current].len, paths[current].ant_num, paths[j].len, paths[j].ant_num);
// 			if (paths[j].len + paths[j].ant_num < paths[current].len + paths[current].ant_num)
// 			{
// 				current = j;
// 			}
// 		}
// 		ants[i] = current;
// 		ft_printf("\033[32mAnt %d going to path %d\033[0m\n", i, ants[i]);
// 		paths[current].ant_num++;
// 	}
// }


void					print_solution(t_data *data)
{
	
}

void					solve(t_data *data)
{
	t_path		*p = data->path_lst;
	size_t		*ants = data->ants;
	size_t		n_ants = data->ants_number;
	size_t		n_paths = data->path_size;
	size_t		current;
	size_t		**paths;

	paths = malloc(n_paths * sizeof(size_t *));
	for (size_t i = 0; i < n_paths; i++)
	{
		paths[i] = malloc(2 * sizeof(size_t));
		paths[i][0] = p->len;
		paths[i][1] = p->ant_num;
		p = p->next;
	}
	for (size_t i = 0; i < n_paths; i++)
		ft_printf("%d %d %d\n", i, paths[i][0], paths[i][1]);

	ants = malloc(n_ants * sizeof(size_t));
	for (size_t i = 0; i < n_ants; i++)
	{
		current = 0;
		for (size_t j = 1; j < n_paths; j++)
		{
			// ft_printf("\033[36m[%d]+[%d] > [%d]+[%d]\033[0m\n", paths[current][0], paths[current][1], paths[j][0], paths[j][1]);
			if (paths[j][0] + paths[j][1] < paths[current][0] + paths[current][1])
			{
				current = j;
				break;
			}
		}
		ants[i] = current;
		paths[current][1]++;
		ft_printf("\033[32mAnt %d going to path %d\033[0m\n", i, ants[i]);
	}
}