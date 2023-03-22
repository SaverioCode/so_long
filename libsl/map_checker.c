/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:38:29 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/22 16:46:05 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mandatory_chars(char c, int *ex_pl_col)
{
	if (c == 69)
		ex_pl_col[0] = 1;
	if (c == 80)
		ex_pl_col[1] = 1;
	if (c == 67)
		ex_pl_col[2] = 1;
}

void	ft_map_check_chars(t_map *map)
{
	char	*str;
	int		*ex_pl_col;
	int		i;
	int		j;

	str = "01CEP";
	i = -1;
	ex_pl_col = ft_calloc(3 * 4);
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{	
			if (!ft_strchr(str, map->map[i][j]))
				ft_free_on_error(ft_free_map, map, "Error: forbidden char!\n");
			mandatory_chars(map->map[i][j], ex_pl_col);
		}
	}
	if (!ex_pl_col[0] || !ex_pl_col[1] || !ex_pl_col[2])
		ft_free_on_error(ft_free_map, map, "Error: missing mandatory chars!\n");
	free(ex_pl_col);
}

void	ft_map_check_wall(t_map *map)
{
	int		i;
	char	*error;

	error = "Error: walls settled incorrectly!\n";
	i = -1;
	while (map->map[0][++i])
		if (map->map[0][i] != 49)
			ft_free_on_error(ft_free_map, map, error);
	i = -1;
	while (map->map[map->height - 1][++i])
		if (map->map[map->height - 1][i] != 49)
			ft_free_on_error(ft_free_map, map, error);
	i = -1;
	while (map->map[++i])
		if (map->map[i][0] != 49 || map->map[i][map->width - 1] != 49)
			ft_free_on_error(ft_free_map, map, error);
}

void	ft_map_checker(t_map *map)
{
	int		i;
	char	*error;

	error = "Error: map is not rectangular!\n";
	if (map->height < 3 || map->width < 3 || map->height == map->width)
		ft_free_on_error(ft_free_map, map, error);
	i = 0;
	while (++i < map->height)
		if (ft_strlen(map->map[i]) != ft_strlen(map->map[i - 1]))
			ft_free_on_error(ft_free_map, map, error);
	ft_map_check_wall(map);
	ft_map_check_chars(map);
}
