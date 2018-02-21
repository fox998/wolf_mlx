#include "../inc/wolf.h"
#include #include <fcntl.h>

int **read_map(char *map_path)
{
    int fd;

    if (!(fd = open(map_path, O_RDONLY))
        return (NULL);
}