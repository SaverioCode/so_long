/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:36:31 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/22 13:18:00 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check_chars(t_map *map)
{
	char	*str;
	int		col;
	int		player;
	int		exit;
	int		i;

	str = "01CEP";
	i = -1;
	while (map->map[++i])
	{
		while (*map->map[i])
		{	
			if (!ft_strchr(str, *map->map[i]))
				ft_free_on_error(ft_free_map, "Error: forbidden char!\n");
			if (*map->map[i] == 69)
				exit = 1;
			if (*map->map[i] == 80)
				player = 1;
			if (*map->map[i] == 67)
				col = 1;
			map->map[i]++;
		}
	}
	if (!col || !player || !exit)
		ft_free_on_error(ft_free_map, "Error: missing mandatory chars!\n");
}

void	ft_map_check_wall(void)
{
	t_map	*map;
	int		i;

	i = -1;
	while (map->map[0][++i])
		if (map->map[0][i] != 49)
			ft_free_on_error(ft_free_map, "Error: walls settled incorrectly!\n");
	i = -1;
	while (map->map[map->height][++i])
		if (map->map[map->height][i] != 49)
			ft_free_on_error(ft_free_map, "Error: walls settled incorrectly!\n");
	i = -1;
	while (map->map[++i])
		if (map->map[i][0] != 49 || map->map[i][map->width] != 49)
			ft_free_on_error(ft_free_map, "Error: walls settled incorrectly!\n");
}

void	ft_map_checker(void)
{
	t_map	*map;
	int		i;

	if (map->height < 3 || map->width < 3 || map->height == map->width)
		ft_free_on_error(ft_free_map, "Error: map is not rectangular!\n");
	i = 0;
	while (++i < map->height)
		if (ft_strlen(map->map[i]) != ft_strlen(map->map[i - 1]))
			ft_free_on_error(ft_free_map, "Error: map is not rectangular!\n");
	ft_map_check_wall();
	ft_map_check_chars(map);
}

void	ft_map_allocate(char *map_path)
{
	t_map	*map;
	int		i;
	int		fd;

	map->map = ft_calloc((map->height + 1) * 8);
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		map->map[i] = get_next_line(fd);
		map->map[i][ft_strlen(map->map[i])] = 0;
		i++;
	}
	close(fd);
	map->map[i] = NULL;
}

void	ft_map_handler(char *map_path)
{
	t_map	*map;
	int		fd;
	char	*line;

	map->height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_error("Error: map not found!\n");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->height++;
		free(line);
	}
	close(fd);
	ft_map_allocate(map_path);
	map->width = ft_strlen(map->map[0][0]);
	ft_map_checker();
}
