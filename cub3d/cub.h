#ifndef CUB_H
#define CUB_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "parsing/get_next_line.h"

# define WIDTH (33 * 32)
# define HEIGHT (16 * 32)
# define SIZE 9
# define FOV 1.0472
# define CRNUM (WIDTH)
# define SQRS 32
# define PI 3.14159265359


typedef struct s_weapon
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	char	*data_img;
	int width, height, bits_per_pixel, size_line, endian;
	int		check;
}				t_weapon;

typedef struct s_xpm
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	char	*data_img;
	int width, height, bits_per_pixel, size_line, endian;
}				t_xpm;

typedef struct s_horcheck
{
	float	xstep;
	float	ystep;
	float	next_horx;
	float	next_hory;
	float	hitwallx;
	float	hitwally;
	float	xintercept;
	float	yintercept;
}	t_hor;

typedef struct s_vercheck
{
	float	xstep;
	float	ystep;
	float	next_verx;
	float	next_very;
	float	hitwallx;
	float	hitwally;
	float	xintercept;
	float	yintercept;
}	t_ver;

typedef struct s_dda
{
	double	dx;
	double	dy;
	double 	steps;
	double	xi;
	double	yi;
	double	xinc;
	double	yinc;
}		t_dda;

typedef struct	s_immg {
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
	double	xintercept;
	double	yintercept;
}	t_player;

typedef struct s_cub
{
	void    *mlx_;
	void    *win_;
	char	**map;
	double rayangle;
	struct s_immg   img_;
	struct s_player player;
	struct s_horcheck	hor;
	struct s_vercheck	ver;
	struct s_xpm		*xpm;
	struct s_weapon		*weapon;
}   t_cub;

typedef struct s_pars
{
	char *string;
	struct s_pars *next;
}              t_pars ;


typedef struct s_flag
{
	int	SO;
	int	WE;
	int	EA;
	int	NO;
	int	F;
	int	C;
}				t_flag;

typedef struct s_path
{
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	char	*NO_path;
	char	*F_path;
	char	*C_path;
	int		c;
	int		f;
}				t_path;

void	create_list(t_pars **list, char *n_file);
void	ft_lstadd_back(t_pars **lst, t_pars *new);
t_pars	*ft_lstnew(char *str);
int	ft_strcmp(char *s1, char *s2);
char	**get_map(t_pars *list);
void	check_characters(char **map);
int is_mapclosed(char **map);
void	path__(t_pars *list, t_path **path);
void	ifvalid_space(char **map);
void	ifvalid_floor(char **map);
void	rgbtoint(t_path *path);
char	**rectagle_map(char **map);
void	draw_weapon(int x, t_weapon *weapon, t_cub *data);

// void	create_list(t_pars **list, char *n_file);
// void	ft_lstadd_back(t_pars **lst, t_pars *new);
// t_pars	*ft_lstnew(char *str);
// int	ft_strcmp(char *s1, char *s2);
// char	**get_map(t_pars *list);
// int	check_characters(char **map);
// int is_mapclosed(char **map);


// raycasting 
void    rightrotation(t_cub *data);
void    leftrotation(t_cub *data);
void    move_up(t_cub *data);
void    move_down(t_cub *data);
void    move_right(t_cub *data);
void    move_left(t_cub *data);
void	ray_caster(t_cub *data, int x);
double	rad(double ang);
void	player_position(t_cub *data);
void    drow_2d(t_cub *data);
double	*horizontal_check(t_cub *data);
double	*vertical_check(t_cub *data);
void	my_mlx_pixel_put(t_immg *data, int x, int y, int color);
double	count_distance(t_cub *data, double x,  double y);
int	check_if_hitwall(t_cub *data, float x, float y);
void	drow_map(t_cub *data, int i, int j , int color);
void	dda_line(t_cub	*data, double x, double y, int color);
int	my_mlx_pixel_put2(t_immg *data, t_xpm *xpm,int x, int y);
#endif
