/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:42:30 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 22:31:23 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void         print_path(t_data *data, t_path *path)
{
    size_t  idx;

    ft_printf("Size of path: %d\n", path->len);
    idx = path->path[0];
    ft_printf("[%s]", data->rooms_tab[idx].name);
    for (size_t i = 1; i < path->len; i++)
    {
        idx = path->path[i];
        ft_printf("->[%s]", data->rooms_tab[idx].name);
    }
    ft_printf("\n");
}