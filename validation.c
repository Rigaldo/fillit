/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:24:55 by cburns            #+#    #+#             */
/*   Updated: 2020/01/30 10:24:55 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_adjacency(const char *str)
{
	int		adj;
	int		i;

	adj = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			if (i < 18 && str[i + 1] == '#')
				adj++;
			if (i > 0 && str[i - 1] == '#')
				adj++;
			if (i < 15 && str[i + 5] == '#')
				adj++;
			if (i > 5 && str[i - 5] == '#')
				adj++;
		}
		i++;
	}
	return (adj);
}

int			ft_check_figure(const char *str)
{
	int		i;
	int		dots;
	int		sharps;
	int		adj;

	i = 0;
	dots = 0;
	sharps = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			dots++;
		if (str[i] == '#')
			sharps++;
		if (str[i] == '\n' && ((i + 1) % 5 != 0))
			return (0);
		i++;
	}
	if (dots != 12 || sharps != 4)
		return (0);
	adj = ft_check_adjacency(str);
	if (adj != 6 && adj != 8)
		return (0);
	return (1);
}

int			ft_width(const char *str)
{   
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (i < 4)
	{
		if (str[i] == '#' || str[i + 5] == '#'
			|| str[i + 10] == '#' || str[i + 15] == '#')
			width++;
		i++;
	}
	return (width);
}

int			ft_height(const char *str)
{
	int		i;
	int		height;

	i = 0;
	height = 0;
	while (i < 19)
	{
		if (str[i] == '#' || str[i + 1] == '#'
			|| str[i + 2] == '#' || str[i + 3] == '#')
			height++;
		i += 5;
	}
	return (height);
}
