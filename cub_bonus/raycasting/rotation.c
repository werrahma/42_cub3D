/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:31:28 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/03 10:31:29 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	rightrotation(t_cub *data)
{
	data->player.rotation += rad(3);
	if (data->player.rotation > 6.283185)
		data->player.rotation = 0;
}

void	leftrotation(t_cub *data)
{
	data->player.rotation -= rad(3);
	if (data->player.rotation < 0)
		data->player.rotation = 6.283185;
}
