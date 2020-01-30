/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:51:27 by cburns            #+#    #+#             */
/*   Updated: 2020/01/17 22:51:27 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int  ft_put_error(const char *str) 
{
	ft_putstr_fd(str, 2);
	return (-1);
}

int     main(int argc, char **argv)
{
	int     fd;
	t_list  *list;

	if (argc != 2)
		return (ft_put_error("usage: ./fillit input_file\n"));
	if (!(fd = open(argv[1], O_RDONLY)))
		return (ft_put_error("error1\n"));
	if (!(ft_create_buffer(&list, fd)))
		return (ft_put_error("error2\n"));
	return (0);

}