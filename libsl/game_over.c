/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:42 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/27 19:34:44 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_game(t_game *game)
{
	mlx_clear_window(game->game, game->win);
	ft_free_imgs(game);
	mlx_destroy_window(game->game, game->win);
	ft_free_map(game);
	exit(0);
}
