
#ifndef THREAD_H
# define THREAD_H

# define NUM_OF_THREADS 20

typedef struct s_window t_window;

typedef struct	s_thread
{
	int				*y;
	t_window		*wind;
	int				num;
	pthread_t		des;
}               t_thread;

#endif