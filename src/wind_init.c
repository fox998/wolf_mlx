#include "../inc/wolf.h"
#include "../inc/read.h"
#include "../lib/minilibx/mlx.h"
#include <stdlib.h>
#include <math.h>

static t_cam	*get_cam(double eng, int posX, int posY)
{
	t_cam	*tmp;
	double	pi;
	
	pi = 3.1415926536;
	eng = pi * eng / 180.0;
	tmp = (t_cam*)malloc(sizeof(t_cam));
	tmp->cam_pos[0] = posX + 0.5;
	tmp->cam_pos[1] = posY + 0.5;
	tmp->dir[0] = cos(eng);
	tmp->dir[1] = sin(eng);
	tmp->plane[0] = -tmp->dir[1];
	tmp->plane[1] = tmp->dir[0];
	return (tmp);
}

static t_image	*get_image(void *mlx, int w, int h)
{
	t_image    	*img;

	img = (t_image *)malloc(sizeof(t_image));
	img->img_ptr = mlx_new_image(mlx, w, h);
	img->pix_ptr = mlx_get_data_addr(img->img_ptr,
	&img->bit_pixel, &img->line_size, &img->endian);
	img->h = h;
	img->byte_pixel = img->bit_pixel / 8;
	img->w = img->line_size / img->byte_pixel;
	return (img);
}

void    		wind_init(t_window *wind, char *map_path)
{
	t_map		*map;

	map = (t_map*)malloc(sizeof(t_map));
	read_map(map_path, &map->m, &map->h, &map->w);
	wind->map = map;
	wind->mlx = mlx_init();
	wind->win = mlx_new_window(wind->mlx, WIN_W, WIN_H, "Wolf");
	wind->scrin = get_image(wind->mlx, WIN_W, WIN_H);
	wind->mini_map = get_image(wind->mlx, WIN_W , WIN_H );
	wind->cam = get_cam(0, 1, 1);
}