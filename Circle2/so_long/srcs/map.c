/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:36:15 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/18 20:53:47 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_extension(char *file_name)
{
	if (ft_strcmp(file_name + ft_strlen(file_name) - 4, ".ber"))
		ft_return_error("Wrong extension.");
}

static void	ft_count_col_row(t_map *map, char *file_name)
{
	int		fd;
	int		cur_col;
	char	buffer;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_return_error("Map file open failed.");
	cur_col = 0;
	map->col = 0;
	map->row = 0;
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
		{
			if (map->col < cur_col)
				map->col = cur_col;
			cur_col = 0;
			map->row++;
		}
		else
			cur_col++;
	}
	close(fd);
}

static void	ft_set_map(t_map *map, char *file_name)
{
	int		fd;
	int		cur_col;
	int		cur_row;
	char	*line;

	map->map_str = (char *)malloc(sizeof(char) * (map->col * map->row + 1));
	if (!map->map_str)
		ft_return_error("Allocation failed.");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_return_error("Map file open failed.");
	map->map_str[map->col * map->row] = '\0';
	cur_row = 0;
	while (cur_row < map->row)
	{
		line = ft_get_next_line(fd);
		line = ft_strrepl(line, '\n', '\0');
		cur_col = 0;
		while (cur_col < ft_strlen(line))
		{
			map->map_str[cur_row * map->col + cur_col] = line[cur_col];
			cur_col++;
		}
		cur_row++;
	}
}

static void	ft_check_components(char *map_str)
{
	int	idx;
	int	exit;
	int	collectible;
	int	player;

	idx = 0;
	exit = 0;
	collectible = 0;
	player = 0;
	while (map_str[idx])
	{
		if (map_str[idx] == 'E')
			exit++;
		else if (map_str[idx] == 'C')
			collectible++;
		else if (map_str[idx] == 'P')
			player++;
		else if (map_str[idx] != '1' && map_str[idx] != '0')
			ft_return_error("Map contains invalid value.");
		idx++;
	}
	if (!exit || !collectible || !player)
		ft_return_error("Map must have at least one exit(E)," \
			" one collectible(C), and one starting position(P).");
}

static void	ft_check_rectangle(t_map *map)
{
	if (ft_strlen(map->map_str) != map->col * map->row)
		ft_return_error("Map must be rectangular.");
}

static void	ft_check_wall(t_map *map)
{
	int	cur_col;
	int	cur_row;

	cur_col = 0;
	while (cur_col < map->col)
	{
		if (map->map_str[cur_col] != '1'
			|| map->map_str[(map->row - 1) * map->col + cur_col] != '1')
			ft_return_error("Map must be closed by walls.");
		cur_col++;
	}
	cur_row = 0;
	while (cur_row < map->row)
	{
		if (map->map_str[cur_row * map->col] != '1'
			|| map->map_str[cur_row * map->col + (map->col - 1)] != '1')
			ft_return_error("Map must be closed by walls.");
		cur_row++;
	}
}

void	ft_init_map(t_map *map, char *file_name)
{
	ft_check_extension(file_name);
	ft_count_col_row(map, file_name);
	ft_set_map(map, file_name);
	ft_check_rectangle(map);
	ft_check_components(map->map_str);
	ft_check_wall(map);
}
