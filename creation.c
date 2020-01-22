/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 23:43:32 by cburns            #+#    #+#             */
/*   Updated: 2020/01/20 00:47:13 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char     *ft_create_figure(char *file)
{
    char    pos[21];
    int     i;
    
    i = 0;
    while (file[i] != '\0' && i < 20)
    {
        if (file[i] != '#' || file[i] != '.' || file[i] != '\n')
            return (NULL);  
        pos[i] = file[i];
        i++;
    }
    if (i != 20 || !(file[i] == '\0' || file[i] == '\n'))
        return (NULL);
    pos[i] = '\0';
    return (pos);
}

int   *ft_fulfil_struct(t_list **list)
{
    t_list  *node;
    char    value;

    value = 'A';
    node = *list;
    while (node != NULL)
    {
        ((t_etris *)node->content)->value = value;
        value++;
        if (ft_check_figure(&(((t_etris *)node->content)->pos)) == 0)
        {
            ft_free_list(list);
            return (0);
        }
        ((t_etris *)node->content)->width = ft_width(((t_etris *)node->content)->pos);
        ((t_etris *)node->content)->height = ft_height(((t_etris *)node->content)->pos);
        node = node->next;
    }   
    return (1);
}

int   *ft_create_list(t_list **list, char *file, int ret)
{
    t_list  *node;
    t_list  *tail;
    t_etris *tetr;
    char    pos[21];
    int     i;
    
    i = 0;
    node = *list;
    while (i <= ret)
    {
        if ((*pos = ft_create_figure(file + i)) == NULL ||
            (tetr = (t_etris *)malloc(sizeof(t_etris))) == NULL)
        {
            ft_free_list(list);
            return (0);
        }
        *(tetr->pos) = *pos;
        if ((node = ft_lstnew(tetr, sizeof(t_etris))) == NULL)
        {
            ft_free_list(list);
            return (0);
        }
        if (node == *list)
            *list = node;
        node->next = tail;
        node = tail;
        i += 21;
    }
    return (ft_fulfil_struct(list));
}

int   *ft_create_buffer(t_list **list, int fd)
{
    char    file[550];
    int     ret;

    ret = read(fd, file, 551);
    file[ret] = '\0';
    if (!(close(fd)))
        return (0);
    if (ret < 20 || ret > 545)
        return (0);
    return (ft_create_list(list, file, ret));
}

t_point     *ft_point_new(int x, int y) 
{ 
    t_point *point; 

    point = (t_point *)malloc(sizeof(t_point)); 
    point->x = x; 
    point->y = y; 
    return (point); 
}
