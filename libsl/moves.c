/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:00:25 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/27 14:49:18 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_position(t_game *game, int x, int y)
{
	if (game->map[y][x] == 67)
	{	
		game->map[y][x] == 48;
		game->col_cnt++;
		ft_print_sprite(game, x, y);
	}
	// else if ()	
}


void	ft_old_postition(t_game *game, int x, int y)
{
	// if (game->map[y][x] == 67)
	// {
	// 	mlx_put_image_to_window(game->game, game->win, game->background, x * 50, y * 50);
	// 	mlx_put_image_to_window(game->game, game->win, game->ground, x * 50, y * 50);
	// }
	// else
		ft_print_sprite(game, x, y);
}

void	ft_move(t_game *game, int x, int y)
{	
	if (game->map[game->player_y + y][game->player_x + x] == 49)
		return ;
	game->mv_cnt++;
	game->player_x += x;
	game->player_y += y;
	ft_new_position(game, game->player_x, game->player_y);
	mlx_put_image_to_window(game->game, game->win, game->player,
		game->player_x * 50, game->player_y * 50);
	ft_old_postition(game, game->player_x - x, game->player_y - y);
}

void	ft_key_hook(int key, t_game *game)
{
	if (key == 2 || key == 124)
		ft_move(game, 1, 0);
	else if (key == 0 || key == 123)
		ft_move(game, -1, 0);
	else if (key == 1 || key == 125)
		ft_move(game, 0, 1);
	else if (key == 13 || key == 126)
		ft_move(game, 0, -1);
}
