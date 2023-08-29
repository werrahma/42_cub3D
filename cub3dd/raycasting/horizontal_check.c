# include "../cub.h"

double	*horizontal_check(t_cub *data)
{

	double *horhitwall = malloc(2 * sizeof(double));
	data->hor.yintercept = floor((data->player.y / SQRS)) * SQRS;
	if (sin(data->rayangle) > 0)
		data->hor.yintercept += SQRS;
	data->hor.xintercept = ((data->player.y - data->hor.yintercept) / tan(data->rayangle));
	if (cos(data->rayangle) < 0)
		data->hor.xintercept = data->player.x - fabs(data->hor.xintercept);
	else
		data->hor.xintercept = data->player.x + fabs(data->hor.xintercept);
	data->hor.ystep = SQRS;
	if (sin(data->rayangle) < 0)
		data->hor.ystep *= -1;
	data->hor.xstep = SQRS / tan(data->rayangle);
	if ((cos(data->rayangle) < 0 && data->hor.xstep > 0)
		|| (cos(data->rayangle) > 0 && data->hor.xstep < 0))
	data->hor.xstep *= -1;
	data->hor.next_horx = data->hor.xintercept;
	data->hor.next_hory = data->hor.yintercept;
	if(sin(data->rayangle) < 0)
		data->hor.next_hory -= 0.001;
	while (data->hor.next_horx >= 0 && data->hor.next_horx <= WIDTH && data->hor.next_hory >= 0 && data->hor.next_hory <= HEIGHT)
	{
		if (check_if_hitwall(data, data->hor.next_hory, data->hor.next_horx))
		{
			data->hor.hitwallx = data->hor.next_horx;
			data->hor.hitwally = data->hor.next_hory;
			horhitwall[0] = data->hor.hitwallx;
			horhitwall[1] = data->hor.hitwally;
			break;
		}
		data->hor.next_horx += data->hor.xstep;
		data->hor.next_hory += data->hor.ystep;
	}
	return (horhitwall);
}
