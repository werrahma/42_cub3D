/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:03:08 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/01 18:27:17 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	shifting(char *r, char *g, char *b)
{
	int	color;

	color = ft_atoi(r) * 65536 + ft_atoi(g) * 256 + ft_atoi(b);
	return (color);
}

int	height_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	return (i);
}

void	error_handler3(int flag)
{
	if (!flag)
		write(2, "need to setting map\n", 20);
	else if (flag == 1)
		write(2, "character not valid\n", 20);
	else if (flag == 2)
		write (2, "there is space nearby player\n", 29);
	else if (flag == 3)
		write(2, "more than player in map\n", 24);
	else if (flag == 4)
		write(2, "player not set\n", 15);
	else if (flag == 5)
		write(2, "floor not valid\n", 16);
	else if (flag == 6)
		write (2, "invalid color\n", 14);
	else if (flag == 7)
		write(2, "ivalid map\n", 11);
	exit(1);
}

void	if_validplayer(char **map, int i, int j, int *check)
{
	if (map[i] && map[i][j] != ' ' && map[i][j] != '1'
		&& map[i][j] != '0' && map[i][j] != 'N'
		&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
		error_handler3(1);
	if (map[i] && (map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W'))
	{
		if (j > 0 && i > 0 && (map[i + 1][j] == ' ' || map[i - 1][j] == ' '
			|| map[i][j - 1] == ' ' || map[i][j + 1] == ' '))
			error_handler3(2);
		(*check)++;
	}
}

void	check_characters(char **map)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	if (!map[0])
		error_handler3(0);
	while (map[i] && i < height_map(map))
	{
		j = 0;
		while (map[i][j])
		{
			if_validplayer(map, i, j, &check);
			j++;
		}
		i++;
	}
	if (check > 1)
		error_handler3(3);
	else if (!check)
		error_handler3(4);
}
