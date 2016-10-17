/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_letter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:17:02 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/22 09:01:57 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_letter(t_tab piece)
{
	size_t i;

	i = 0;
	while (piece[0][i] == '.')
		i++;
	return (piece[0][i]);
}

void		ft_delete_letter(t_info **info, int letter, t_tmp_param tmp)
{
	size_t line;
	size_t col;
	size_t c_tmp;

	line = tmp.line;
	c_tmp = tmp.col;
	while ((*info)->map[line])
	{
		col = c_tmp;
		while ((*info)->map[line][col])
		{
			if ((*info)->map[line][col] == letter)
				(*info)->map[line][col] = '.';
			col++;
		}
		line++;
	}
}

void		*ft_select(t_list **liste, size_t nb)
{
	t_list *maillon;

	maillon = *liste;
	while (nb-- > 1)
		maillon = maillon->next;
	return (maillon->content);
}
