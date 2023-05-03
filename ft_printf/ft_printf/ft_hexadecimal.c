/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:44:32 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/11 17:46:34 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned long s)
{	
	char	*a;
	int		b;

	b = 0;
	a = "0123456789abcdef";
	if (s < 16)
	{
		b += write(1, &a[s], 1);
	}
	else
	{
		b += ft_hexadecimal(s / 16);
		b += ft_hexadecimal(s % 16);
	}
	return (b);
}

/*#include<stdlib.h>
int main(int ac, char **av)
{
	int i = atoi(av[1]);
	ft_hexadecimal(i);
	return (0);
}*/
