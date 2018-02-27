
#ifndef WOLF_H
# define WOLF_H

# define WIN_W 1000
# define WIN_H 800

typedef double	t_rot_mat[4][4];

typedef struct	s_map
{
	int				**m;
	int				h;
	int				w;
}				t_map;

typedef struct	s_image
{
	int				bit_pixel;
	int				line_size;
	int				endian;
	int				h;
	void			*img_ptr;
	char			*pix_ptr;
}               t_image;

typedef	int		i_vec2[2];

typedef	double	d_vec2[2];

typedef struct	s_cam
{
	d_vec2			cam_pos;
	d_vec2			dir;
	d_vec2			plane;
}				t_cam;

typedef struct	s_window
{
	int				*num_of_wind;
	int				line_per_thread;
	void			*mlx;
	void			*win;
	void			*(*fract_foo)(void *param);
	t_image			*scrin;
	t_image			*mini_map;
	t_rot_mat		*rot;
	t_cam			*cam;
	t_map			*map;
}				t_window;   

void	hook_init(t_window *wind);
void    wind_init(t_window *wind, char *map_path);
void	render(t_window *wind);

#endif
