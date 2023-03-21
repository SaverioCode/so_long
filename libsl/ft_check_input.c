/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:47:55 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/21 15:27:17 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_format(char *map, size_t map_l)
{
	char	*format;
	int		i;

	format = ".bar";
	i = 3;
	while (i >= 0)
	{
		if (map[map_l] != format[i])
			return (0);
		i--;
		map_l--;
	}
	return (1);
}

void	ft_check_input(int ac, char **av)
{
	char	*map;
	size_t	map_l;

	if (ac != 2)
		ft_error("Error: missing map!\n");
	map = av[1];
	map_l = ft_strlen(map);
	if (map_l < 5 || !ft_map_format(map, map_l))
		ft_error("Error: wrong map format!\n");
}
