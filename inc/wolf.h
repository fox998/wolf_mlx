
#ifndef WOLF_H
# define WOLF_H
# include "../lib/minilibx/mlx.h"
# include <pthread.h>

# ifdef __APPLE__
#  define ESC 53
#  define RIGHT_ERROW 123
#  define LEFT_ERROW 124
#  define UP_ERROW 126
#  define DOWN_ERROW 125
#  define MINUS 78
#  define PLUS 69
#  define ONE 18
#  define TWO 19
#  define Q_KEY 12
#  define W_KEY 13
#  define E_KEY 14
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define SPASE 49
# else
#  define ONE 1
# endif

# define WIN_W 1000
# define WIN_H 800

# define NUM_OF_THREADS 20

typedef double	t_rot_mat[4][4];

typedef struct	s_image
{
	int				bit_pixel;
	int				line_size;
	int				endian;
	void			*img_ptr;
	char			*pix_ptr;
}               t_image;

typedef struct	s_window
{
	int				*num_of_wind;
	void			*mlx;
	void			*win;
	t_image			*img;
	t_rot_mat		*rot;
	void			*(*fract_foo)(void *param);
	int				line_per_thread;
}				t_window;

typedef struct	s_thread
{
	int				*y;
	t_window		*wind;
	int				num;
	pthread_t		des;
}               t_thread;    

#endif
