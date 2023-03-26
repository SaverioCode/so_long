/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:02:42 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/26 19:35:40 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl/so_long.h"

int	main(int ac, char **av)
{
	// t_map	map;
	t_game	game;
	t_img	img;
	
	ft_check_input(ac, av);
	ft_map_handler(av[1], &game);
	game.counter = 0;
	game.game = mlx_init();
	game.win = mlx_new_window(game.game, game.width * 50, game.height * 50, "SO_LONG"); /// to modify
	map_printer(&game, &img);
	mlx_key_hook(game.win, (void *)ft_key_hook, &game);
	mlx_loop(game.game);
}
