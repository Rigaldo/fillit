/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 22:59:14 by cburns            #+#    #+#             */
/*   Updated: 2020/01/30 10:22:36 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_free_list(t_list **list)
{
	t_list		*node;
	t_list		*tail;
	int			i;

	node = *list;
	while (node != NULL)
	{
		tail = node->next;
		if (node->content != NULL)
		{
			i = 0;
			while (((t_etris *)node->content)->figure[i])
			{
				free(((t_etris *)node->content)->figure[i]);
				i++;
			}
			free(((t_etris *)node->content)->figure);
			((t_etris *)node->content)->figure = NULL;
			free(node->content);
			node->content = NULL;
		}
		free(node);
		node = tail;
	}
	return (0);
}

void			ft_free_map(t_map **map)
{
	int			i;

	i = 0;
	if (map != NULL)
	{
		while ((*map)->array[i])
		{
			free((*map)->array[i]);
			i++;
		}
		free((*map)->array);
		(*map)->array = NULL;
		free(map);
		map = NULL;
	}
}

void			ft_print(t_map *map)
{
	int			i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr_fd(map->array[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
