/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:02:54 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/21 16:46:45 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <mlx.h>
# include <fctnl.h>
# include "get_next_line/get_next_line.h"

typedef struct s_map
{
	char	**map;
	size_t	height;
	size_t	width;
}	t_map;

void	ft_error(char *str);
size_t	ft_strlen(char *str);
void	ft_check_input(int ac, char **av);
void	*ft_malloc(int bytes);

#endif