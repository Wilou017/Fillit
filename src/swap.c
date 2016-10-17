/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:39:25 by fsimmet           #+#    #+#             */
/*   Updated: 2016/01/19 15:22:36 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tab	ft_swapl(t_tab grille, size_t l)
{
	char *tmp;

	tmp = ft_strnew(4);
	ft_strcpy(tmp, grille[l]);
	ft_strcpy(grille[l], grille[l + 1]);
	ft_strcpy(grille[l + 1], tmp);
	free(tmp);
	return (grille);
}

t_tab	ft_swapc(t_tab piece)
{
	t_tab	piece2;
	size_t	l;
	size_t	c;

	piece2 = ft_tabmalloc(4, '.');
	if (!piece2)
		return (NULL);
	l = 0;
	while (piece[l])
	{
		c = 1;
		while (piece[l][c])
		{
			piece2[l][c - 1] = piece[l][c];
			c++;
		}
		l++;
	}
	while (l > 0)
		piece2[--l][3] = '.';
	l = 0;
	while (l <= 4)
		free(piece[l++]);
	return (piece2);
}
