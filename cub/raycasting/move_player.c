/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:31:17 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/03 10:31:19 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	move_up(t_cub *data)
{
	data->player.xtmp += cos(data->player.rotation) * SPEED;
	data->player.ytmp += sin(data->player.rotation) * SPEED;
}

void	move_down(t_cub *data)
{
	data->player.xtmp += cos(data->player.rotation) * -SPEED;
	data->player.ytmp += sin(data->player.rotation) * -SPEED;
}

void	move_right(t_cub *data)
{
	data->player.xtmp += cos(data->player.rotation + rad(90)) * SPEED;
	data->player.ytmp += sin(data->player.rotation + rad(90)) * SPEED;
}

void	move_left(t_cub *data)
{
	data->player.xtmp += cos(data->player.rotation + rad(90)) * -SPEED;
	data->player.ytmp += sin(data->player.rotation + rad(90)) * -SPEED;
}
