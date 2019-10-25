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

# define V 0
# define H 1

/*
** Structure w/ all map data.
** width - map width.
** height - map height.
** level - Buffer to store level.
*/
typedef struct		s_map
{
	int				width;
	int				height;
	char			**level;
}					t_map;

typedef struct		s_ray
{
	double			angle;
}					t_ray;

typedef struct		s_cast
{
	t_ray			*ray;
	double			distance;
}					t_cast;

/*
** Projection plane data struct.
** size - projection plane size (WIDTH * HEIGHT)
** mid[2] - сoordinates of the middle of the projection plane. (x = 0, y = 1)
** dist - distance to the projection plane.
** ray_angle - the angle between the rays.
*/
typedef struct		s_prj_plane
{
	int				size;
	double			mid[2];
	double			dist;
	double			ray_angle;
}					t_prj_plane;

/*
** Camera / Player data structure.
** coord[2] - cam coordinates on 2D map. (x = 0, y = 1)
** height - cam height.
** fov - field of view.
** pov - point of view.
** depth - drawing depth.
** prj_plane - projection plane data struct ptr.
*/
typedef	struct		s_cam
{
	double			x;
	double			y;
	double			height;
	double			fov;
	double			pov;
	float			depth;
	t_prj_plane		*prj_plane;
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
	t_cast			*cast;
}					t_env;

void		read_map(const char *level_name, t_map *map);

void		renderer(t_env *env);
void		cast_a_ray(t_env *env);

t_env		*env_init(t_map *map);
t_map		*map_init();
t_cam		*cam_init();
t_cast		*cast_init();
t_ray		*ray_init();
t_prj_plane *prj_plane_init(t_cam *cam);

void init_key_hooks(t_env *env);

void draw_map(t_env *env);
void draw_player(t_env *env);
void draw_pow(t_env *env, int mapX, int mapY);
#endif
