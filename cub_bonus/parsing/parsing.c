/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:43:54 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/03 21:19:00 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	error_handler(int i, t_flag flag)
{
	if (i != 6 || (flag.c == 0 || flag.ea == 0 \
		|| flag.f == 0 || flag.no == 0 \
		|| flag.so == 0 || flag.we == 0))
	{
		write (2, "error in path\n", 14);
		exit (1);
	}
}

void	ifvalid_floor(char **map)
{
	size_t	i;
	size_t	j;
	size_t	hight;

	i = 1;
	hight = height_map(map);
	while (map[i] && i < hight)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if ((i > 0 && (j >= ft_strlen (map[i - 1]) \
					|| j >= ft_strlen (map[i + 1]))))
					error_handler3(5);
				else if ((j > 0 && map[i][j - 1] == ' ') || map[i][j + 1] == ' '
					|| map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
					error_handler3(5);
			}
			j++;
		}
		i++;
	}
}

char	*pathfind(char *str)
{
	int	i;

	i = 3;
	while (str[i])
	{
		if ((str[i] == '.' && str[i + 1] == '/') || str[i] == ' ')
			return (ft_strdup(&str[i]));
		else
			break ;
		i++;
	}
	write(2, "invalid path\n", 13);
	exit(1);
	return (NULL);
}

char	*findrgb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C' || str[i] == 'F')
		{
			i += 2;
			return (ft_strdup(&str[i]));
		}
		i++;
	}
	return (NULL);
}

char	**ignor_space(char **map)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (map[i] && map[i][0] != '\0')
	{
		j = 0;
		x = ft_strlen(map[i]) - 1;
		while (map[i][j] && map[i][j] == ' ')
		{
			map[i][j] = '1';
			j++;
		}
		while (map[i][x] && map[i][x] == ' ')
		{
			map[i][x] = '1';
			x--;
		}
		i++;
	}
	return (map);
}
