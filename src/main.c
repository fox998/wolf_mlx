
#include "../inc/wolf.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx/mlx.h"

#include <stdio.h>

int main(int argc, char **argv)
{
	t_window	wind;

	if (argc != 2)
		return (1);
	wind_init(&wind, argv[1]);
	texture_init(&wind);
	render(&wind);
	hook_init(&wind);
	mlx_loop(wind.mlx);
}
