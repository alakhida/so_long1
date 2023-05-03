/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:22:33 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/11 18:02:12 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int			ft_putstr(const char *s);
int			ft_putchar(char c);
int			ft_printf(const char *s, ...);
int			ft_hexadecimal(unsigned long s);
int			ft_hex(unsigned int s, int isupper);
int			ft_putnbr(long x);
int			ft_putunbr(unsigned int x);

#endif
