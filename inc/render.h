
#ifndef RENDER_H
# define RENDER_H
# include "wolf.h"

typedef struct  s_raycaster
{
    d_vec2		vec_dir;
	d_vec2		delt_dist;
	d_vec2		side_dist;
	i_vec2		map;
    i_vec2		step;
}               t_reycaster;

#endif