/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:01:53 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/27 15:42:26 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_imgs(t_game *game)
{
	mlx_destroy_image(game->game, game->background);
	free(game->background);
	mlx_destroy_image(game->game, game->ground);
	free(game->ground);
	mlx_destroy_image(game->game, game->wall);
	free(game->wall);
	mlx_destroy_image(game->game, game->player);
	free(game->player);
	mlx_destroy_image(game->game, game->col);
	free(game->col);
	mlx_destroy_image(game->game, game->exit);
	free(game->exit);
}

void	ft_free_map(t_game *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}
