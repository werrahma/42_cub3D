/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:31:10 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/03 10:31:13 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	minimap_checks(t_cub *data, int x, int y)
{
	if ((x / 8) < data->h_w.width && (x / 8) >= 0
		&& (y / 8) < data->h_w.height && (y / 8) >= 0)
	{
		if (data->map[y / 8][x / 8] == '1')
			return (1);
	}
	return (0);
}

void	drow_p(t_cub *data)
{
	int	i;
	int	j;

	i = 75;
	while (i < 79)
	{
		j = 50;
		while (j < 54)
		{
			my_mlx_pixel_put(&data->img_, i, j, 0x2e3787);
			j++;
		}
		i++;
	}
}

void	drow_minimap(t_cub *data)
{
	int	i;
	int	j;
	int	x_v;
	int	y_v;

	y_v = (data->player.y) / 8 - 50;
	j = 1;
	while (++j < 100)
	{
		i = 1;
		x_v = data->player.x / 8 - 75;
		while (++i < 150)
		{
			if (i == 149 || j == 99 || i == 2 || j == 2)
				my_mlx_pixel_put(&data->img_, i, j, 0x000000);
			else if (minimap_checks(data, x_v, y_v))
				my_mlx_pixel_put(&data->img_, i, j, 0x000000);
			else
				my_mlx_pixel_put(&data->img_, i, j, 0xBfbfbf);
			x_v ++;
		}
		y_v ++;
	}
	drow_p(data);
}
