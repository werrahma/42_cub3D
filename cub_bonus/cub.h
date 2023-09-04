/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <yahamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:34:58 by yahamdan          #+#    #+#             */
/*   Updated: 2023/09/04 12:55:35 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "parsing/get_next_line.h"

# define WIDTH 1000
# define HEIGHT 500
# define SIZE 8
# define SPEED 8
# define FOV 1.0472
# define SQRS 64
# define PI 3.14159265359

typedef struct s_path
{
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*no_path;
	char	*f_path;
	char	*c_path;
	int		c;
	int		f;
}				t_path;

typedef struct s_h_w
{
	int	height;
	int	width;
}				t_h_w;

typedef struct s_xpm
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	char	*data_img;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_xpm;

typedef struct s_horcheck
{
	float	xstep;
	float	ystep;
	float	nhorx;
	float	nhory;
	float	xin;
	float	yin;
}				t_hor;

typedef struct s_vercheck
{
	float	xstep;
	float	ystep;
	float	nverx;
	float	nvery;
	float	xin;
	float	yin;
}				t_ver;

typedef struct s_dda
{
	double	dx;
	double	dy;
	double	steps;
	double	xi;
	double	yi;
	double	xinc;
	double	yinc;
}				t_dda;

typedef struct s_immg {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_immg;

typedef struct s_player
{
	double	xtmp;
	double	ytmp;
	double	x;
	double	y;
	double	rotation;
	double	xin;
	double	yin;
}				t_player;

typedef struct s_mouse
{
	int	x;
	int	y;
}				t_mouse;

typedef struct s_cub
{
	char				**map;
	void				*mlx_;
	void				*win_;
	double				rayangle;
	struct s_xpm		*xpm;
	struct s_h_w		h_w;
	struct s_path		*path;
	struct s_immg		img_;
	struct s_mouse		mouse;
	struct s_player		player;
	struct s_horcheck	hor;
	struct s_vercheck	ver;
}				t_cub;

typedef struct s_pars
{
	char			*string;
	struct s_pars	*next;
}				t_pars;

typedef struct s_flag
{
	int	so;
	int	we;
	int	ea;
	int	no;
	int	f;
	int	c;
}				t_flag;

typedef struct s_help
{
	double	pphight;
	double	y;
	double	size;
	int		y_top;
	int		y_down;
	double	hight;
	int		color;
	double	hordist;
	double	verdist;
}				t_help;

void	create_list(t_pars **list, char *n_file);
void	ft_lstadd_back(t_pars **lst, t_pars *new);
t_pars	*ft_lstnew(char *str);
int		ft_strcmp(char *s1, char *s2);
char	**get_map(t_pars *list);
void	check_characters(char **map);
void	is_mapclosed(char **map);
void	path__(t_pars *list, t_path **path);
void	ifvalid_space(char **map);
void	ifvalid_floor(char **map);
void	rgbtoint(t_path *path);
char	**rectagle_map(char **map);
void	path_checker(t_pars *list, t_path **path);
char	*pathfind(char *str);
char	*findrgb(char *str);
char	**ignor_space(char **map);
void	free_split(char **split);
void	check_characters(char **map);
int		height_map(char **map);
void	error_handler3(int flag);
void	error_handler(int i, t_flag flag);
int		shifting(char *r, char *g, char *b);
void	setting_texwalls(t_cub *data);
void	h_w_map(char **map, t_h_w *h_w);
void	ifvalid_mapname(int ac, char *av);
int		get_position(double pos, int tex_width);
void	rightrotation(t_cub *data);
void	leftrotation(t_cub *data);
void	move_up(t_cub *data);
void	move_down(t_cub *data);
void	move_right(t_cub *data);
void	move_left(t_cub *data);
void	ray_caster(t_cub *data, int x);
double	rad(double ang);
void	player_position(t_cub *data);
void	rander_map(t_cub *data);
double	*horizontal_check(t_cub *data);
double	*vertical_check(t_cub *data);
void	my_mlx_pixel_put(t_immg *data, int x, int y, int color);
double	count_distance(t_cub *data, double x, double y);
int		check_if_hitwall(t_cub *data, float x, float y);
int		get_pixels(t_xpm *xpm, int x, int y);
void	mlx_render_img(t_cub *data);
int		mouse_hook(int x, int y, t_cub *data);
int		keey_hook(int key, t_cub *data);
int		position_check(t_cub *data, float newx, float newy);
void	drow_minimap(t_cub *data);
int		event_hook(t_cub *data);
void	hor_init(t_cub *data, t_help *cub, double hdist, double pdist);
void	rander_floor(t_cub *data, int i, int x);
int		get_horcolor(t_cub *data, double hight, double *hitwall);
void	ver_init(t_cub *data, t_help *cub, double vdist, double pdist);
int		get_vercolor(t_cub *data, double hight, double *hitwall);

#endif
