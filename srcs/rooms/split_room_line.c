/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_room_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:13:29 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 18:13:37 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char **split_room_line(const char *line)
{
    char **line_items = ft_strsplit(line, ' ');

    if (!line_items) {
        ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
        return (NULL);
    }
    else if (tab_len(line_items) == 3)
    {
        if (!ft_is_signed_numeric(line_items[1]) ||
            !ft_is_signed_numeric(line_items[2]))
        {
            ft_dprintf(STDERR_FILENO, "Error: invalid room coordinates\n");
            free_tab(line_items);
            return (NULL);
        }
    }
    else
    {
        ft_dprintf(STDERR_FILENO, "Error: invalid room line\n");
        free_tab(line_items);
        return (NULL);
    }
    return (line_items);
}