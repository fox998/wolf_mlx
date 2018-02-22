
#ifndef READ_H
# define READ_H


typedef struct  s_map_line
{
    char				*line;
    struct s_map_line	*next;
}               t_ml;

void			read_map(char *map_path, int ***map, int *h, int *w);

#endif