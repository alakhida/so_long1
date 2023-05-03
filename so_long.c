/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:51:23 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/03 16:48:32 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "./libft/libft.h"

int main(int ac, char **av)
{
    t_map map;
	
	if (ac != 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
    splitted_map(&map, av[1]);
    if (check_map_and_pce(&map, av[1], ac) == 0)
        exit (0);	
	put_win(&map);
	free(map.map_holder);
	free2d(map.blocks);
	return (0);
}