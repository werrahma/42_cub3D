/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:07:12 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/01 17:10:08 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ignor_paths(t_pars **list)
{
	while ((*list))
	{
		if (ft_strncmp((*list)->string, "NO ", 3)
			&& ft_strncmp((*list)->string, "WE ", 3)
			&& ft_strncmp((*list)->string, "EA ", 3)
			&& ft_strncmp((*list)->string, "SO ", 3) 
			&& ft_strncmp((*list)->string, "F ", 2)
			&& ft_strncmp((*list)->string, "C ", 2)
			&& (*list)->string && (*list)->string[0] != '\0')
			break ;
		(*list) = (*list)->next;
	}
}

char	**get_map(t_pars *list)
{
	int		i;	
	char	**map;
	t_pars	*tmp;

	i = 0;
	ignor_paths(&list);
	tmp = list;
	while (list)
	{
		i++;
		list = list->next;
	}
	map = malloc((sizeof(char *) * (i + 1)));
	if (!i)
		error_handler3(7);
	map[i] = NULL;
	i = 0;
	while (tmp)
	{
		map[i] = ft_strdup(tmp->string);
		i++;
		tmp = tmp->next;
	}
	return (map);
}
