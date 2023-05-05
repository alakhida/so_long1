/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:51:23 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/05 22:30:52 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

int	quit(void)
{
	exit(1);
}

void	put_win(t_map	*map)
{
	map->blocks = ft_split(map->map_holder, '\n');
	map->mlx.mlx = mlx_init();
	init_images(map);
	get_win_size(map);
	map->mlx.mlx_win = mlx_new_window(map->mlx.mlx, map->x, map->j, "so_long");
	draw_map(map);
	mlx_key_hook(map->mlx.mlx_win, move, map);
	mlx_hook(map->mlx.mlx_win, 17, 0L, quit, NULL);
	mlx_loop(map->mlx.mlx);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (!check_file(av[1]))
		return (1);
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
