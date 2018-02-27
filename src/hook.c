
#include "../inc/keys.h"
#include "../inc/wolf.h"
#include "../lib/minilibx/mlx.h"
#include <stdlib.h>
#include <math.h>

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
	wind = (t_window *)param;
	x > xc ? (eng = M_PI * (5) / 180.0) : 0;
	x < xc ? (eng = M_PI * (-5) / 180.0) : 0;
	oldx = wind->cam->dir[0];
	cos_sin[0] = cos(eng);
	cos_sin[1] = sin(eng);
	wind->cam->dir[0] = wind->cam->dir[0] * cos_sin[0] - wind->cam->dir[1] * cos_sin[1];
	wind->cam->dir[1] = oldx * cos_sin[1] + wind->cam->dir[1] * cos_sin[0];
	wind->cam->plane[0] = -wind->cam->dir[1];
	wind->cam->plane[1] = wind->cam->dir[0];
	xc = x;
	render(wind);
}

int		mouse_hook(int key, int x, int y, void *param)
{
	
}

int		key_hook(int key, void *param)
{
	t_window	*wind;
	double		delta_pos;

	wind = (t_window *)param;
	delta_pos = 0.1;
	key == ESC ? exit(0) : 0;
	if (key == A_KEY)
	{
		wind->cam->cam_pos[0] -=  wind->cam->plane[0] * delta_pos;
		wind->cam->cam_pos[1] -=  wind->cam->plane[1] * delta_pos;
	}
	if (key == D_KEY)
	{
		wind->cam->cam_pos[0] +=  wind->cam->plane[0] * delta_pos;
		wind->cam->cam_pos[1] +=  wind->cam->plane[1] * delta_pos;
	}
	if (key == S_KEY)
	{
		wind->cam->cam_pos[0] -=  wind->cam->dir[0] * delta_pos;
		wind->cam->cam_pos[1] -=  wind->cam->dir[1] * delta_pos;
	}
	if (key == W_KEY)
	{
		wind->cam->cam_pos[0] +=  wind->cam->dir[0] * delta_pos;
		wind->cam->cam_pos[1] +=  wind->cam->dir[1] * delta_pos;
	}
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
