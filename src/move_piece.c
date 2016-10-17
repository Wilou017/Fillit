/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 18:31:45 by fsimmet           #+#    #+#             */
/*   Updated: 2016/01/19 15:29:08 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	ft_move(t_tab piece)
{
	size_t	l;

	l = 0;
	while (piece[l])
	{
		if (piece[l][0] == '#')
			return (0);
		l++;
	}
	return (1);
}

static t_tab	ft_up(t_tab piece)
{
	size_t	l;

	while (ft_strchr(piece[0], '#') == NULL)
	{
		l = 0;
		while (l < 3 && ft_strchr(piece[l], '#') == NULL)
		{
			piece = ft_swapl(piece, l);
			l++;
		}
	}
	return (piece);
}

static t_tab	ft_left(t_tab piece)
{
	while (ft_move(piece))
		piece = ft_swapc(piece);
	return (piece);
}

t_tab			ft_left_up(t_tab piece)
{
	return (ft_left(ft_up(piece)));
}
