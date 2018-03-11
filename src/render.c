
#include "../inc/wolf.h"
#include "../inc/render.h"
#include "../inc/thread.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"
#include <math.h>

#include <stdio.h>
#include <time.h>

int		get_color(t_image *textur, int side, int cor[2])
{
	int color;
	int w;

	// color = (0x0000FF) / (1 + side);
	// textur == 2 ? color = (color << 8) : 0;
	// textur == 3 ? color = (color << 16) : 0;
	// textur > 3 ? color = color + (color << 8) +  (color << 16): 0;
	color = *(int*)(textur->pix_ptr + (cor[0] + cor[1] * textur->w) * textur->byte_pixel);
	if(side == 0) color = (color >> 1) & 8355711;
	return (color);
}

void	ver_line(t_reycaster r, t_window *wind, int x)
{
	int			border;
	int			y;
	int			line_h;
	int			tex[2];

	tex[0] = r.wallX * r.tex->w;
	//(r.side == 0 &&  wind->cam->dir[0] > 0) || (r.side == 1 &&  wind->cam->dir[1] < 0) ? tex[0] = wind->tex->w - tex[0] - 1 : 0;
	line_h = WIN_H / r.perp_wall_dist;
	border = ft_max((WIN_H - line_h) / 2, 0);
	y = -1;
	while (++y < border)
		*((int*)wind->scrin->pix_ptr + (x + y * wind->scrin->w)) = 0;
	border = ft_min((WIN_H + line_h) / 2 , WIN_H - 1);
	while (y < border)
	{
		tex[1] = y -((WIN_H - line_h) / 2);
		tex[1] = ((tex[1] * r.tex->h)/line_h);
		*(int*)(wind->scrin->pix_ptr + (x + y * wind->scrin->w) *
		wind->scrin->byte_pixel) = get_color(r.tex, r.side, tex);
		y++;
	}
	while (y < WIN_H)
		*((int*)wind->scrin->pix_ptr + (x + y++ * wind->scrin->w)) = 0;
}

void	reycaster_init(t_reycaster *r, t_cam *c, int x)
{
	double		camX;

	camX = 2.0 * x / (double) WIN_W - 1;
	r->vec_dir[0] = c->dir[0] + c->plane[0] * camX;
	r->vec_dir[1] = c->dir[1] + c->plane[1] * camX;
	r->delt_dist[0] = fabs(1.0 / r->vec_dir[0]);
	r->delt_dist[1] = fabs(1.0 / r->vec_dir[1]);
	r->map[0] = c->cam_pos[0];
	r->map[1] = c->cam_pos[1];
	r->vec_dir[0] < 0 ? r->step[0] = -1 : (r->step[0] = 1);
	r->vec_dir[1] < 0 ? r->step[1] = -1 : (r->step[1] = 1);
	r->side_dist[0] = (( - c->cam_pos[0] + r->map[0]) * r->step[0]  +
	(1 + r->step[0]) / 2) * r->delt_dist[0];
	r->side_dist[1] = ((-c->cam_pos[1] + r->map[1]) * r->step[1] +
	(1 + r->step[1]) / 2) * r->delt_dist[1];
}

void	*get_frame(void *param)
{
	int			x;
	int			i;
	double		perp_wall_dist;
	t_reycaster	r;
	t_window	*wind;

	x = *((t_thread*)param)->x + ((t_thread*)param)->num;
	wind = ((t_thread*)param)->wind;
	reycaster_init(&r, wind->cam, x);
	while (1)
	{
		r.side_dist[0] < r.side_dist[1] ? i = 0 : (i = 1);
		r.side_dist[i] += r.delt_dist[i];
		r.map[i] += r.step[i];
		if (wind->map->m[r.map[1]][r.map[0]] > 0)
			break ;
	}
	r.perp_wall_dist = (r.map[i] - wind->cam->cam_pos[i] +
	(1 - r.step[i]) / 2) / r.vec_dir[i];
	r.side = i;
	r.tex = &wind->tex[i * 2 + (r.vec_dir[i] > 0 ? 0 : 1)];
	r.wallX = wind->cam->cam_pos[1 - i] + r.perp_wall_dist * r.vec_dir[1 - i];
	r.wallX -= floor(r.wallX);
	ver_line(r, wind, x);
	return (0);
}

#include <time.h>

void	render(t_window *wind)
{
	t_thread	thread[NUM_OF_THREADS];
	int			x;
	int			num;
	static int	time = 0;

	if (clock() - time < 200 )
		return ;
	time = clock();
	x = -1;
	while (++x < NUM_OF_THREADS)
	{
		thread[x].x = &x;
		thread[x].num = x;
		thread[x].wind = wind;
	}
	x = 0;
	while (x < WIN_W)
	{
		num = -1;
		while (++num < NUM_OF_THREADS)
			pthread_create(&thread[num].des,
				NULL, &get_frame, thread + num);
		while (num-- > 0)
			pthread_join(thread[num].des, NULL);
		x += NUM_OF_THREADS;
	}
	mlx_put_image_to_window(wind->mlx, wind->win, wind->scrin->img_ptr, 0, 0);
}
