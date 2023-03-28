/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:00:31 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/28 17:27:21 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_flip_images(t_game *game, int image)
{
	t_img	img;

	if (image == 0)
		game->col = (game->game, \
			"assets/coin/coin_0.xmp", &img.width, &img.heigth);
	if (image == 1)
		game->col = mlx_xpm_file_to_image(game->game, \
			"assets/coin/coin_1.xmp", &img.width, &img.heigth);
}

void	map_reader(t_game *game)
{
	int	y;
	int	x;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 67)
				mlx_put_image_to_window(game->game, game->win, \
					game->col, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	ft_animation(t_game *game)
{
	int	image;
	int	time;

	if (game->col_tot == game->col_cnt)
		return ;
	time = 0;
	image = 0;
	while (time < 2000)
		time++;
	if (game->col)
		mlx_destroy_image(game->game, game->col);
	coin_flip_images(game, image);
	map_reader(game);
	image++;
}
