/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:42:49 by fsimmet           #+#    #+#             */
/*   Updated: 2015/12/12 14:15:11 by fsimmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_push_back(t_list **alst, t_list *nw)
{
	t_list	*tmp;

	tmp = *alst;
	if (*alst && nw)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = nw;
	}
	else
		*alst = nw;
}
