
#ifndef THREAD_H
# define THREAD_H
# include "wolf.h"
# include <pthread.h>

# define NUM_OF_THREADS 8

typedef struct s_window t_window;

typedef struct	s_thread
{
	int				*x;
	t_window		*wind;
	int				num;
	pthread_t		des;
}               t_thread;

#endif