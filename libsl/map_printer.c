/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:26:47 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/22 18:58:46 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_imgs(t_game *game, t_img *img, t_map *map)
{
	img->width = 1;
	img->heigth = 1;
	game->wall = mlx_xpm_file_to_image(game->game, "assets/wall1.xpm", &img->width, &img->heigth);
	game->player = mlx_xpm_file_to_image(game->game, , &img->width, &img->heigth);
	game->ground = mlx_xpm_file_to_image(game->game, , &img->width, &img->heigth);
	game->col = mlx_xpm_file_to_image(game->game, , &img->width, &img->heigth);
	game->exit = mlx_xpm_file_to_image(game->game, , &img->width, &img->heigth);
	if (!game->wall || !game->player || !game->col || !game->exit)
		ft_free_on_error(ft_free_map, map, "Error: asset not working!\n");
}

void	map_printer(t_game *game, t_map *map, t_img *img)
{
	int	x;
	int	y;

	initialize_imgs(game, img, map);
	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] == 49)
				mlx_put_image_to_window(game->game, game->win, game->wall, x * 50, y * 50);
			else if (map->map[y][x] == 48)
				mlx_put_image_to_window(game->game, game->win, game->ground, x * 50, y * 50);
			else if (map->map[y][x] == 80)
				mlx_put_image_to_window(game->game, game->win, game->player, x * 50, y * 50);
			else if (map->map[y][x] == 69)
				mlx_put_image_to_window(game->game, game->win, game->exit, x * 50, y * 50);
			else if (map->map[y][x] == 67)
				mlx_put_image_to_window(game->game, game->win, game->col, x * 50, y * 50);
		}
	}
}
