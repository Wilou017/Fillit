/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:42:48 by amaitre           #+#    #+#             */
/*   Updated: 2015/12/12 15:44:52 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tablen(char **tab)
{
	size_t	len;

	len = 0;
	if (tab)
		while (*tab)
			len += ft_strlen(*tab++);
	return (len);
}
