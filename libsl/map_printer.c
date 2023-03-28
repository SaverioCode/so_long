/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:26:47 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/28 18:23:14 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_print_bckground_ground(t_game *game, int x, int y)
// {
// 	mlx_put_image_to_window(game->game, game->win, \
// 		game->background, x * 50, y * 50);
// 	mlx_put_image_to_window(game->game, game->win, \
// 		game->ground, x * 50, y * 50);
// }

void	characters_imgs(t_game *game, t_img *img)
{
	game->player_right = mlx_xpm_file_to_image(game->game, \
		"assets/player/player_r.xpm", &img->width, &img->heigth);
	game->player_left = mlx_xpm_file_to_image(game->game, \
		"assets/player/player_l.xpm", &img->width, &img->heigth);
	game->player_up = mlx_xpm_file_to_image(game->game, \
		"assets/player/player_u.xpm", &img->width, &img->heigth);
	game->player_down = mlx_xpm_file_to_image(game->game, \
		"assets/player/player_d.xpm", &img->width, &img->heigth);
	game->enemy_r = mlx_xpm_file_to_image(game->game, \
		"assets/enemy/enemy_r.xpm", &img->width, &img->heigth);
	game->enemy_l = mlx_xpm_file_to_image(game->game, \
		"assets/enemy/enemy_l.xpm", &img->width, &img->heigth);
}

void	initialize_imgs(t_game *game, t_img *img)
{
	game->background = mlx_xpm_file_to_image(game->game, \
		"assets/background.xpm", &img->width, &img->heigth);
	game->ground = mlx_xpm_file_to_image(game->game, \
		"assets/ground.xpm", &img->width, &img->heigth);
	game->wall = mlx_xpm_file_to_image(game->game, \
		"assets/wall.xpm", &img->width, &img->heigth);
	game->col = mlx_xpm_file_to_image(game->game, \
		"assets/col.xpm", &img->width, &img->heigth);
	game->exit = mlx_xpm_file_to_image(game->game, \
		"assets/exit_0.xpm", &img->width, &img->heigth);
	characters_imgs(game, img);
	game->player = game->player_down;
	game->enemy = game->enemy_r;
	if (!game->wall || !game->player || !game->col || !game->exit)
		ft_free_on_error(ft_free_map, game, "Error: asset not working!\n");
	else if (!game->background || !game->enemy)
		ft_free_on_error(ft_free_map, game, "Error: asset not working!\n");
}

void	ft_print_sprite(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->game, game->win, \
		game->background, x * 50, y * 50);
	if (game->map[y][x] == 49)
		mlx_put_image_to_window(game->game, game->win, \
			game->wall, x * 50, y * 50);
	else if (game->map[y][x] == 48)
		mlx_put_image_to_window(game->game, game->win, \
			game->ground, x * 50, y * 50);
	else if (game->map[y][x] == 80 \
		&& y == game->player_y && x == game->player_x)
		mlx_put_image_to_window(game->game, game->win, \
			game->player, x * 50, y * 50);
	else if (game->map[y][x] == 69)
		mlx_put_image_to_window(game->game, game->win, \
			game->exit, x * 50, y * 50);
	else if (game->map[y][x] == 67)
		mlx_put_image_to_window(game->game, game->win, \
			game->col, x * 50, y * 50);
	else if (game->map[y][x] == 50)
		mlx_put_image_to_window(game->game, game->win, \
			game->enemy, x * 50, y * 50);
}

void	map_printer(t_game *game, t_img *img)
{
	int	x;
	int	y;

	initialize_imgs(game, img);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 80)
			{
				game->player_y = y;
				game->player_x = x;
			}
			if (game->map[y][x] == 67)
				game->col_tot++;
			ft_print_sprite(game, x, y);
			x++;
		}
		y++;
	}
}
