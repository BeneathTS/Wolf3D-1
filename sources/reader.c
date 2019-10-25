#include "wolf3d.h"

static void get_map_size(const char *level_name, t_map *map)
{
	int fd;
	char *buf;
	int width;
	int status;

	if ((fd = open(level_name, O_RDONLY)) == -1)
		exit(-1);
	while ((status = get_next_line(fd, &buf)) > 0)
	{
		width = 0;
		++map->height;
		while (buf[width])
			width++;
		if ((width != map->width && map->width != 0) || width == 0)
			exit (-1);
		else if (map->width != width)
			map->width = width;
		free(buf);
	}
	free(buf);
	if (status == -1)
		exit (-1);
	close(fd);
}

static void init_level_buf(t_map *map)
{
	if (map->level)
		free(map->level);
	if (!(map->level = (char**)malloc(sizeof(char*) * (map->height + 1))))
		exit(-1);
	map->level[map->height] = NULL;
}

static void get_map_data(const char *level_name, t_map *map)
{
	int fd;
	int ct;
	int status;
	char *buf;

	if ((fd = open(level_name, O_RDONLY)) == -1)
		exit(-1);
	ct = -1;
	while ((status = get_next_line(fd, &buf)) > 0)
	{
		map->level[++ct] = ft_strdup(buf);
		free(buf);
	}
	free(buf);
	if (status == -1)
		exit (-1);
	close(fd);
}

void read_map(const char *level_name, t_map *map)
{
	get_map_size(level_name, map);
	init_level_buf(map);
	get_map_data(level_name, map);
}