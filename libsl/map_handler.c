/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:36:31 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/22 16:38:45 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_allocate(char *map_path, t_map *map)
{
	int		i;
	int		fd;

	map->map = ft_calloc((map->height + 1) * 8);
	fd = open(map_path, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		map->map[i] = get_next_line(fd);
		map->map[i][ft_strlen(map->map[i]) - 1] = 0;
		i++;
	}
	close(fd);
	map->map[i] = NULL;
}

void	ft_map_handler(char *map_path, t_map *map)
{
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
	ft_map_allocate(map_path, map);
	map->width = ft_strlen(map->map[0]);
	ft_map_checker(map);
}