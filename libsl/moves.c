/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:00:25 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/26 17:07:44 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_game *game, t_map *map, int x, int y)
{
	if (map->map[map->player_y + y][map->player_x + x] == 48)
		return ;
	game->counter++;
	map->player_x += x;
	map->player_y += y;
	mlx_put_image_to_window(game->game, game->win, game->player,
		map->player_x * 50, map->player_y * 50);
	ft_print_sprite(game, map, map->player_x - x, map->player_y - y);
}

void	ft_key_hook(int key, t_game *game, t_map *map)
{
	if (key == 2 || key == 124)
		ft_move(game, map, 1, 0);
	else if (key == 0 || key == 123)
		ft_move(game, map, -1, 0);
	else if (key == 13 || key == 126)
		ft_move(game, map, 0, 1);
	else if (key == 1 || key == 125)
		ft_move(game, map, 0, -1);
}
