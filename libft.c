/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:07:34 by cburns            #+#    #+#             */
/*   Updated: 2020/01/30 09:16:54 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!(*alst))
		*alst = new;
	else
	{
		current = *alst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*element;

	if (!(element = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		element->content = NULL;
		element->content_size = 0;
	}
	else
	{
		if (!(element->content = malloc(content_size)))
		{
			free(element);
			return (NULL);
		}
		element->content = ft_memcpy(element->content, content, content_size);
		element->content_size = content_size;
	}
	element->next = NULL;
	return (element);
}

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	mem = ft_memset(mem, 0, size);
	return (mem);
}

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	i;

	i = 0;
	if (s && fd >= 0)
		while (s[i])
			ft_putchar_fd(s[i++], fd);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

char	*ft_strncpy(char *dest, char const *s, size_t n)
{
	size_t	i;
	size_t	j;

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

void	ft_memdel(void **ap)
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
void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*sym;
	size_t			i;

	sym = (unsigned char *)dest;
	i = 0;
	while (i < n)
		sym[i++] = (unsigned char)c;
	return (dest);
}
