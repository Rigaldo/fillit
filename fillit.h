/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cburns <cburns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:54:19 by cburns            #+#    #+#             */
/*   Updated: 2020/01/30 09:16:36 by cburns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct      s_etris
{
    char            value;
    int             width;
    int             height;
    char            pos[21];
    char            **figure;
}                   t_etris;

typedef struct      s_point 
{ 
    int             x; 
    int             y; 
}                   t_point; 

typedef struct      s_map 
{ 
    int             size; 
    char            **array; 
}                   t_map; 

int         ft_put_error(const char *str);

int         ft_create_buffer(t_list **list, int fd);
int         ft_create_list(t_list **list, char *file, int ret);
int         ft_create_figure(char *file, char pos[21]);
int         ft_fulfil_struct(t_list **list);
t_point     *point_new(int x, int y);
int     ft_create_elem(t_list *node);
t_point     *ft_point_new(int x, int y);
void	ft_minmax(char *str, t_point *min, t_point *max);

int         ft_check_adjacency(const char *str);
int         ft_check_figure(const char *str);
int         ft_width(const char *str);
int         ft_height(const char *str);

int         ft_solve_map(t_map *map, t_list *list);
int         ft_high_sqrt(int n);
t_map       ft_artyom_pidor(t_list *list);
void        ft_set_piece(t_etris *tetri, t_map *map, t_point *point, char c);
int         ft_place(t_etris *tetri, t_map *map, int x, int y);

void        ft_free_list(t_list **list);
void        ft_print(t_map *map);

void	    ft_putchar_fd(char c, int fd);
void	    ft_putstr_fd(char const *s, int fd);
void	    *ft_memalloc(size_t size);
t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstaddend(t_list **alst, t_list *new);
char	    *ft_strncpy(char *dest, char const *s, size_t n);
void	    ft_memdel(void **ap);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *dest, int c, size_t n);
#endif
