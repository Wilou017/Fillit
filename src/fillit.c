/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:41:43 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/22 09:30:42 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_freeall(t_info **info)
{
	size_t i;
	t_list *tmp;
	t_list *tmp2;

	tmp = *((*info)->liste);
	if (tmp)
	{
		i = 0;
		while ((*info)->nbmaillon > i)
		{
			free(tmp->content);
			tmp2 = tmp->next;
			free(tmp);
			tmp = tmp2;
			i++;
		}
		i = 0;
		while (i <= (*info)->cote)
		{
			free((*info)->map[i]);
			i++;
		}
		free((*info)->map);
		free(*info);
	}
}

int			ft_start(t_info *info)
{
	ft_tabtostr(info, 1);
	ft_transformtoalpha(info, 'A', 1);
	info->cote = 0;
	if ((info->map = ft_creatmap(&info)) == NULL)
		return (ft_error(0));
	while (ft_resolve(&info, 1) == 0)
		ft_map_plusplus(&info);
	ft_show_tab(info->map);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_info			*info;

	if (argc == 2)
	{
		info = (t_info *)malloc(sizeof(t_info));
		if (!ft_creatlist(argv[1], &info))
			return (ft_error(0));
		if (info->liste == NULL)
			return (ft_error(0));
		if (ft_check(info))
		{
			if (!ft_start(info))
				return (0);
		}
		else
			return (ft_error(0));
	}
	else
		return (ft_error(0));
	ft_freeall(&info);
	return (0);
}
