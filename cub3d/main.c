#include "cub.h"
void	my_mlx_pixel_put(t_immg *data, int x, int y, int color)
{
	char	*dst;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}


////my_mlx_pixel_put2(&data->img_, &data->xpm,x, y);

int	my_mlx_pixel_put2(t_immg *data, t_xpm *xpm,int x, int y)
{

	char	*dst;
	// char	*dst1;
	// printf("%s\n", xpm->data_img);
	if (x >= 0 && x < xpm->img_width && y >= 0 && y < xpm->img_height)
	{

		dst = xpm->data_img + (y * xpm->size_line + x
				* (xpm->bits_per_pixel / 8));
		// // printf("%s\n", dst);
		// dst1 = data->addr + (y * data->line_length + x
		// 		* (data->bits_per_pixel / 8));
		return (*(unsigned int *)dst);
		// *(unsigned int *)dst1 = *(unsigned int *)dst;
	}
	return (0);
}

void	dda_line(t_cub	*data, double x, double y, int color)
{
	t_dda	dda;
	dda.dx = x - data->player.x;
	dda.dy = y - data->player.y;
	if (fabs(dda.dx) > fabs(dda.dy))
		dda.steps = fabs(dda.dx);
	else
		dda.steps = fabs(dda.dy);
	dda.xinc = dda.dx / dda.steps;
	dda.yinc = dda.dy / dda.steps;
	dda.xi = data->player.x;
	dda.yi = data->player.y;
	while((int)dda.steps--)
	{
		my_mlx_pixel_put(&data->img_, dda.xi, dda.yi, color);
		dda.xi += dda.xinc;
		// if ((dda.xi / 64))
		dda.yi += dda.yinc;
	}
}

void	draw_player(t_cub *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SIZE / 3)
	{
		j = 0;
		while (j < SIZE / 3)
		{
			my_mlx_pixel_put(&data->img_, x + i, y + j, color);
			my_mlx_pixel_put(&data->img_, x - i, y + j, color);
			my_mlx_pixel_put(&data->img_, x + i, y - j, color);
			my_mlx_pixel_put(&data->img_, x - i, y - j, color);
			j++;
		}
		i++;
	}
}

void	drow_map(t_cub *data, int i, int j , int color)
{
	int x;
	int y;
	y = i - SQRS;
	while(y < i)
	{
		x = j - SQRS;
		while(x < j)
		{
			if (x == j - 1)
				my_mlx_pixel_put(&data->img_, x, y, 0x17202A);
			else if (y == i - 1)
				my_mlx_pixel_put(&data->img_, x, y, 0x17202A);
			else
				my_mlx_pixel_put(&data->img_, x, y, color);
			x++;
		}
		y++;
	}
}

double rad(double ang)
{
	return (ang * (PI / 180));
}

int	check_if_hitwall(t_cub *data, float x, float y)
{
	if(data->map[(int)(x/ SQRS)]  && data->map[(int)(x/ SQRS)][(int)(y / SQRS)] == '1')
		return (1);
	return (0);
}

double	count_distance(t_cub *data, double x,  double y)
{
	double distance;

	distance = sqrt(pow(data->player.x - x, 2) + pow(data->player.y - y, 2));
	return (distance);
}


int	keey_hook(int key, t_cub *data)
{
	if (key == 65307)
		exit(0);
	data->player.xtmp = data->player.x;
	data->player.ytmp = data->player.y;
	if (key == 119)
		move_up(data);
	else if (key == 115)
		move_down(data);
	else if (key == 97)
		move_left(data);
	else if (key == 100)
		move_right(data);
	else if (key == 65361)
		leftrotation(data);
	else if (key == 65363)
		rightrotation(data);
	if (data->map[(int)data->player.ytmp / SQRS][(int)data->player.xtmp / SQRS] != '1')
	{
		data->player.x = data->player.xtmp;
		data->player.y = data->player.ytmp;
		data->img_.img = mlx_new_image(data->mlx_, WIDTH, HEIGHT);
		data->img_.addr = mlx_get_data_addr(data->img_.img, &data->img_.bits_per_pixel,
		&data->img_.line_length, &data->img_.endian);
		drow_2d(data);
		mlx_put_image_to_window(data->mlx_, data->win_, data->img_.img, 0, 0);
		// if (key == 32)
		// 	data->weapon[0].check = 32;
		// printf("%d\n", data->weapon.width);
		// static int i;
		// while(i < 4)
		// {
		// 	int x = WIDTH / 2.3;
		// 	int a = 0;
		// 	while(a < data->weapon[i].img_width)
		// 	{
		// 	// if (key == 32)
		// 	// {
		// 	// 	i = 0;
		// 	// 	while(i < 4)
		// 	// 	{
		// 	// 		x = WIDTH / 2.3;
		// 	// 		a = 0;
		// 	// 		while(a < data->weapon[i].img_width)
		// 	// 		{
		// 	// 			draw_weapon(x, &data->weapon[i], data);
		// 	// 			x++;
		// 	// 			a++;
		// 	// 		}
		// 	// 		i++;
		// 	// 	}
		// 	// }
		// 		draw_weapon(x, &data->weapon[i], data);
		// 		x++;
		// 		a++;
		// 	}
		// 	int z = 0;
		// 	// while (z < 1000000000)
		// 	// 	z++;
		// 	drow_2d(data);
		// 	i++;
		// }
		// i = 0;
	}
	static int i;
	while(i < 4)
		{
			int x = WIDTH / 2.3;
			int a = 0;
			while(a < data->weapon[i].img_width)
			{
			// if (key == 32)
			// {
			// 	i = 0;
			// 	while(i < 4)
			// 	{
			// 		x = WIDTH / 2.3;
			// 		a = 0;
			// 		while(a < data->weapon[i].img_width)
			// 		{
			// 			draw_weapon(x, &data->weapon[i], data);
			// 			x++;
			// 			a++;
			// 		}
			// 		i++;
			// 	}
			// }
				draw_weapon(x, &data->weapon[i], data);
				x++;
				a++;
			}
			int z = 0;
			// while (z < 1000000000)
			// 	z++;
			// drow_2d(data);
			i++;
	}
	return (0);
}

int loop_hook(t_cub *data)
{
	int x = WIDTH / 2.3;
	int a = 0;
	printf("hna\n");
	static int i = 0;
	while(a < data->weapon[i].img_width)
	{
		// if (key == 32)
		// {
		// 	x = WIDTH / 2.3;
		// 	a = 0;
		// 	while(a < data->weapon[i].img_width)
		// 	{
		// 		draw_weapon(x, &data->weapon[i], data);
		// 		x++;
		// 		a++;
		// 	}
		// }
		draw_weapon(x, &data->weapon[i], data);
		x++;
		a++;
	}
	if (data->weapon->check == 32)
		i++;
	if (i == 4)
		i = 0;
	return (0);
}


int main(int ac, char **av)
 {
	(void)ac;
	t_cub   data;
	t_weapon weapon;
	// t_pars *list;
	// list = NULL;
	
	// create_list(&list, av[1]);
	// data.map = get_map(list);

    t_pars *list;
    t_path *path;

	list = NULL;
	create_list(&list, av[1]);
	data.map = get_map(list);
	check_characters(data.map);
	ifvalid_floor(data.map);
	if (!is_mapclosed(data.map))
	{
		write(2, "error map not closed\n", 21);
		exit (1);
	}
	ifvalid_space(data.map); ///this check is not important
	path__(list, &path);
	rgbtoint(path);
	data.map = rectagle_map(data.map);
	// for(int a = 0; data.map[a]; a++)
	// {
	// 	printf("%s\n", data.map[a]);
	// }
	// exit (1);
	////
	data.mlx_ = mlx_init();
	data.win_ = mlx_new_window(data.mlx_, WIDTH , HEIGHT, "Abomination3D");

	//file to image
	// xpm.relative_path = "./yahamdan.xpm";
	// xpm.img = mlx_xpm_file_to_image(data.mlx_, xpm.relative_path, &xpm.img_width, &xpm.img_height);
	// // char *img = xpm.img;
	// xpm.data_img = (unsigned int *)mlx_get_data_addr(data.mlx_, &xpm.bits_per_pixel, &xpm.size_line, &xpm.endian);
	
	// exit(1);
	// t_xpm xpm;
	//data.map
	data.weapon = malloc(sizeof(t_weapon) * 5);
	data.weapon[0].relative_path = "./textures/gun/frame1.xpm";
	data.weapon[1].relative_path = "./textures/gun/frame2.xpm";
	data.weapon[2].relative_path = "./textures/gun/frame3.xpm";
	data.weapon[3].relative_path = "./textures/gun/frame4.xpm";
	data.weapon[4].relative_path = "./textures/gun/frame5.xpm";
	data.weapon[0].img = mlx_xpm_file_to_image(data.mlx_, data.weapon[0].relative_path, &data.weapon[0].img_width, &data.weapon[0].img_height);
	data.weapon[0].data_img =  (char *)mlx_get_data_addr(data.weapon[0].img, &data.weapon[0].bits_per_pixel, &data.weapon[0].size_line, &data.weapon[0].endian);
	///
		data.weapon[1].img = mlx_xpm_file_to_image(data.mlx_, data.weapon[1].relative_path, &data.weapon[1].img_width, &data.weapon[1].img_height);
	data.weapon[1].data_img =  (char *)mlx_get_data_addr(data.weapon[1].img, &data.weapon[1].bits_per_pixel, &data.weapon[1].size_line, &data.weapon[1].endian);
	///
		data.weapon[2].img = mlx_xpm_file_to_image(data.mlx_, data.weapon[2].relative_path, &data.weapon[2].img_width, &data.weapon[2].img_height);
	data.weapon[2].data_img =  (char *)mlx_get_data_addr(data.weapon[2].img, &data.weapon[2].bits_per_pixel, &data.weapon[2].size_line, &data.weapon[2].endian);
	///
		data.weapon[3].img = mlx_xpm_file_to_image(data.mlx_, data.weapon[3].relative_path, &data.weapon[3].img_width, &data.weapon[3].img_height);
	data.weapon[3].data_img =  (char *)mlx_get_data_addr(data.weapon[3].img, &data.weapon[3].bits_per_pixel, &data.weapon[3].size_line, &data.weapon[3].endian);
	///
		data.weapon[4].img = mlx_xpm_file_to_image(data.mlx_, data.weapon[4].relative_path, &data.weapon[4].img_width, &data.weapon[4].img_height);
	data.weapon[4].data_img =  (char *)mlx_get_data_addr(data.weapon[4].img, &data.weapon[4].bits_per_pixel, &data.weapon[4].size_line, &data.weapon[4].endian);
	// printf("%d\n", data.weapon.width);
	
	// weapon
	data.xpm = malloc(sizeof(t_xpm) * 4);
	data.xpm[0].relative_path = "./textures/marble/m1.xpm";
	data.xpm[1].relative_path = "./textures/map2/wall1.xpm";
	data.xpm[2].relative_path = "./textures/map2/wall2.xpm";
	data.xpm[3].relative_path = "./textures/marble/m2.xpm";
	data.xpm[0].img = mlx_xpm_file_to_image(data.mlx_, data.xpm[0].relative_path, &data.xpm[0].img_width, &data.xpm[0].img_height);
	data.xpm[1].img = mlx_xpm_file_to_image(data.mlx_, data.xpm[1].relative_path, &data.xpm[1].img_width, &data.xpm[1].img_height);
	data.xpm[2].img = mlx_xpm_file_to_image(data.mlx_, data.xpm[2].relative_path, &data.xpm[2].img_width, &data.xpm[2].img_height);
	data.xpm[3].img = mlx_xpm_file_to_image(data.mlx_, data.xpm[3].relative_path, &data.xpm[3].img_width, &data.xpm[3].img_height);
	// char *img = data.xpm.img;
	data.xpm[0].data_img = (char *)mlx_get_data_addr(data.xpm[0].img, &data.xpm[0].bits_per_pixel, &data.xpm[0].size_line, &data.xpm[0].endian);
	data.xpm[1].data_img = (char *)mlx_get_data_addr(data.xpm[1].img, &data.xpm[1].bits_per_pixel, &data.xpm[1].size_line, &data.xpm[1].endian);
	data.xpm[2].data_img = (char *)mlx_get_data_addr(data.xpm[2].img, &data.xpm[2].bits_per_pixel, &data.xpm[2].size_line, &data.xpm[2].endian);
	data.xpm[3].data_img = (char *)mlx_get_data_addr(data.xpm[3].img, &data.xpm[3].bits_per_pixel, &data.xpm[3].size_line, &data.xpm[3].endian);
	// printf("%s\n", data.xpm[0].data_img);
	
	/////
	data.img_.img = mlx_new_image(data.mlx_, WIDTH, HEIGHT);
	data.img_.addr = mlx_get_data_addr(data.img_.img, &data.img_.bits_per_pixel,
		&data.img_.line_length, &data.img_.endian);
	player_position(&data);
	drow_2d(&data);
	mlx_put_image_to_window(data.mlx_, data.win_, data.img_.img, 0, 0);
	// draw_weapon(1, &data);
	mlx_hook(data.win_, 2, 1L<<0, keey_hook, &data);
	// mlx_loop_hook(data.win_, loop_hook, &data);
	mlx_loop(data.mlx_);
}
