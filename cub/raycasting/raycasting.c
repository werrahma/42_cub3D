/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:14:35 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/04 13:10:58 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	rander_sky(t_cub *data, t_help *cub, int x)
{
	int	i;
	int	color;

	i = 0;
	while (i < cub->y)
	{
		color = data->path->c;
		my_mlx_pixel_put(&data->img_, x, i, color);
		i++;
	}
}

void	horizontal_rayrander(t_cub *data, double *hitwall, double pdist, int x)
{
	t_help	cub;
	int		i;

	cub.hordist = count_distance(data, hitwall[0], hitwall[1]);
	cub.hight = 0.0;
	i = 0;
	cub.hordist *= cos(data->player.rotation - data->rayangle);
	hor_init(data, &cub, cub.hordist, pdist);
	rander_sky(data, &cub, x);
	i = cub.y_top;
	if (i < 0)
	{
		cub.hight += cub.size * abs(i);
		i = 0;
	}
	while (i < cub.y_down)
	{
		cub.color = get_horcolor(data, cub.hight, hitwall);
		my_mlx_pixel_put(&data->img_, x, i, cub.color);
		if (i > HEIGHT)
			break ;
		cub.hight += cub.size;
		i++;
	}
	rander_floor(data, i, x);
}

void	vertical_rayrander(t_cub *data, double *verhitwall, double pdist, int x)
{
	t_help	cub;
	int		i;

	cub.verdist = count_distance(data, verhitwall[0], verhitwall[1]);
	cub.hight = 0.0;
	i = 0;
	cub.verdist *= cos(data->player.rotation - data->rayangle);
	ver_init(data, &cub, cub.verdist, pdist);
	rander_sky(data, &cub, x);
	i = cub.y_top;
	if (i < 0)
	{
		cub.hight += cub.size * abs(i);
		i = 0;
	}
	while (i < cub.y_down)
	{
		cub.color = get_vercolor(data, cub.hight, verhitwall);
		my_mlx_pixel_put(&data->img_, x, i, cub.color);
		if (i > HEIGHT)
			break ;
		i++;
		cub.hight += cub.size;
	}
	rander_floor(data, i, x);
}

void	ray_caster(t_cub *data, int x)
{
	double	*verhitwall;
	double	*horhitwall;
	double	ppdistance;
	double	verdist;
	double	hordist;

	horhitwall = horizontal_check(data);
	verhitwall = vertical_check(data);
	verdist = count_distance(data, verhitwall[0], verhitwall[1]);
	hordist = count_distance(data, horhitwall[0], horhitwall[1]);
	ppdistance = (WIDTH / 2) / tan(rad(30));
	if (horhitwall[1] <= 0 || horhitwall[0] <= 0)
		vertical_rayrander(data, verhitwall, ppdistance, x);
	else if (verhitwall[1] <= 0 || verhitwall[0] <= 0)
		horizontal_rayrander(data, horhitwall, ppdistance, x);
	else if (hordist >= verdist)
		vertical_rayrander(data, verhitwall, ppdistance, x);
	else
		horizontal_rayrander(data, horhitwall, ppdistance, x);
	free(verhitwall);
	free(horhitwall);
}

void	rander_map(t_cub *data)
{
	int	k;

	k = 0;
	data->rayangle = data->player.rotation - rad(30);
	while (k < WIDTH)
	{
		ray_caster(data, k);
		data->rayangle += FOV / WIDTH;
		k++;
	}
}
