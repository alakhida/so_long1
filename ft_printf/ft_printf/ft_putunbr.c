/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:20:58 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/12 17:25:25 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int x)
{
	int		count;

	count = 0;
	if (x >= 10)
	{
		count += ft_putunbr(x / 10);
		x = x % 10;
	}
	if (x < 10)
		count += ft_putchar(x + 48);
	return (count);
}
/*
#include <stdio.h>

int main ()
{
	printf("%d", ft_putunbr(455));
}*/
