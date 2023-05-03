/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:09:17 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/03 16:51:14 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

size_t ft_strlen2d(char **strs)
{
    size_t counter;

    counter = 0;
    while (strs[counter])
        counter++;
    return (counter);
}

void free2d(char **strs)
{
    size_t counter;

    counter = 0;
    while (strs[counter])
        free(strs[counter++]);
    free(strs);
}


