/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:10:32 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/11 18:00:36 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkmate(const char c, va_list ap)
{
	int		count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, const char *));
	else if (c == 'p')
	{
		count += ft_putstr("0x");
		count += ft_hexadecimal(va_arg(ap, unsigned long));
	}
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x')
		count += ft_hex(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
		count += ft_hex(va_arg(ap, unsigned int), 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			count;
	int			i;

	va_start(ap, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_checkmate(s[i], ap);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}

/*int main()
{
	int x = '%';
	ft_printf("%%", x);
}*/
