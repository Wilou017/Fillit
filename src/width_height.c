/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_height.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 09:34:57 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/22 09:36:40 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t		ft_width(t_tab piece)
{
	size_t i;
	size_t j;
	size_t max;
	size_t letter;

	i = 1;
	j = 0;
	max = 1;
	letter = 0;
	while (j < 4)
	{
		while (i < 4 && !(piece[j][i - 1] != '.' && piece[j][i] == '.'))
		{
			if (piece[j][i] != '.')
				letter = 1;
			i++;
		}
		if (i > max && letter == 1)
			max = i;
		i = 1;
		letter = 0;
		j++;
	}
	return (max);
}

size_t		ft_height(t_tab piece)
{
	size_t i;
	size_t j;
	size_t max;
	size_t letter;

	i = 1;
	j = 0;
	max = 1;
	letter = 0;
	while (j < 4)
	{
		while (i < 4 && !(piece[i - 1][j] != '.' && piece[i][j] == '.'))
		{
			if (piece[i][j] != '.')
				letter = 1;
			i++;
		}
		if (i > max && letter == 1)
			max = i;
		i = 1;
		letter = 0;
		j++;
	}
	return (max);
}
