/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:31:20 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/03 10:31:22 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	player_angle(t_cub *data, int x, int y)
{
	if (data->map[x][y] == 'N')
		data->player.rotation = rad(270);
	else if (data->map[x][y] == 'S')
		data->player.rotation = rad(90);
	else if (data->map[x][y] == 'W')
		data->player.rotation = rad(180);
	else if (data->map[x][y] == 'E')
		data->player.rotation = 0;
}

void	player_position(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
			{
				data->player.x = (j * SQRS) + SQRS / 2;
				data->player.y = (i * SQRS) + SQRS / 2;
				player_angle(data, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
	data->mouse.x = 0;
	data->mouse.y = 0;
}
