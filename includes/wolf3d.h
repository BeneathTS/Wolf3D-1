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
# include "controls.h"
# include "get_next_line.h"

# define BS_TEX "textures/xpm/bluestone.xpm"
# define WD_TEX "textures/xpm/wood.xpm"

# define WIDTH 1280
# define HEIGHT 720

# define TEX_SIZE 64

# define FLOOR_COLOR 0x353C44

# define X 0
# define Y 1

# define START 0
# define FINISH 1

# define V 0 //x
# define H 1 //y

# define NO 0
# define YES 1

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

/*
** Struct withh all textures and data what it nedeed.
** tex_id - id of texture
** tex_ptr - texture img pointer
** data - texture data (use this var to get texture, not tex_ptr)
** bts_pr_pxl, sz_ln, endian not used, but that needed to mlx.
** next - next texture
** prev - previous texture
*/
typedef struct		s_tex
{
	char			id;
	int				width;
	int				height;
	void			*tex_ptr;
	char			*data;
	int				bts_pr_pxl;
	int				sz_ln;
	int				endian;
	struct s_tex	*next;
	struct s_tex	*prev;
}					t_tex;

/*
** Structure w/ all ray's data.
** v_dir - vector direction. (x = 0, y = 1)
** angle - current ray angle.
** m_pos - ray position on 2D map. (x = 0, y = 1)
** s_dist - distance for first intersection point. (0 = Vertical, 1 - Horizontal)
** d_dist - distance between intersection points. (0 = Vertical, 1 - Horizontal)
** side - hit side (Vertical or Horizontal);
*/
typedef struct		s_ray
{
	double			v_dir[2];
	double			angle;
	int				m_pos[2];
	double			s_dist[2];
	double			d_dist[2];
	char			side;
}					t_ray;

/*
** Structure w/ all needed data for raycasting.
** ray - ray data structure ptr.
** time - variable for working with system time required for FPS.
** distance - ray lenght;
** wall_height - что-то связанное с размером стены.
*/
typedef struct		s_cast
{
	t_ray			*ray;
	double			time[2];
	int				step[2];
	double			distance;
	int				wall_height;
}					t_cast;

/*
** Camera / Player data structure.
** pos - player position. (x = 0, y = 1)
** v_dir - direction vector/ point of view. (x = 0, y = 1)
** v_plane - projection plane vector. (x = 0, y = 1)
**
** c_v_dir - changed direction vector/ point of view. (x = 0, y = 1)
** c_v_plane - chenged projection plane vector. (x = 0, y = 1)
** (changed vectors are used for rotation and movement)
**
** depth - drawing depth.
** m_speed - moving speed.
** r_speed - rotation speed.
*/
typedef	struct		s_cam
{
	double			pos[2];
	double			v_dir[2];
	double			v_plane[2];
	double			c_v_plane[2];
	double			c_v_dir[2];
	char			depth;
	float			m_speed;
	float			r_speed;
}					t_cam;

/*
** Main struct with all another structures and environment data;
** (like window ptr, img ptr etc)
** mlx - x window connection ptr.
** win - window ptr.
** img - main image ptr(used for rendering)
** bts_pr_pxl, sz_ln, endian not used, but that needed to mlx.
** map - map data structure.
** tex - texture data structure.
** cam - cam/player data structure.
** cast - raycast(a part of rendering) data structure.
** cntrls - controls data structure.
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
	t_tex			*tex;
	t_cam			*cam;
	t_cast			*cast;
	t_cntrls		*cntrls;
}					t_env;

/*
** Data init functions
*/
void		read_map(const char *level_name, t_map *map);
t_tex		*tex_init(t_tex *prev, t_tex *next);
t_env		*env_init(t_map *map);
t_map		*map_init();
t_cam		*cam_init();
t_cast		*cast_init();
t_ray		*ray_init();

/*
** Rendering functions
*/
void		renderer(t_env *env);
void		cast_a_ray(t_cast *cast, t_cam *cam, t_env *env);

/*
** control functions
*/
void init_key_hooks(t_env *env);

void load_textures(t_env *env);

#endif
