/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_mapclosed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:21:34 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/03 21:08:24 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	error_handler_(int flag)
{
	if (!flag)
		write(2, "error map not closed\n", 21);
	else
		write(2, "ivalid map\n", 11);
	exit (1);
}

void	firstandlast_line(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i] && map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '\0')
			error_handler_(0);
		j++;
	}
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			error_handler_(0);
		j++;
	}
}

void	is_mapclosed(char **map)
{
	int	i;

	i = 0;
	if (!map[i])
		error_handler_(1);
	map = ignor_space(map);
	while (map[i])
		i++;
	i--;
	firstandlast_line(map, i);
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1'
			|| map[i][ft_strlen(map[i]) - 1] != '1')
			error_handler_(0);
		i++;
	}
}
