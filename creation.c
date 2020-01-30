/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 09:15:33 by cburns            #+#    #+#             */
/*   Updated: 2020/01/30 09:15:37 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int         ft_create_buffer(t_list **list, int fd)
{
    char    file[550];
    int     ret;

    ret = read(fd, file, 549);
    file[ret] = '\0';
    if (close(fd) != 0)
        return (0);
    if (ret < 20 || ret > 545)
        return (0);
    return (ft_create_list(list, file, ret));
}

int         ft_create_list(t_list **list, char *file, int ret)
{
    t_list  *node;
    t_etris *tetr;
    char    pos[21];
    int     i;
    int     j;

    i = 0;
    while (i <= ret)
    {
        if ((ft_create_figure(file + i, pos)) == 0 ||
            (tetr = (t_etris *)malloc(sizeof(t_etris))) == NULL ||
            (node = ft_lstnew(tetr, sizeof(t_etris))) == NULL)
        {
            //ft_free_list(list);
            //printf("jopa\n");
            return (0);
        }
        j = 0;
        while (j < 21)
        {
            tetr->pos[j] = pos[j];
            j++;
        }
        node->content = (void *)tetr;
        ft_lstaddend(list, node);
        i += 21;
    }
    return (ft_fulfil_struct(list));
}

int         ft_fulfil_struct(t_list **list) //заполняем структуру т_етриса для каждого элемента списка
{
    t_list  *node;
    char    value;

    value = 'A';
    node = *list;

    while (node != NULL)
    {
        ((t_etris *)node->content)->value = value++;
        ((t_etris *)node->content)->width = ft_width(((t_etris *)node->content)->pos);
        ((t_etris *)node->content)->height = ft_height(((t_etris *)node->content)->pos);
        if ((ft_check_figure(((t_etris *)node->content)->pos) == 0) || ft_create_elem(node) == 0) //а тут как раз заполняем т_етрис->фигура из строки пос
        {
            //ft_free_list(list);
            return (0);
        }
        node = node->next;
    }
    return (1);
}

int     ft_create_elem(t_list *node) //та самая функция, которую я переработал и вставил проверки на маллок везде
{
    char    **figure;
    int     i;
    t_point *min;
    t_point *max;

    if ((min = ft_point_new(3, 3)) == NULL || (max = ft_point_new(0, 0)) == NULL)
        return (0);
    ft_minmax(((t_etris *)node->content)->pos, min, max);
    i = 0;
    if ((figure = (char **)malloc(sizeof(char *) * (((t_etris *)node->content)->height + 1))) == NULL)
        return (0);
    while (i < ((t_etris *)node->content)->height)
    {
        if ((figure[i] = (char *)malloc(sizeof(char) * (((t_etris *)node->content)->width + 1))) == NULL)
            return (0);
        ft_strncpy(figure[i], ((t_etris *)node->content)->pos + (min->x) + (i + min->y) * 5,
            (size_t)(max->x - min->x + 1));
        i++;
    }
    figure[i] = NULL; // не уверен, что это нужно. Если последнюю строчку не требуется нуль-терминировать,
                      // то надо в 95 строке убрать + 1, там где height
    ft_memdel((void **)&min);
    ft_memdel((void **)&max);   
    return (1);
}

int     ft_create_figure(char *file, char pos[21])
{
    int     i;
    
    i = 0;
    while (file[i] != '\0' && i < 20)
    {
        if (file[i] != '#' && file[i] != '.' && file[i] != '\n')
            return (0);  
        pos[i] = file[i];
        i++;
    }
    if (i != 20 || !(file[i] == '\0' || file[i] == '\n'))
        return (0);
    pos[i] = '\0';
    return (1);
}

t_point     *ft_point_new(int x, int y)
{ 
    t_point *point; 

    if ((point = (t_point *)malloc(sizeof(t_point))) == NULL)
        return (NULL);
    point->x = x; 
    point->y = y; 
    return (point); 
}

void	ft_minmax(char *str, t_point *min, t_point *max)
{
    int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}
