#include "wolf3d.h"

t_cam *cam_init()
{
	t_cam *cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		exit (-1);
	cam->pos[X] = 1.05;
	cam->pos[Y] = 1.05;
	cam->v_dir[X] = 1;
	cam->v_dir[Y] = 0;
	cam->v_plane[X] = 0.0;
	cam->v_plane[Y] = 0.66;
	cam->c_v_dir[X] = cam->v_dir[X];
	cam->c_v_dir[Y] = cam->v_dir[Y];
	cam->c_v_plane[X] = cam->v_plane[X];
	cam->c_v_plane[Y] = cam->v_plane[Y];
	cam->depth = 5;
	return (cam);
}

t_map *map_init()
{
	t_map *map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit (-1);
	map->width = 0;
	map->height = 0;
	map->level = NULL;
	return (map);
}

t_ray *ray_init()
{
	t_ray *ray;

	if (!(ray =(t_ray*)malloc(sizeof(t_ray))))
		exit (-1);
	return (ray);
}

t_cast *cast_init()
{
	t_cast *cast;

	if (!(cast = (t_cast*)malloc(sizeof(t_cast))))
		exit (-1);
	cast->time[OLD] = 0;
	cast->time[NEW] = 0;
	cast->ray = ray_init();
	return (cast);
}
