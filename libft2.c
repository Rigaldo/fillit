/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 10:06:37 by cburns            #+#    #+#             */
/*   Updated: 2020/01/30 10:28:35 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

char				*ft_strncpy(char *dest, char const *s, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (s[j])
		{
			dest[i] = s[j];
			i++;
			j++;
		}
		else
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}

void				ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!dest && !src && n)
		return (NULL);
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}

void				*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*sym;
	size_t			i;

	sym = (unsigned char *)dest;
	i = 0;
	while (i < n)
		sym[i++] = (unsigned char)c;
	return (dest);
}
