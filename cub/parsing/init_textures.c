/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:26:29 by werrahma          #+#    #+#             */
/*   Updated: 2023/09/04 09:54:20 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_pixels(t_xpm *xpm, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < xpm->img_width && y >= 0 && y < xpm->img_height)
	{
		dst = xpm->data_img + (y * xpm->size_line + x
				* (xpm->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
	}
	return (0);
}

void	ifvalid_mapname(int ac, char *av)
{
	int	i;

	i = 0;
	if (ac != 2)
	{
		write(2, "invalid arg\n", 12);
		exit (1);
	}
	while (av[i] != '.')
		i++;
	if (ft_strcmp(&av[i], ".cub"))
	{
		write(2, "invalid name map\n", 17);
		exit(1);
	}
}

void	h_w_map(char **map, t_h_w *h_w)
{
	h_w->height = 0;
	h_w->width = 0;
	while (map[h_w->height])
		h_w->height++;
	h_w->width = ft_strlen(map[0]);
}

void	if_texinvalid(t_cub *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!data->xpm[i].img)
		{
			write(2, "invalid texture\n", 15);
			exit(1);
		}
		i++;
	}
}

void	setting_texwalls(t_cub *data)
{
	data->xpm = malloc(sizeof(t_xpm) * 4);
	data->xpm[1].relative_path = data->path->we_path;
	data->xpm[0].relative_path = data->path->ea_path;
	data->xpm[2].relative_path = data->path->so_path;
	data->xpm[3].relative_path = data->path->no_path;
	data->xpm[0].img = mlx_xpm_file_to_image(data->mlx_, data->xpm[0] \
		.relative_path, &data->xpm[0].img_width, &data->xpm[0].img_height);
	data->xpm[1].img = mlx_xpm_file_to_image(data->mlx_, data->xpm[1] \
		.relative_path, &data->xpm[1].img_width, &data->xpm[1].img_height);
	data->xpm[2].img = mlx_xpm_file_to_image(data->mlx_, data->xpm[2] \
		.relative_path, &data->xpm[2].img_width, &data->xpm[2].img_height);
	data->xpm[3].img = mlx_xpm_file_to_image(data->mlx_, data->xpm[3] \
		.relative_path, &data->xpm[3].img_width, &data->xpm[3].img_height);
	if_texinvalid(data);
	data->xpm[0].data_img = (char *)mlx_get_data_addr(data->xpm[0].img, &data \
		->xpm[0].bits_per_pixel, &data->xpm[0].size_line, &data->xpm[0].endian);
	data->xpm[1].data_img = (char *)mlx_get_data_addr(data->xpm[1].img, &data \
		->xpm[1].bits_per_pixel, &data->xpm[1].size_line, &data->xpm[1].endian);
	data->xpm[2].data_img = (char *)mlx_get_data_addr(data->xpm[2].img, &data \
		->xpm[2].bits_per_pixel, &data->xpm[2].size_line, &data->xpm[2].endian);
	data->xpm[3].data_img = (char *)mlx_get_data_addr(data->xpm[3].img, &data \
		->xpm[3].bits_per_pixel, &data->xpm[3].size_line, &data->xpm[3].endian);
}
