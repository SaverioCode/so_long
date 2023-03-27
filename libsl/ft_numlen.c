/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarzi-c <fgarzi-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:32:42 by fgarzi-c          #+#    #+#             */
/*   Updated: 2023/03/27 18:43:47 by fgarzi-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(long long num, int base)
{
	int	counter;

	counter = 0;
	if (num < 0 && ++counter)
		num *= -1;
	while (num > 0 && ++ counter)
		num = num / base;
	return (counter);
}
