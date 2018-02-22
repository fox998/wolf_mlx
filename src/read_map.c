#include "../lib/libft/libft.h"
#include "../inc/read.h"
#include <fcntl.h>
#include <stdlib.h>

void read_usage(char f)
{
	if (f == 'f')
		ft_putstr("Usage: ./wolf3d map_file\n");
	else if(f == 'm')
		ft_putstr("Error: incorrect map format\n");
	exit(1);
}

static t_ml *get_lines(int fd, int *count)
{
	t_ml    *head;
	t_ml    *temp;

	head = (t_ml*)malloc(sizeof(t_ml));
	temp = head;
	*count = 0;
	while (get_next_line(fd, &temp->line) > 0)
	{
		(*count)++;
		temp->next = (t_ml *)malloc(sizeof(t_ml));
		temp = temp->next;
	}
	temp->next = NULL;
	return (head);
}
static int  *get_int_arr(char **line, int *w)
{
	int         i;
	int         *arr;

	i = 0;
	while(line[i])
		i++;
	i != *w && *w != -1 ? read_usage('m') : (*w = i);
	arr = (int *) malloc(sizeof(int) * i);
	i = -1;
	while (line[++i])
	{
		arr[i] = ft_atoi(line[i]);
		free(line[i]);
	}
	free(line);
	return (arr);
}

static void get_map(t_ml *head, int **map, int *w)
{
	char        **l;
	int         i;
	t_ml		*tmp;

	i = -1;
	*w = -1;
	tmp = head;
	while (tmp->next)
	{
		l = ft_strsplit(tmp->line, ' ');
		tmp->line ? free(tmp->line) : 0;
		map[++i] = get_int_arr(l, w);
		head = tmp;
		tmp = tmp->next;
		free(head);
	}
	tmp->line ? free(tmp->line) : 0;
	free(tmp);
}

void        read_map(char *map_path, int ***map, int *h, int *w)
{
	int		fd;
	t_ml	*tmp;
	int		i;


	if (!(fd = open(map_path, O_RDONLY)))
		read_usage('f');
	tmp = get_lines(fd, h);
	*map = (int **)malloc(sizeof(int *) * (*h));
	get_map(tmp, *map, w);
	i = -1;
	while (++i < *h)
		(*map)[i][0] == 0 || (*map)[i][*w - 1] == 0 ? read_usage('m') : 0;
	i = -1;
	while (++i < *w)
		(*map)[0][i] == 0 ? read_usage('m') : 0;
	i = -1;
	while (++i < *w)
		(*map)[*h - 1][i] == 0 ? read_usage('m') : 0;
}