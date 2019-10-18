#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <time.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# include "libft.h"
# include "get_next_line.h"

# define WIDTH 1280
# define HEIGHT 720

# define WALL_SIZE 64

# define X 0
# define Y 1

# define OLD 0
# define NEW 1

typedef struct		s_map
{
	int				width;
	int				height;
	int				level_id;
	char			*level;
}					t_map;

/*
** Structure with everything you need for raycasting.
*/
typedef struct		s_casting
{

}					t_casting;

typedef	struct		s_cam
{
	double			x;
	double			y;
	double			dir[2];    
	double			plane[2];
	int				depth;
}					t_cam;

/*
** Main struct with all another structures and environment data;
** (like window ptr, img ptr etc)
*/
typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				sz_ln;
	int				endian;
	int				bts_pr_pxl;
	char			*data_addr;
	t_map			*map;
	t_cam			*cam;
	t_casting		*cast;
}					t_env;

void		read_map(const char *level_name, t_map *map);
/*
** Functions that are needed to render an image.
*/
void		renderer(t_env *env);
void		cast_a_ray(t_env *env);
/*
** Data init functions.
*/
t_env		*env_init(t_map *map);
t_map		*map_init();
t_cam		*cam_init();
t_casting	*cast_init();
#endif