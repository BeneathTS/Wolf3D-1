#include "wolf3d.h"

t_cam *cam_init()
{
	t_cam *cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		exit (-1);
	cam->depth = 5;
	cam->dir[X] = -1.0;
	cam->dir[Y] = 0.0;
	cam->plane[X] = 0.0;
	cam->plane[Y] = 0.66;
	cam->x = 3;
	cam->y = 3;
	return (cam);
}

t_map *map_init()
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit (-1);
	map->width = 0;
	map->height = 0;
	map->level_id = 0;
	map->level = NULL;
	return (map);
}

t_casting *cast_init()
{
	t_casting *cast;

	if (!(cast = (t_casting*)malloc(sizeof(t_casting))))
		exit (-1);
	cast->time[OLD] = 0.0;
	cast->time[NEW] = 0.0;
	return (cast);
}