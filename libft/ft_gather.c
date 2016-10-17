/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gather.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:25:50 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/12 17:09:20 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gather(char **tab, int ch)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	l;
	size_t	c;

	l = 0;
	c = 0;
	i = 0;
	len = ft_tablen(tab);
	str = ft_strnew(len);
	while (tab[l])
	{
		while (tab[l][c])
			str[i++] = tab[l][c++];
		if (ch != 0)
			str[i++] = ch;
		c = 0;
		l++;
	}
	return (str);
}
