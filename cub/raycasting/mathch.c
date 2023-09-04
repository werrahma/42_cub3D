/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:31:04 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/03 10:31:06 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	rad(double ang)
{
	return (ang * (PI / 180));
}

double	count_distance(t_cub *data, double x, double y)
{
	double	distance;

	distance = sqrt(pow(data->player.x - x, 2) + pow(data->player.y - y, 2));
	return (distance);
}
