/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:14:07 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 18:14:14 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t get_room_id(t_data *data, const char *name)
{
    for (size_t i = 0; i < data->rooms_number; ++i)
    {
        if (ft_strcmp(data->rooms_tab[i].name, name) == 0)
            return (i);
    }
    return (-1);
}