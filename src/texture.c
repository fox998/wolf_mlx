#include "../lib/minilibx/mlx.h"
#include "../inc/wolf.h"
#include "../inc/texture.h"
#include <stdlib.h>
#include "../texture/redbrick.xpm"
#include "../texture/bluestone.xpm"
#include "../texture/colorstone.xpm"
#include "../texture/greystone.xpm"

#include <stdio.h>

static	void	get_texture(t_image *tex, int h)
{
	tex->pix_ptr = mlx_get_data_addr(tex->img_ptr,
		&tex->bit_pixel, &tex->line_size, &tex->endian);
	tex->byte_pixel = tex->bit_pixel / 8;
	tex->w = tex->line_size / tex->byte_pixel;
	tex->h = h;
}

void    texture_init(t_window *wind)
{
	t_image	*arr_t;
	int		i;
	int		h;
	int		w;

	i = -1;
	h = TEX_H;
	w = TEX_W;
	arr_t = (t_image *)malloc(sizeof(t_image) * 4);
	arr_t[0].img_ptr = mlx_xpm_to_image(wind->mlx, redbrick_xpm, &w, &h);
	arr_t[1].img_ptr = mlx_xpm_to_image(wind->mlx, bluestone_xpm, &w, &h);
	arr_t[2].img_ptr = mlx_xpm_to_image(wind->mlx, colorstone_xpm, &w, &h);
	arr_t[3].img_ptr = mlx_xpm_to_image(wind->mlx, greystone_xpm, &w, &h);
	while (++i < 4)
		get_texture(&arr_t[i], h);
	wind->tex = arr_t;
}