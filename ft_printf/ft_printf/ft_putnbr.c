/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:38:15 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/14 16:57:02 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long x)
{
	int	counter;

	counter = 0;
	if (x < 0)
	{
		counter += ft_putchar('-');
		x = -x;
	}
	if (x >= 10)
	{
		counter += ft_putnbr(x / 10);
		x = x % 10;
	}
	if (x < 10)
		counter += ft_putchar(x + 48);
	return (counter);
}
/*int main()
{
	int x = 16;
	ft_putnbr(x);
}*/
