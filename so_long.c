/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:02:42 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/23 21:25:28 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_game	game;
	t_img	img;
	
	ft_check_input(ac, av);
	ft_map_handler(av[1], &map);
	game.game = mlx_init();
	game.win = mlx_new_window(game.game, map.width * 50, map.height * 50, "SO_LONG"); /// to modify
	map_printer(&game, &map, &img);
	mlx_loop(game.game);
}
