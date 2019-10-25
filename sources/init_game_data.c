#include "wolf3d.h"

t_cam *cam_init()
{
	t_cam *cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		exit (-1);
	cam->x = 64;
	cam->y = 64;
	cam->height = WALL_SIZE >> 1;
	cam->fov = 60.0;
	cam->depth = 5.0;
	cam->pov = 1.0;
	cam->prj_plane = prj_plane_init(cam);
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
	cast->ray = ray_init();
	return (cast);
}

t_prj_plane *prj_plane_init(t_cam *cam)
{
	t_prj_plane *plane;

	if (!(plane = (t_prj_plane*)malloc(sizeof(t_prj_plane))))
		exit (-1);
	plane->size = WIDTH * HEIGHT;
	plane->mid[X] = (double)WIDTH / 2.0;
	plane->mid[Y] = (double)HEIGHT / 2.0;
	plane->dist = (WIDTH / 2) / tan(cam->fov / 2);
	plane->ray_angle = cam->fov / (double)WIDTH;
	return (plane);
}