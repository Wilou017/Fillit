/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:23:48 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/22 10:12:32 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_put_check(t_tab map, t_tab piece, t_tmp_param tmp)
{
	size_t l_piece;
	size_t c_piece;
	size_t c_tmp;

	l_piece = 0;
	c_piece = 0;
	c_tmp = tmp.col;
	while (l_piece < tmp.height)
	{
		while (c_piece < tmp.width)
		{
			if (map[tmp.line][tmp.col] != '.' && piece[l_piece][c_piece] != '.')
				return (0);
			c_piece++;
			tmp.col++;
		}
		tmp.col = c_tmp;
		tmp.line++;
		c_piece = 0;
		l_piece++;
	}
	return (1);
}

static void			ft_put_piece(t_info **info, t_tab piece, t_tmp_param tmp)
{
	size_t l_piece;
	size_t c_piece;
	size_t c_tmp;

	l_piece = 0;
	c_tmp = tmp.col;
	while (l_piece < tmp.height)
	{
		c_piece = 0;
		while (c_piece < tmp.width)
		{
			if (piece[l_piece][c_piece] != '.')
				(*info)->map[tmp.line][tmp.col] = piece[l_piece][c_piece];
			c_piece++;
			tmp.col++;
		}
		tmp.line++;
		tmp.col = c_tmp;
		l_piece++;
	}
}

int					ft_res_bis(t_info **info, t_tab piece,
					t_tmp_param tmp, size_t nb)
{
	if (ft_put_check((*info)->map, piece, tmp))
	{
		ft_put_piece(info, piece, tmp);
		if (!ft_resolve(info, nb + 1))
			ft_delete_letter(info, ft_letter(piece), tmp);
		else
			return (1);
	}
	return (0);
}

int					ft_resolve(t_info **info, size_t nb)
{
	t_tmp_param	tmp;
	t_tab		piece;

	if (nb > (*info)->nbmaillon)
		return (1);
	piece = ft_strsplit(ft_select((*info)->liste, nb), '\n');
	tmp.height = ft_height(piece);
	tmp.width = ft_width(piece);
	tmp.line = 0;
	while ((*info)->map[tmp.line] &&
		(tmp.line + tmp.height) <= (*info)->cote)
	{
		tmp.col = 0;
		while ((*info)->map[tmp.line][tmp.col] &&
		(tmp.col + tmp.width) <= (*info)->cote)
		{
			if (ft_res_bis(info, piece, tmp, nb))
				return (1);
			tmp.col++;
		}
		tmp.line++;
	}
	return (0);
}
