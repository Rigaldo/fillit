/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free&print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:59:14 by cburns            #+#    #+#             */
/*   Updated: 2020/01/29 00:32:05 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_free_list(t_list **list)
{
    t_list  *node;
    t_list  *tail;

    node = *list;
    if (list != NULL)
    {
        while (node != NULL)
        {
            tail = node->next; 
            //вот тут нужно дописать очистку фигуры(tetr->figure) в цикле, а я ушел спать ня^^
            free(node->content);
            node->content = NULL;
            free(node);
            node = tail;
        }
    }
}

void    ft_free_map(t_map **map)
{
    if (map != NULL)
    {
        free((*map)->array);
        free(map);
        map = NULL;
    }
}

void ft_print(t_map *map)
{
    int i;

    i = 0;
    while (i < map->size)
    {
        ft_putstr(map->array[i]);
        ft_putchar('\n');
        i++;
    }
}