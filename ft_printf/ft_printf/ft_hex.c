/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:15:39 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/11 17:59:28 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int s, int isupper)
{
	char	*c;
	int		count;

	count = 0;
	if (isupper)
		c = "0123456789ABCDEF";
	else
		c = "0123456789abcdef";
	if (s < 16)
	{
		count += write(1, &c[s], 1);
	}
	else
	{
		count += ft_hex(s / 16, isupper);
		count += ft_hex(s % 16, isupper);
	}
	return (count);
}
/* int main(int ac, char **av)
 {
	 int i = atoi(av[1]);
	 ft_hexamaj(i);
	 return (0);
 }*/
