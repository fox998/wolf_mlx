
#include "../inc/wolf.h"
#include "../inc/read.h"
#include "../lib/libft/libft.h"

#include <stdio.h>

int main(int argc, char **argv)
{
	t_map	map;

	map.m = NULL;
	if (argc == 2)
		read_map(argv[1], &map.m, &map.h, &map.w);
	
	ft_putstr("\nHello World\n");
	for(int i = 0; i < map.h; i++)
		free(map.m[i]);
	free(map.m);
}