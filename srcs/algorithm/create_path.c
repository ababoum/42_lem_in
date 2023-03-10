/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marwa <marwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:11:07 by marwa             #+#    #+#             */
/*   Updated: 2023/03/10 20:52:13 by marwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t      *rev_path(size_t *str, size_t len)
{
    int     temp;
    int     i;
    int     j;

    i = 0;
    j = len - 1;
    while (i <= j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return (str);
}


t_path       *create_path(t_room *room)
{
    size_t       *p;
    t_room      *tmp;
    t_path      *path;
    size_t      counter = 0;

    tmp = room;
    while (tmp->parent != NULL)
    {
        counter++;
        tmp = tmp->parent;
    }
    path = malloc(sizeof(t_path));
    path->ant_num = 0;
    path->len = counter;
    p = malloc(counter * sizeof(size_t));
    counter = 0;
    while (room->parent != NULL)
    {
        p[counter] = room->id;
        room = room->parent;
        counter++;
    }
    path->path = rev_path(p, path->len);
    path->next = NULL;
    return path;
}