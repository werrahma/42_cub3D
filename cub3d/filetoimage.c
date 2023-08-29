#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*img;
    mlx = mlx_init();

	char	*relative_path = "./werrahma.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}