/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:30:51 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/03 10:30:58 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_stepss(t_cub *data)
{
	data->hor.yin = floor((data->player.y / SQRS)) * SQRS;
	if (sin(data->rayangle) > 0)
		data->hor.yin += SQRS;
	data->hor.xin = ((data->player.y - data->hor.yin) / tan(data->rayangle));
	if (cos(data->rayangle) < 0)
		data->hor.xin = data->player.x - fabs(data->hor.xin);
	else
		data->hor.xin = data->player.x + fabs(data->hor.xin);
	data->hor.ystep = SQRS;
	if (sin(data->rayangle) < 0)
		data->hor.ystep *= -1;
	data->hor.xstep = SQRS / tan(data->rayangle);
	if ((cos(data->rayangle) < 0 && data->hor.xstep > 0)
		|| (cos(data->rayangle) > 0 && data->hor.xstep < 0))
		data->hor.xstep *= -1;
	data->hor.nhorx = data->hor.xin;
	data->hor.nhory = data->hor.yin;
	if (sin(data->rayangle) < 0)
		data->hor.nhory -= 0.001;
}

double	*horizontal_check(t_cub *d)
{
	double	*horhitwall;

	horhitwall = malloc(2 * sizeof(double));
	get_stepss(d);
	while (1)
	{
		if (d->hor.nhorx >= (SQRS * d->h_w.width) || d->hor.nhorx <= 0
			|| d->hor.nhory >= (SQRS * d->h_w.height) || d->hor.nhory <= 0)
		{
			horhitwall[0] = -1;
			horhitwall[1] = -1;
			break ;
		}
		if (check_if_hitwall(d, d->hor.nhory, d->hor.nhorx))
		{
			horhitwall[0] = d->hor.nhorx;
			horhitwall[1] = d->hor.nhory;
			break ;
		}
		d->hor.nhorx += d->hor.xstep;
		d->hor.nhory += d->hor.ystep;
	}
	return (horhitwall);
}
