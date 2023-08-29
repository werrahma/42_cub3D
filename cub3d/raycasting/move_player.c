#include "../cub.h"

void    move_up(t_cub *data)
{
    data->player.xtmp += cos(data->player.rotation) * 15;
    data->player.ytmp += sin(data->player.rotation) * 15;
}
void    move_down(t_cub *data)
{
    data->player.xtmp += cos(data->player.rotation) * -15;
    data->player.ytmp += sin(data->player.rotation) * -15;
}

void    move_right(t_cub *data)
{
    data->player.xtmp += cos(data->player.rotation + rad(90)) * 15;
    data->player.ytmp += sin(data->player.rotation + rad(90)) * 15;
}

void    move_left(t_cub *data)
{
    data->player.xtmp += cos(data->player.rotation + rad(90)) * -15;
    data->player.ytmp += sin(data->player.rotation + rad(90)) * -15;
}
