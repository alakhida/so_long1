/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:19:51 by alakhida          #+#    #+#             */
/*   Updated: 2022/11/03 22:24:32 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	k;
	size_t	lsrc;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (dstsize == 0)
		return (lsrc);
	if (dstsize < ldst)
		lsrc += dstsize;
	else
		lsrc += ldst;
	k = 0;
	while (src[k] != '\0' && (ldst + k) < dstsize - 1)
	{
		dst[ldst + k] = src[k];
		k++;
	}
	dst[ldst + k] = '\0';
	return (lsrc);
}
