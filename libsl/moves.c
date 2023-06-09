/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:00:25 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/28 20:35:03 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_move(t_game *game, int x, int y)
{
	if (x > 0)
		game->player = game->player_right;
	else if (x < 0)
		game->player = game->player_left;
	else if (y > 0)
		game->player = game->player_down;
	else if (y < 0)
		game->player = game->player_up;
	if (game->map[game->player_y][game->player_x] != 50)
		mlx_put_image_to_window(game->game, game->win, game->player,
			game->player_x * 50, game->player_y * 50);
}

void	ft_new_position(t_game *game, int x, int y)
{
	t_img	img;

	if (game->map[y][x] == 67)
	{	
		game->map[y][x] = 48;
		game->col_cnt++;
		ft_print_sprite(game, x, y);
		if (game->col_cnt == game->col_tot)
		{
			mlx_destroy_image(game->game, game->exit);
			game->exit = mlx_xpm_file_to_image(game->game, \
				"assets/exit_1.xpm", &img.width, &img.heigth);
			ft_map_reader(game, 69, game->background);
			ft_map_reader(game, 69, game->exit);
		}
	}
	else if (game->map[y][x] == 69 && game->col_tot == game->col_cnt)
		ft_game_over(game, "YOU WON!\n");
	else if (game->map[y][x] == 50)
		ft_game_over(game, "YOU LOST!\n");
}

void	ft_move(t_game *game, int x, int y)
{	
	char	*game_cnt;

	if (game->map[game->player_y + y][game->player_x + x] == 49)
		return ;
	game->mv_cnt++;
	game->player_x += x;
	game->player_y += y;
	ft_print_sprite(game, 0, 0);
	game_cnt = ft_itoa(game->mv_cnt);
	mlx_string_put(game->game, game->win, 15, 15, 0, game_cnt);
	free(game_cnt);
	ft_new_position(game, game->player_x, game->player_y);
	ft_player_move(game, x, y);
	ft_print_sprite(game, game->player_x - x, game->player_y - y);
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
	else if (key == 12 || key == 53)
		ft_close_game(game);
}
