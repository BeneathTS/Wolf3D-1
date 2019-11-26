/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:27:00 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/26 06:12:20 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <SDL.h>
# include <SDL_mixer.h>
# include <time.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>
# include <stdint.h>
# include <stdbool.h>

# include "audio.h"
# include "menu.h"
# include "../libft/includes/libft.h"
# include "controls.h"
# include "define_value.h"

/*
** Structure w/ all map data.
** width - map width.
** height - map height.
** level - Buffer to store level.
*/
typedef struct			s_map
{
	int					width;
	int					height;
	char				**level;
}						t_map;

/*
** Struct withh all textures and data what it nedeed.
** tex_id - id of texture
** tex_ptr - texture img pointer
** data - texture data (use this var to get texture, not tex_ptr)
** bts_pr_px, sz_ln, endian not used, but that needed to mlx.
** next - next texture
** prev - previous texture
*/
typedef struct			s_tex
{
	char				id;
	int					width;
	int					height;
	void				*tex_ptr;
	char				*data;
	int					bts_pr_px;
	int					sz_ln;
	int					endian;
	struct s_tex		*next;
	struct s_tex		*prev;
}						t_tex;

/*
** Structure w/ all ray's data.
** v_dir - vector direction. (x = 0, y = 1)
** angle - current ray angle.
** m_pos - ray position on 2D map. (x = 0, y = 1)
** s_dist - distance for first intersection point. (0 = Vert, 1 - Horiznt)
** d_dist - distance between intersection points. (0 = Vert, 1 - Horiznt)
** side - hit side (Vertical or Horizontal);
*/
typedef struct			s_ray
{
	double				v_dir[2];
	double				angle;
	int					m_pos[2];
	double				s_dist[2];
	double				d_dist[2];
	char				side;
}						t_ray;

/*
** Structure w/ all needed data for raycasting.
** ray - ray data structure ptr.
** time - variable for working with system time required for FPS.
** distance - ray lenght;
** wall_height - что-то связанное с размером стены.
*/
typedef struct			s_cast
{
	t_ray				*ray;
	double				time[2];
	int					step[2];
	double				distance;
	int					wall_height;
}						t_cast;

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
typedef	struct			s_cam
{
	double				pos[2];
	double				v_dir[2];
	double				v_plane[2];
	double				c_v_plane[2];
	double				c_v_dir[2];
	char				depth;
	int					view_height;
	float				m_speed;
	float				r_speed;
	t_tex				*weapon;
}						t_cam;

typedef struct			s_lvl_crd
{
	char				id;
	char				*level_name;
	int					pos;
	t_tex				*background;
	unsigned int		font_color;
	struct s_lvl_crd	*next;
	struct s_lvl_crd	*prev;
}						t_lvl_crd;

typedef struct			s_menu_controls
{
	int					v_pos;
	int					m_pos;
	int					r_pos;
	int					s_pos;
	int					d_pos;
	char				scroller_status;
	char				id_first_card;
	char				num_of_cards;
	char				pressed[5];
	int					push_coord;
}						t_menu_controls;

typedef struct			s_menu
{
	int					bg_off[2];
	char				sel_button;
	t_tex				*first_tex[4];
	t_tex				*main;
	t_tex				*chooser;
	t_tex				*settings;
	t_tex				*back_button;
	t_tex				*refresh_button;
	t_lvl_crd			*cards;
	t_menu_controls		*controls;
	struct dirent		*file_name;
	DIR					*dir_ptr;
}						t_menu;

/*
** Main struct with all another structures and environment data;
** (like window ptr, img ptr etc)
** mlx - x window connection ptr.
** win - window ptr.
** img - main image ptr(used for rendering)
** bts_pr_px, sz_ln, endian not used, but that needed to mlx.
** map - map data structure.
** tex - texture data structure.
** cam - cam/player data structure.
** cast - raycast(a part of rendering) data structure.
** cntrls - controls data structure.
*/
typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	int					sz_ln;
	int					endian;
	int					bts_pr_px;
	char				*data_addr;
	char				mode;
	Mix_Music			*music[4];
	int					volume;
	t_map				*map;
	t_tex				*tex;
	t_cam				*cam;
	t_cast				*cast;
	t_menu				*menu;
	t_cntrls			*cntrls;
}						t_env;

/*
**	close.c
*/
int						x_close(t_env *env);

/*
**	get_texture_name.c
*/
char					*get_texture_name(int i, char *arr_id_tex);

/*
**	hooks.c
*/
void					init_key_hooks(t_env *env);

/*
**	init_env.c
*/
t_env					*env_init(t_map *map);

/*
**	init_game_data.c
*/
t_tex					*tex_init(t_tex *prev, t_tex *next);
t_cam					*cam_init();
t_map					*map_init();
t_ray					*ray_init();
t_cast					*cast_init();

/*
**	level_chooser.c
*/

/*
**	load_textures.c
*/
void					load_textures(t_env *env);

/*
**	menu_controls.c
*/
void					bg_paralax(int x, int y, t_env *env);
void					menu_push_buttons(int x, int y, t_env *env);
void					menu_controls(int x, int y, t_env *env);

/*
**	menu_data_load.c
*/
void					load_menu_data(t_env *env);

/*
**	menu.c
*/
void					set_alpha(char *data, int width, int height,
							unsigned int alpha_value);
void					draw_main_menu(t_env *env);

/*
**	mouse_controls.c
*/
int						push_buttons(int button, int x, int y, t_env *env);
int						mouse_move(int x, int y, t_env *env);
int						mouse_release(int button, int x, int y, t_env *env);

/*
**	move.c
*/
void					player_move(int key, t_env *env);

/*
**	music.c
*/
void					init_sdl_music(Mix_Music **music);
void					change_music(int flag, Mix_Music **music);

/*
**	ray_caster.c
*/
void					cast_a_ray(t_cast *cast, t_cam *cam, t_env *env);

/*
**	reader.c
*/
bool					read_map(const char *level_name, t_map *map);

/*
**	renderer.c
*/
void					renderer(t_env *env);

/*
**	settings_controls.c
*/
void					settings_push_buttons(int x, int y, t_env *env);
void					settings_controls(int x, int y, t_env *env);

/*
**	settings_controls.c
*/
void					load_settings_data(t_env *env);

/*
**	settings.c
*/
void					draw_settings(t_env *env);

void draw_chooser(t_env *env);
void chooser_controls(int x, int y, t_env *env);
void load_chooser_data(t_env *env);
void push_scroller(int x, int y, t_env *env);
void check_back_button_select(int x, int y, t_env *env);
void draw_add_buttons(t_env *env);
void check_push_add_buttons(int x, int y, t_env *env);
void load_back_button(t_env *env);
void load_refresh_button(t_env *env);
void read_map_files(t_env *env);
void load_weapon_texture(t_env *env);
#endif
