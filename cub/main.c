/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:45:15 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/04 12:41:34 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_cub	data;
	t_pars	*list;

	list = NULL;
	ifvalid_mapname(ac, av[1]);
	create_list(&list, av[1]);
	data.map = get_map(list);
	path_checker(list, &data.path);
	ifvalid_floor(data.map);
	is_mapclosed(data.map);
	check_characters(data.map);
	rgbtoint(data.path);
	data.map = rectagle_map(data.map);
	h_w_map(data.map, &data.h_w);
	data.mlx_ = mlx_init();
	data.win_ = mlx_new_window(data.mlx_, WIDTH, HEIGHT, "Abomination3D");
	setting_texwalls(&data);
	player_position(&data);
	mlx_render_img(&data);
	mlx_hook(data.win_, 2, 1L << 0, keey_hook, &data);
	mlx_hook(data.win_, 17, 0, event_hook, &data);
	mlx_loop(data.mlx_);
}
