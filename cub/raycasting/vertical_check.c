/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:31:31 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/03 10:31:33 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_steps(t_cub *data)
{
	data->ver.xin = floor(data->player.x / SQRS) * SQRS;
	if (cos(data->rayangle) > 0)
		data->ver.xin += SQRS;
	data->ver.yin = (data->player.x - data->ver.xin) * tan(data->rayangle);
	if (sin(data->rayangle) < 0)
		data->ver.yin = data->player.y - fabs(data->ver.yin);
	else
		data->ver.yin = data->player.y + fabs(data->ver.yin);
	data->ver.xstep = SQRS;
	if (cos(data->rayangle) < 0)
		data->ver.xstep *= -1;
	data->ver.ystep = SQRS * tan(data->rayangle);
	if ((sin(data->rayangle) > 0 && data->ver.ystep < 0)
		|| (sin(data->rayangle) < 0 && data->ver.ystep > 0))
		data->ver.ystep *= -1;
	data->ver.nverx = data->ver.xin;
	data->ver.nvery = data->ver.yin;
	if (cos(data->rayangle) < 0)
		data->ver.nverx -= 0.001;
}

double	*vertical_check(t_cub *d)
{
	double	*hitwall;

	hitwall = malloc(2 * sizeof(double));
	get_steps(d);
	while (1)
	{
		if (d->ver.nvery >= (SQRS * d->h_w.height) || d->ver.nvery <= 0
			|| d->ver.nverx >= (SQRS * d->h_w.width) || d->ver.nverx <= 0)
		{
			hitwall[0] = -1;
			hitwall[1] = -1;
			break ;
		}
		if (check_if_hitwall(d, (d->ver.nvery), (d->ver.nverx)))
		{
			hitwall[0] = d->ver.nverx;
			hitwall[1] = d->ver.nvery;
			break ;
		}
		d->ver.nverx += d->ver.xstep;
		d->ver.nvery += d->ver.ystep;
	}
	return (hitwall);
}
