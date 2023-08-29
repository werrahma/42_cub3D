#include "cub.h"

void    dda_line(t_cub    *data, double x, double y, int color)
{
    t_dda    dda;
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

int    loop_hook(t_cub *data)
{
    printf("hna\n");
    return (1);
}


int main(int ac, char **av)
 {
    (void)ac;
    t_cub   data;
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
    ifvalid_space(data.map);
    path__(list, &path);
    rgbtoint(path);
    data.map = rectagle_map(data.map);
    // for(int a = 0; data.map[a]; a++)
    // {
    //     printf("%s\n", data.map[a]);
    // }
    // exit (1);
    ////
    player_position(&data);
    data.mlx_ = mlx_init();
    data.win_ = mlx_new_window(data.mlx_, WIDTH , HEIGHT, "Abomination3D");
    mlx_render_img(&data);
    mlx_hook(data.win_, 2, 1L<<0, keey_hook, &data);
    mlx_hook(data.win_, 6, 1L<<6 , mouse_hook, &data);
    mlx_loop_hook(data.win_, loop_hook, &data);
    mlx_mouse_hide(data.mlx_, data.win_);
    mlx_loop(data.mlx_);
}