/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:00:31 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/28 20:23:10 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_flip_images(t_game *game, int image)
{
	t_img	img;

	if (image == 0)
		game->col = mlx_xpm_file_to_image(game->game, \
			"assets/coin/coin_0.xpm", &img.width, &img.heigth);
	else if (image == 1)
		game->col = mlx_xpm_file_to_image(game->game, \
			"assets/coin/coin_1.xpm", &img.width, &img.heigth);
	else if (image == 2)
		game->col = mlx_xpm_file_to_image(game->game, \
			"assets/coin/coin_2.xpm", &img.width, &img.heigth);
	else if (image == 3)
		game->col = mlx_xpm_file_to_image(game->game, \
			"assets/coin/coin_3.xpm", &img.width, &img.heigth);
	else if (image == 4)
		game->col = mlx_xpm_file_to_image(game->game, \
			"assets/coin/coin_4.xpm", &img.width, &img.heigth);
}

void	ft_animation(t_game *game)
{
	static int	image;

	if (game->col_tot == game->col_cnt)
		return ;
	usleep(90000);
	if (game->col)
		mlx_destroy_image(game->game, game->col);
	coin_flip_images(game, image);
	ft_map_reader(game, 67, game->background);
	ft_map_reader(game, 67, game->ground);
	ft_map_reader(game, 67, game->col);
	image++;
	if (image > 4)
		image = 0;
}
