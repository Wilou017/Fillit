/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:18:54 by amaitre           #+#    #+#             */
/*   Updated: 2016/01/21 14:32:48 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_transformtoalpha(t_info *info, char c, size_t i)
{
	t_list	*maillon;
	size_t	count;

	count = 1;
	maillon = *(info->liste);
	if (i <= info->nbmaillon)
	{
		while (count < i)
		{
			maillon = maillon->next;
			count++;
		}
		maillon->content = ft_sharptolettre(maillon->content, c);
		ft_transformtoalpha(info, ++c, ++i);
	}
}

void	ft_tabtostr(t_info *info, size_t i)
{
	t_list	*maillon;
	size_t	count;
	char	*content_old;
	char	**tab_content;

	count = 1;
	maillon = *(info->liste);
	if (i <= info->nbmaillon)
	{
		while (count < i)
		{
			maillon = maillon->next;
			count++;
		}
		content_old = maillon->content;
		tab_content = ft_strsplit(content_old, '\n');
		maillon->content = ft_gather(ft_left_up(tab_content), '\n');
		free(tab_content);
		free(content_old);
		ft_tabtostr(info, ++i);
	}
}

void	ft_makecircle(t_info **info)
{
	t_list	*liste;
	t_list	*tmp;
	size_t	i;

	liste = *((*info)->liste);
	if (liste)
	{
		i = 1;
		tmp = liste;
		while (i < (*info)->nbmaillon)
		{
			tmp = tmp->next;
			i++;
		}
		tmp->next = liste;
	}
}

int		ft_creatlist(char *file, t_info **info)
{
	int				fd;
	char			buf[BUFFSIZE];

	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		(*info)->nbmaillon = (int)malloc(sizeof(int));
		(*info)->nbmaillon = 0;
		(*info)->liste = (t_list **)malloc(sizeof(t_list));
		*((*info)->liste) = NULL;
		while (read(fd, &buf, BUFFSIZE) != 0)
		{
			(*info)->nbmaillon++;
			if ((*info)->nbmaillon > 26)
				return (ft_error(fd));
			ft_lstadd_push_back((*info)->liste, ft_lstnew(buf, BUFFSIZE + 1));
			ft_strclr(buf);
		}
		close(fd);
	}
	else
		return (ft_error(fd));
	ft_makecircle(info);
	return (1);
}

char	*ft_sharptolettre(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = c;
		i++;
	}
	return (str);
}
