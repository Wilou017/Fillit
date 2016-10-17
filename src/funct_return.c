/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:12:46 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/21 14:03:55 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_show_tab(char **tab)
{
	unsigned int ligne;
	unsigned int colone;

	ligne = 0;
	colone = 0;
	while (tab[ligne] != NULL)
	{
		while (tab[ligne][colone] != '\0')
		{
			ft_putchar(tab[ligne][colone]);
			colone++;
		}
		ft_putchar('\n');
		colone = 0;
		ligne++;
	}
}

int		ft_error(int i)
{
	if (i != 0)
	{
		close(i);
		return (0);
	}
	else
	{
		ft_putstr("error\n");
		return (1);
	}
}
