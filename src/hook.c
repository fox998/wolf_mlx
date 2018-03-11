
#include "../inc/keys.h"
#include "../inc/wolf.h"
#include "../lib/minilibx/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include <stdio.h>

int		leave_hook(void *param)
{
	exit(0);
}

int		mouse_move_hook(int x, int y, void *param)
{
	static int xc = 0;
	double	eng;
	double	oldx;
	double	cos_sin[2];
	t_window	*wind;

	if (abs(xc - x) < 3)
		return 0;
	wind = (t_window *)param;
	x  > xc ? (eng = M_PI * (2) / 180.0) : 0;
	x  < xc ? (eng = M_PI * (-2) / 180.0) : 0;
	oldx = wind->cam->dir[0];
	cos_sin[0] = cos(eng);
	cos_sin[1] = sin(eng);
	wind->cam->dir[0] = wind->cam->dir[0] * cos_sin[0] - wind->cam->dir[1] * cos_sin[1];
	wind->cam->dir[1] = oldx * cos_sin[1] + wind->cam->dir[1] * cos_sin[0];
	wind->cam->plane[0] = -wind->cam->dir[1];
	wind->cam->plane[1] = wind->cam->dir[0];
	render(wind);
	(xc = x);
	return (0);
}

int		mouse_hook(int key, int x, int y, void *param)
{
	
}

int		key_hook(int key, void *param)
{
	t_window	*wind;
	double		delta_pos;
	d_vec2		*direct;
	int			sign;
	int			new_map[2];

	wind = (t_window *)param;
	delta_pos = 0.1;
	key == ESC ? exit(0) : 0;
	(key == A_KEY || key == D_KEY) ? (direct = &wind->cam->plane) : (direct = &wind->cam->dir);
	(key == A_KEY || key == S_KEY) ? sign = -1 : (sign = 1);
	new_map[0] = wind->cam->cam_pos[0] + (*direct)[0] * delta_pos * sign;
	new_map[1] = wind->cam->cam_pos[1] + (*direct)[1] * delta_pos * sign;
	if (wind->map->m[new_map[1]][new_map[0]] > 0 )
		return (0);
	wind->cam->cam_pos[0] += (*direct)[0] * delta_pos * sign;
	wind->cam->cam_pos[1] += (*direct)[1] * delta_pos * sign;
	render(wind);
}

void	hook_init(t_window *wind)
{
	mlx_hook(wind->win, 6,
		64, &mouse_move_hook, wind);
	mlx_hook(wind->win, 17, (1L << 5), &leave_hook, wind);
	mlx_hook(wind->win, 4, (1L << 2), &mouse_hook, wind);
	mlx_hook(wind->win, 2, (1L << 0), &key_hook, wind);
}
