/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:02:54 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/22 16:39:06 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}	t_map;

void	ft_error(char *str);
void	ft_free_on_error(void ft_free(), void *par, char *error);
void	ft_free_map(t_map *map);
size_t	ft_strlen(char *str);
void	ft_check_input(int ac, char **av);
void	*ft_calloc(size_t bytes);
void	ft_map_handler(char *map_path, t_map *map);
void	ft_map_checker(t_map *map);

#endif