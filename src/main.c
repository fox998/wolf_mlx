
#include "../inc/wolf.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx/mlx.h"

int main(int argc, char **argv)
{
	t_window	wind;

	if (argc != 2)
		return (1);
	wind_init(&wind, argv[1]);
	render(&wind);
	mlx_loop(wind.mlx);
}
