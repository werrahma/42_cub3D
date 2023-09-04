/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:15:21 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/03 21:20:45 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	hieghtlen(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	iscolorvalid(char	**color)
{
	int	i;
	int	j;

	i = 0;
	if (hieghtlen(color) > 3)
	{
		write (2, "eroor in colors\n", 16);
		exit (1);
	}
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]))
			{
				write (2, "not digit\n", 10);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	rang_color(int r, int g, int b)
{
	if (!(r >= 0 && r <= 255) || !(g >= 0 && g <= 255) || !(b >= 0 && b <= 255))
	{
		write (2, "invalid color\n", 13);
		exit (1);
	}
}

void	count_comma(char *path)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (path[i])
	{
		if (path[i] == ',')
			flag++;
		i++;
	}
	if (flag >= 3)
	{
		write(2, "multiple comma\n", 15);
		exit(1);
	}
}

void	rgbtoint(t_path *path)
{
	char	**ceiling;
	char	**floor;

	count_comma(path->c_path);
	count_comma(path->f_path);
	ceiling = ft_split(path->c_path, ',');
	floor = ft_split(path->f_path, ',');
	iscolorvalid(ceiling);
	iscolorvalid(floor);
	if (!ceiling[0] || !ceiling[1] || !ceiling[2] \
		|| !floor[0] || !floor[1] || !floor[2])
		error_handler3(6);
	else if (ft_strlen(ceiling[0]) > 3 || ft_strlen(ceiling[1]) > 3 \
		|| ft_strlen(ceiling[2]) > 3 || ft_strlen(floor[0]) > 3 \
		|| ft_strlen(floor[1]) > 3 || ft_strlen(floor[2]) > 3)
		error_handler3(6);
	rang_color(ft_atoi(ceiling[0]), ft_atoi(ceiling[1]), ft_atoi(ceiling[2]));
	rang_color(ft_atoi(floor[0]), ft_atoi(floor[1]), ft_atoi(floor[2]));
	path->c = shifting(ceiling[0], ceiling[1], ceiling[2]);
	path->f = shifting(floor[0], floor[1], floor[2]);
	free_split(ceiling);
	free_split(floor);
}
