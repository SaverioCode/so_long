/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:02:54 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/27 19:34:54 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>
# include "get_next_line/get_next_line.h"

typedef struct s_game
{
	void	*game;
	void	*win;
	char	**map;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		enemy_x;
	int		enemy_y;
	void	*player;
	int		mv_cnt;
	void	*enemy;
	void	*col;
	int		col_tot;
	int		col_cnt;
	void	*exit;
	void	*wall;
	void	*ground;
	void	*background;
}	t_game;

typedef struct s_img
{
	int	width;
	int heigth;
}	t_img;

void	ft_error(char *str);
void	ft_free_on_error(void ft_free(), void *par, char *error);
void	ft_free_map(t_game *map);
void	ft_free_imgs(t_game *game);
size_t	ft_strlen(char *str);
void	ft_check_input(int ac, char **av);
void	*ft_calloc(size_t bytes);
void	ft_map_handler(char *map_path, t_game *map);
void	ft_map_checker(t_game *map);
void	map_printer(t_game *game, t_img *img);
void	ft_print_sprite(t_game *game, int x, int y);
void	ft_print_bckground_ground(t_game *game, int x, int y);
void	ft_key_hook(int key, t_game *game);
void	ft_close_game(t_game *game);
int		ft_numlen(long long num, int base);
char	*ft_itoa(long long num);

#endif