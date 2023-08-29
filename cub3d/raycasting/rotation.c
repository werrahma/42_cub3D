#include "../cub.h"

void    rightrotation(t_cub *data)
{
    data->player.rotation += 0.05235988;
    if (data->player.rotation > 6.283185)
        data->player.rotation = 0;
}

void    leftrotation(t_cub *data)
{
    data->player.rotation -= 0.05235988;
    if (data->player.rotation < 0)
        data->player.rotation = 6.283185;
}