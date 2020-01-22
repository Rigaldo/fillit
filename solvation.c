/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 00:22:58 by cburns            #+#    #+#             */
/*   Updated: 2020/01/20 00:47:12 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include "fillit.h" 

int         ft_solve_map(t_map *map, t_list *list) 
{ 
    int     x; 
    int     y; 
    t_etris *tetri; 

    if (list == NULL) 
        return (1); 
    y = 0; 
    tetri = (t_etris *)(list->content); 
    while (y < map->size - tetri->height + 1) 
    { 
        x = 0; 
        while (x < map->size - tetri->width + 1) 
        { 
            if (place(tetri, map, x, y)) 
            { 
                if (solve_map(map, list->next)) 
                    return (1); 
                else 
                    set_piece(tetri, map, point_new(x, y), '.'); 
            } 
            x++; 
        } 
        y++; 
    } 
    return (0); 
} 

int     ft_high_sqrt(int n) 
{ 
    int size; 

    size = 2; 
    while (size * size < n)     
        size++; 
    return (size); 
} 

t_map       ft_artyom_pidor(t_list *list) 
{ 
    t_map   *map; 
    int     size; 

    size = high_sqrt(ft_lstcount(list) * 4); 
    map = map_new(size); 
    while (!solve_map(map, list)) 
    { 
        size++; 
        free_map(map); 
        map = map_new(size); 
    } 
    return (map); 
} 

void        ft_set_piece(t_etris *tetri, t_map *map, t_point *point, char c) 
{ 
    int     i; 
    int     j; 

    i = 0; 
    while (i < tetri->width) 
    { 
        j = 0; 
        while (j < tetri->height) 
        { 
            if (tetri->pos[j][i] == '#') 
                map->array[point->y + j][point->x + i] = c; 
            j++; 
        } 
        i++; 
    } 
    ft_memdel((void **)&point); 
}

int         ft_place(t_etris *tetri, t_map *map, int x, int y) 
{ 
    int     i; 
    int     j; 

    i = 0; 
    while (i < tetri->width) 
    { 
        j = 0; 
        while (j < tetri->height) 
        { 
            if (tetri->pos[j][i] == '#' && map->array[y + j][x + i] != '.') 
                return (0); 
            j++; 
        } 
        i++; 
    } 
    set_piece(tetri, map, point_new(x, y), tetri->value); 
    return (1); 
}
