/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_link_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:14:32 by marwa             #+#    #+#             */
/*   Updated: 2023/03/08 18:14:43 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char **split_link_line(const char *line)
{
    char **line_items = ft_strsplit(line, '-');
    if (!line_items)
    {
        ft_dprintf(STDERR_FILENO, "Error: malloc failed\n");
        return (NULL);
    }
    else if (tab_len(line_items) == 2)
    {
        return (line_items);
    }
    else
    {
        ft_dprintf(STDERR_FILENO, "Error: invalid link line\n");
        free_tab(line_items);
        return (NULL);
    }
}