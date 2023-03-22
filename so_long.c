/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:02:42 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/22 14:46:58 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsl/so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	void	*mlx;
	void	*mlx_win;

	ft_check_input(ac, av);
	mlx = mlx_init();
	ft_map_handler(av[1], &map);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "SO_LONG");
	mlx_loop(mlx);
}
