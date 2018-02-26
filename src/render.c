#include "../inc/wolf.h"
#include "../inc/render.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"
#include <math.h>


#include <stdio.h>

void	ver_line(int line_h, t_image *img, int x, int color)
{
	int			start;
	int			end;
	int			delta;
	int			w;

	line_h >= WIN_H ? line_h = WIN_H - 1 : 0;
	line_h < 0 ? line_h = 0 : 0;
	start = (WIN_H - line_h) / 2;
	end = (WIN_H + line_h) / 2;
	delta = img->bit_pixel / 8;
	w = img->line_size / delta;
	while (start < end)
	{
		*(int*)(img->pix_ptr + (x + start * w) * img->bit_pixel / 8) = color;
		start++;
	}
}

void	reycaster_init(t_reycaster *r, t_cam *c, int x)
{
	double		camX;

	camX = 2.0 * x / (double) WIN_W - 1;
	r->vec_dir[0] = c->dir[0] + c->plane[0] * camX;
	r->vec_dir[1] = c->dir[1] + c->plane[1] * camX;
	//r->vec_dir[0] != 0 ? r->delt_dist[0] = fabs(1.0 / r->vec_dir[0]) : (r->delt_dist[0] = 0);
	r->delt_dist[0] = fabs(1.0 / r->vec_dir[0]);
	r->delt_dist[1] = fabs(1.0 / r->vec_dir[1]);
	//r->vec_dir[1] != 0 ? r->delt_dist[1] = fabs(1.0 / r->vec_dir[1]) : (r->delt_dist[1] = 0);
	r->map[0] = c->cam_pos[0];
	r->map[1] = c->cam_pos[1];
	r->vec_dir[0] < 0 ? r->step[0] = -1 : (r->step[0] = 1);
	//r->vec_dir[0] == 0 ? r->step[0] = 0 : 0;
	r->vec_dir[1] < 0 ? r->step[1] = -1 : (r->step[1] = 1);
	//r->vec_dir[1] == 0 ? r->step[1] = 0 : 0;
	r->side_dist[0] = (( - c->cam_pos[0] + r->map[0]) * r->step[0]  +
	(1 + r->step[0]) / 2) * r->delt_dist[0];
	r->side_dist[1] = ((-c->cam_pos[1] + r->map[1]) * r->step[1] +
	(1 + r->step[1]) / 2) * r->delt_dist[1];
}

void	get_frame(t_window *wind)
{
	int			x;
	int			i;
	double		perp_wall_dist;
	t_reycaster	r;

	x = -1;
	while (++x < WIN_W)
	{
		reycaster_init(&r, wind->cam, x);
		while (1)
		{
			r.side_dist[0] < r.side_dist[1] ? i = 0 : (i = 1);
			r.side_dist[i] += r.delt_dist[i];
			r.map[i] += r.step[i];
			if (wind->map->m[r.map[1]][r.map[0]] > 0)
			{
				break ;
			}
		}
		perp_wall_dist = (r.map[i] - wind->cam->cam_pos[i] +
		(1 - r.step[i]) / 2) / r.vec_dir[i];
		//printf("%d ---- %d\n", r.step[1], r.step[0]);
		printf("%f --- %f --- %f --- %f\n", r.vec_dir[0], r.vec_dir[1] ,  r.delt_dist[1], r.delt_dist[0]);
		ver_line(WIN_H / perp_wall_dist, wind->scrin, x, 0xFFFFFF * wind->map->m[r.map[1]][r.map[0]]);
	}
}

void	render(t_window *wind)
{
	//ft_putstr("q\n");
	get_frame(wind);
	//ft_putstr("w\n");
	mlx_put_image_to_window(wind->mlx, wind->win, wind->scrin->img_ptr, 0, 0);
}