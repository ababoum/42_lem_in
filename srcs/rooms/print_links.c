/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:13:33 by marwa             #+#    #+#             */
/*   Updated: 2023/03/10 13:14:06 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			print_links(t_data *data)
{
    for (size_t i = 0; i < data->rooms_number; ++i)
    {
        for (size_t j = 0; j < data->rooms_number; ++j)
        {
            ft_printf("%d ", data->room_links[i][j]);
        }
        ft_printf("\n");
    }
}