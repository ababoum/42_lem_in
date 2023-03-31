/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:22:10 by marwa             #+#    #+#             */
/*   Updated: 2023/03/10 22:21:00 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

# define LEN		0
# define ANT_NUM	1
# define OFFSET		2
# define SIZE		3

t_path					*get_path_by_id(t_data *data, size_t id)
{
	t_path		*p;

	p = data->path_lst;
	while (p != NULL && p->id != id)
		p = p->next;
	return p;
}

static void			print_solution(t_data *data, size_t **solution, size_t max_len)
{
	size_t		n_ants = data->ants_number;
	char		*name;
	size_t		id;


	for (size_t j = 0; j < max_len - 1; j++)
	{
		for (size_t i = 0; i < n_ants; i++)
		{
			if (solution[i][j] != (size_t)-1)
			{
				id = solution[i][j];
				name = data->rooms_tab[id].name;
				ft_printf("L%d-%s ", i+1, name);
			}
		}
		ft_printf("\n");
	}
	ft_printf("\033[32mNumber of lines: %d\033[0m\n", max_len - 1);
}

static size_t		get_max_len(size_t *ants, size_t n_ants, size_t **paths)
{
	size_t		path_id;
	size_t		max_len = 0;

	for (size_t i = 0; i < n_ants; i++)
	{
		path_id = ants[i];
		if (paths[path_id][LEN] + paths[path_id][ANT_NUM] > max_len)
			max_len = paths[path_id][LEN] + paths[path_id][ANT_NUM];
	}
	return (max_len);
}


static void			create_solution(t_data *data, size_t **paths)
{
	t_path		*p;
	size_t		n_ants = data->ants_number;
	size_t		n_paths = data->path_size;
	size_t		*ants = data->ants;
	size_t		**solution;
	size_t		path_id;
	size_t		max_len;
	size_t		it;
	size_t		offset;

	solution = malloc(n_ants * sizeof(size_t *));
	max_len = get_max_len(ants,n_ants, paths);
	ft_printf("\033[36mMax Length: %d\033[0m\n", max_len);
	for (size_t i = 0; i < n_ants; i++)
	{
		path_id = ants[i];
		// lengths[i] = paths[path_id][LEN] + paths[path_id][OFFSET];
		solution[i] = malloc(max_len * sizeof(size_t));
		// ft_printf("Malloced step for ant %d with size %d\n", i, lengths[i]);
		paths[path_id][OFFSET] = paths[path_id][OFFSET] + 1;
	}
	for (size_t i = 0; i < n_paths; i++)
		paths[i][OFFSET] = 0;
	for (size_t i = 0; i < n_ants; i++)
	{
		path_id = ants[i];
		p = get_path_by_id(data, path_id);
		offset = paths[path_id][OFFSET];
		it = 0;
		while (it < offset)
		{
			solution[i][it] = -1;
			it++;
		}
		// ft_printf("it for id %d is: %d\n", i, it);

		it = 0;
		while (it < paths[path_id][LEN] + offset)
		{
			solution[i][it + offset] = p->path[it];
			it++;
		}
		// ft_printf("it for id %d is: %d\n", i, it);
		// ft_printf("it for id %d is: %d\n\n", i, it);
		while (it < max_len)
		{
			solution[i][it] = -1;
			it++;
		}
		paths[path_id][OFFSET] = paths[path_id][OFFSET] + 1;
	}
	for (size_t i = 0; i < n_ants; i++)
	{
		for (size_t j = 0; j < max_len; j++)
			ft_printf("%d ", solution[i][j]);
		ft_printf("\n");
	}
	print_solution(data, solution, max_len);
}

void					solve(t_data *data)
{
	t_path		*p = data->path_lst;
	size_t		n_ants = data->ants_number;
	size_t		n_paths = data->path_size;
	size_t		current;
	size_t		**paths;

	paths = malloc(n_paths * sizeof(size_t *));
	for (size_t i = 0; i < n_paths; i++)
	{
		paths[i] = malloc(4 * sizeof(size_t));
		paths[i][LEN] = p->len;
		paths[i][ANT_NUM] = p->ant_num;
		paths[i][OFFSET] = 0;
		p = p->next;
	}
	// for (size_t i = 0; i < n_paths; i++)
	// 	ft_printf("%d %d %d\n", i, paths[i][0], paths[i][1]);

	data->ants = malloc(n_ants * sizeof(size_t));
	for (size_t i = 0; i < n_ants; i++)
	{
		current = 0;
		for (size_t j = 1; j < n_paths; j++)
		{
			if (paths[j][LEN] + paths[j][ANT_NUM] < paths[current][LEN] + paths[current][ANT_NUM])
			{
				current = j;
				break;
			}
		}
		data->ants[i] = current;
		paths[current][ANT_NUM]++;
		// TODO: check the index of the path in path_lst
		data->path_lst->ant_num++;
		ft_printf("\033[36mAnt %d going to path %d\033[0m\n", i, data->ants[i]);
	}
	// ft_printf("\n\n\033[36mOFFSET:\033[m\n");
	ft_printf("\n");
	create_solution(data, paths);
}