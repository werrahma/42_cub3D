/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <werrahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:31:34 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/03 21:11:55 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_position(double pos, int tex_width)
{
	int	position;

	position = ((pos / SQRS) - (int)(pos / SQRS)) * tex_width;
	return (position);
}

int	check_if_hitwall(t_cub *data, float x, float y)
{
	if (data->map[(int)(x / SQRS)] &&
		data->map[(int)(x / SQRS)][(int)(y / SQRS)] == '1')
		return (1);
	return (0);
}

int	position_check(t_cub *data, float newx, float newy)
{
	if (data->map[(int)((data->player.y) / SQRS)][(int)(newx / SQRS)] != '1'
		&& data->map[(int)(newy / SQRS)][(int)((data->player.x) / SQRS)] != '1'
		&& data->map[(int)(newy / SQRS)][(int)(newx / SQRS)] != '1')
		return (1);
	return (0);
}
