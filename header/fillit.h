/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:41:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/22 10:13:03 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFFSIZE 21

# include <fcntl.h>
# include "../libft/libft.h"

typedef struct		s_info
{
	struct s_list	**liste;
	size_t			nbmaillon;
	size_t			cote;
	t_tab			map;
}					t_info;

typedef struct		s_tmp_param
{
	size_t			width;
	size_t			height;
	size_t			line;
	size_t			col;
}					t_tmp_param;

t_tab				ft_swapl(t_tab grille, size_t l);
t_tab				ft_swapc(t_tab piece);
int					ft_check(t_info *info);
t_tab				ft_left_up(t_tab piece);
t_tab				ft_creatmap(t_info **info);
void				ft_show_tab(char **tab);
int					ft_error(int i);
void				ft_transformtoalpha(t_info *info, char c, size_t i);
void				ft_tabtostr(t_info *info, size_t i);
void				ft_makecircle(t_info **info);
int					ft_creatlist(char *file, t_info **info);
char				*ft_sharptolettre(char *str, char c);
void				ft_map_plusplus(t_info **info);
int					ft_letter(t_tab piece);
void				ft_delete_letter(t_info **info, int letter,
					t_tmp_param tmp);
void				*ft_select(t_list **liste, size_t nb);
int					ft_resolve(t_info **info, size_t nb);
size_t				ft_width(t_tab piece);
size_t				ft_height(t_tab piece);

#endif
