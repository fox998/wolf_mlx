#include "../inc/wolf.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"

static void	get_squer(int x, int y, t_image *img, int color, int zoom)
{
	int i;
	int j;

	i = -1;
	while (++i < zoom)
	{
		j = -1;
		while (++j < zoom)
			*(int*)(img->pix_ptr  + ((x * zoom + j) * img->bit_pixel /
			8 + (y * zoom + i) * img->line_size)) = 0xFFFFFF * color;
	}
}

void	mini_map(t_window *wind)
{
	int i;
	int j;
	int zoom;

	i = -1;
	zoom = ft_min(wind->mini_map->h / wind->map->h,
	(wind->mini_map->line_size >> 2) / wind->map->w);
	while (++i < wind->map->h)
	{
		j = -1;
		while (++j < wind->map->w)
			get_squer(j , i, wind->mini_map, wind->map->m[i][j], zoom);
	}
	mlx_put_image_to_window(wind->mlx, wind->win, wind->mini_map->img_ptr, 10, 10);
}