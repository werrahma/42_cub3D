/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:17:13 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/03 21:20:45 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_struct(t_flag *flag)
{
	flag->c = 0;
	flag->ea = 0;
	flag->f = 0;
	flag->no = 0;
	flag->so = 0;
	flag->we = 0;
}

void	if_duplicate(t_pars *list, t_path **path, t_flag *flag)
{
	if (!ft_strncmp(list->string, "NO ", 3))
	{
		if (flag->no == 0)
			(*path)->no_path = pathfind(list->string);
		else
		{
			write(2, "duplicate\n", 10);
			exit(1);
		}
		flag->no++;
	}
	else if (!ft_strncmp(list->string, "WE ", 3))
	{
		if (flag->we == 0)
			(*path)->we_path = pathfind(list->string);
		else
		{
			write(2, "duplicate\n", 10);
			exit(1);
		}
		flag->we++;
	}
}

void	if_duplicate2(t_pars *list, t_path **path, t_flag *flag)
{
	if (!ft_strncmp(list->string, "EA ", 3))
	{
		if (flag->ea == 0)
			(*path)->ea_path = pathfind(list->string);
		else
		{
			write(2, "duplicate\n", 10);
			exit(1);
		}
		flag->ea++;
	}
	else if (!ft_strncmp(list->string, "SO ", 3))
	{
		if (flag->so == 0)
			(*path)->so_path = pathfind(list->string);
		else
		{
			write(2, "duplicate\n", 10);
			exit(1);
		}
		flag->so++;
	}
}

void	if_duplicate3(t_pars *list, t_path **path, t_flag *flag)
{
	if (!ft_strncmp(list->string, "F ", 2))
	{
		if (flag->f == 0)
			(*path)->f_path = findrgb(list->string);
		else
		{
			write(2, "duplicate\n", 10);
			exit(1);
		}
		flag->f++;
	}
	else if (!ft_strncmp(list->string, "C ", 2))
	{
		if (flag->c == 0)
			(*path)->c_path = findrgb(list->string);
		else
		{
			write(2, "duplicate\n", 10);
			exit(1);
		}
		flag->c++;
	}
}

void	path_checker(t_pars *list, t_path **path)
{
	t_flag	flag;
	int		i;

	i = 0;
	init_struct(&flag);
	*path = malloc(sizeof(t_path));
	while (list && list->string && list->string[0] != '1' \
		&& list->string[0] != '0' && list->string[0] != ' ')
	{
		if (list->string && list->string[0] != '\0')
			i++;
		if_duplicate(list, path, &flag);
		if_duplicate2(list, path, &flag);
		if_duplicate3(list, path, &flag);
		list = list->next;
	}
	error_handler(i, flag);
}
