/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:42 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/28 20:31:18 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_over(t_game *game, char *str)
{
	write(1, str, ft_strlen(str));
	ft_close_game(game);
}

void	ft_close_game(t_game *game)
{
	mlx_clear_window(game->game, game->win);
	mlx_destroy_window(game->game, game->win);
	ft_free_imgs(game);
	ft_free_map(game);
	exit(0);
}
