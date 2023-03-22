/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:44:59 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/22 14:45:19 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t bytes)
{
	void	*var;
	char	*tmp;
	size_t	i;

	var = malloc(bytes);
	if (!var)
		exit(0);
	tmp = (char *)var;
	i = 0;
	while (i < bytes)
	{
		tmp[i] = 0;
		i++;
	}
	return (var);
}
