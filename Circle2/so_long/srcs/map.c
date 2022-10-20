/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:18:19 by jikoo             #+#    #+#             */
/*   Updated: 2022/10/20 19:40:56 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	ft_check_file_type(char *file_name)
{
	if (ft_strcmp(file_name + ft_strlen(file_name) - 4, ".ber"))
		ft_print_err_and_exit("Invalid file type, use .ber!");
}

static void	ft_count_col_and_row(t_map *map, char *file_name)
{
	int		fd;
	int		cur_col;
	char	buffer;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_print_err_and_exit("File not found!");
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

static void	ft_set_map(t_map *map, char *file_name, int idx)
{
	int		fd;
	int		cur_col;
	int		cur_row;
	char	*line;

	map->map_str = (char *)malloc(sizeof(char) * (map->col * map->row + 1));
	if (!map->map_str)
		ft_print_err_and_exit("Memory allocation error!");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_print_err_and_exit("File not found!");
	cur_row = 0;
	while (cur_row < map->row)
	{
		line = ft_get_next_line(fd);
		line = ft_strrepl(line, '\n', '\0');
		cur_col = 0;
		while (cur_col < ft_strlen(line))
		{
			map->map_str[idx++] = line[cur_col];
			cur_col++;
		}
		cur_row++;
	}
	map->map_str[idx] = '\0';
}

static void	ft_check_rectangle(t_map *map)
{
	if (ft_strlen(map->map_str) != map->col * map->row)
		ft_print_err_and_exit("Map must be rectangular!");
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
			ft_print_err_and_exit("Unexpected char(s) in map!");
		idx++;
	}
	if (!exit || !collectible || !player)
		ft_print_err_and_exit("Map must have at least one exit(E)," \
			" one collectible(C), and one starting position(P)!");
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
			ft_print_err_and_exit("Map must be surrounded by walls!");
		cur_col++;
	}
	cur_row = 0;
	while (cur_row < map->row)
	{
		if (map->map_str[cur_row * map->col] != '1'
			|| map->map_str[cur_row * map->col + (map->col - 1)] != '1')
			ft_print_err_and_exit("Map must be surrounded by walls!");
		cur_row++;
	}
}

void	ft_init_map(t_map *map, char *file_name)
{
	ft_check_file_type(file_name);
	ft_count_col_and_row(map, file_name);
	ft_set_map(map, file_name, 0);
	ft_check_rectangle(map);
	ft_check_components(map->map_str);
	ft_check_wall(map);
}
