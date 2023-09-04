/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:31:14 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/03 17:43:15 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	mlx_render_img(t_cub *d)
{
	d->img_.img = mlx_new_image(d->mlx_, WIDTH, HEIGHT);
	d->img_.addr = mlx_get_data_addr(d->img_.img,
			&d->img_.bits_per_pixel, &d->img_.line_length,
			&d->img_.endian);
	rander_map(d);
	mlx_put_image_to_window(d->mlx_, d->win_, d->img_.img, 0, 0);
}

void	clear_window(t_cub *data)
{
	mlx_destroy_image(data->mlx_, data->img_.img);
	mlx_clear_window(data->mlx_, data->win_);
	mlx_destroy_window(data->mlx_, data->win_);
	exit(0);
}

int	keey_hook(int key, t_cub *data)
{
	data->player.xtmp = data->player.x;
	data->player.ytmp = data->player.y;
	if (key == 65307)
		clear_window(data);
	if (key == 119)
		move_up(data);
	if (key == 115)
		move_down(data);
	if (key == 97)
		move_left(data);
	if (key == 100)
		move_right(data);
	if (key == 65361)
		leftrotation(data);
	if (key == 65363)
		rightrotation(data);
	if (position_check(data, data->player.xtmp, data->player.ytmp))
	{
		data->player.x = data->player.xtmp;
		data->player.y = data->player.ytmp;
		mlx_destroy_image(data->mlx_, data->img_.img);
		mlx_render_img(data);
	}
	return (0);
}

int	mouse_hook(int x, int y, t_cub *data)
{
	if (x >= WIDTH || x <= 0 || y >= HEIGHT || y <= 0)
		mlx_mouse_move(data->mlx_, data->win_, WIDTH / 2, HEIGHT / 2);
	if (x > data->mouse.x)
	{
		data->player.rotation += rad(1);
		if (data->player.rotation > 6.283185)
			data->player.rotation = 0;
	}
	else
	{
		data->player.rotation -= rad(1);
		if (data->player.rotation < 0)
			data->player.rotation = 6.283185;
	}
	data->mouse.x = x;
	data->mouse.y = y;
	mlx_render_img(data);
	return (0);
}

int	event_hook(t_cub *data)
{
	mlx_destroy_image(data->mlx_, data->img_.img);
	mlx_clear_window(data->mlx_, data->win_);
	mlx_destroy_window(data->mlx_, data->win_);
	exit(0);
}
