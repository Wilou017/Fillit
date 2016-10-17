/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:41:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/22 09:32:50 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_char(char **piece)
{
	unsigned int ligne;
	unsigned int colone;

	ligne = 0;
	colone = 0;
	while (piece[ligne] != NULL)
	{
		while (piece[ligne][colone] != '\0')
		{
			if (piece[ligne][colone] != '#' && piece[ligne][colone] != '.')
				return (0);
			colone++;
		}
		colone = 0;
		ligne++;
	}
	return (1);
}

static size_t	ft_check_nbr(char **piece)
{
	size_t	l;
	size_t	c;
	size_t	k;

	l = 0;
	k = 0;
	while (piece[l])
	{
		c = 0;
		while (piece[l][c] != '\0')
		{
			if (piece[l][c] == '#')
				k++;
			c++;
		}
		l++;
	}
	if (k != 4)
		return (0);
	return (1);
}

static size_t	ft_check_dieze(char **piece)
{
	size_t	l;
	size_t	c;
	size_t	k;

	k = 0;
	l = 0;
	while (piece[l])
	{
		c = 0;
		while (piece[l][c] != '\0')
		{
			if (l < 3 && piece[l][c] == '#' && piece[l + 1][c] == '#')
				k++;
			if (c < 3 && piece[l][c] == '#' && piece[l][c + 1] == '#')
				k++;
			c++;
		}
		l++;
	}
	if (k < 3)
		return (0);
	return (1);
}

static int		ft_check_size(char **piece)
{
	unsigned int ligne;

	ligne = 0;
	while (piece[ligne] != NULL)
	{
		if (ft_strlen(piece[ligne]) != 4 || ligne > 3)
			return (0);
		ligne++;
	}
	if (ligne != 4)
		return (0);
	return (1);
}

int				ft_check(t_info *info)
{
	t_list	*maillon;
	t_tab	piece;
	char	*str;
	size_t	i;

	i = 1;
	maillon = *(info->liste);
	while (i <= info->nbmaillon)
	{
		str = (char*)maillon->content;
		piece = ft_strsplit(maillon->content, '\n');
		if (!ft_check_size(piece) || !ft_check_char(piece) ||
			!ft_check_dieze(piece) || !ft_check_nbr(piece) ||
			(i == info->nbmaillon &&
				(str[19] != '\n' || ft_strlen(str) == 21)) ||
			str[0] == '\n')
		{
			free(piece);
			return (0);
		}
		maillon = maillon->next;
		i++;
		free(piece);
	}
	return (1);
}
