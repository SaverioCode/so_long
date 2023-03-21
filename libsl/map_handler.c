/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:36:31 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/21 16:56:17 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_checker()
{
	
}

void	ft_map_allocate(int	fd)
{
	t_map	*map;
	int		i;

	map->map = ft_malloc((map->height + 1) * 8);
	i = 0;
	while (i < map->heigth)
	{
		map->map[i] = get_next_line(fd);
		map->map[i][ft_strlen(map->map[i])] = 0;
		i++; 
	}
	map->map[i] = NULL;
}

void	ft_map_reader()
{
	t_map	*map; /// check if it's ok
	int		fd;
	char	*line;

	map->height = 0;
	fd = open(map, O_RDONLY);
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
	ft_map_allocate(fd);
	map->width = ft_strlen(map->map[0]);
	close(fd);
}
