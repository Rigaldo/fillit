/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:59:14 by cburns            #+#    #+#             */
/*   Updated: 2020/01/20 00:14:22 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
            free(node->content);
            node->content = NULL;
            free(node);
            node = tail;
        }
    }
}