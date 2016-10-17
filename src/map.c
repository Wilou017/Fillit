/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:24:29 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/21 16:04:20 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_map_plusplus(t_info **info)
{
	t_tab	tmpmap;
	size_t	l;

	l = 0;
	(*info)->cote++;
	tmpmap = (*info)->map;
	(*info)->map = ft_creatmap(info);
	while (l < (*info)->cote)
		free(tmpmap[l++]);
}

t_tab		ft_creatmap(t_info **info)
{
	if ((*info)->cote == 0)
		(*info)->cote = ft_sqrt((*info)->nbmaillon * 4);
	if ((*info)->cote < 2)
		return (NULL);
	return (ft_tabmalloc((*info)->cote, '.'));
}
