/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:16:59 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/04 19:20:06 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "so_long.h"

void	init_images(t_map *map)
{
	int		width;
	int		heigth;

	map->floor = mlx_xpm_file_to_image(map->mlx.mlx,
			"./imgs/floor_2.xpm", &width, &heigth);
	map->wall = mlx_xpm_file_to_image(map->mlx.mlx,
			"./imgs/wall_1.xpm", &width, &heigth);
	map->player = mlx_xpm_file_to_image(map->mlx.mlx,
			"./imgs/player.xpm", &width, &heigth);
	map->exit = mlx_xpm_file_to_image(map->mlx.mlx,
			"./imgs/exit.xpm", &width, &heigth);
	map->tokens = mlx_xpm_file_to_image(map->mlx.mlx,
			"./imgs/tokens_2.xpm", &width, &heigth);
}

void	get_win_size(t_map *map)
{
	map->x = ft_strlen(map->blocks[0]) * 50;
	map->j = ft_strlen2d(map->blocks) * 50;
}

void	put_image_to_window(t_map *map, int idx1, int idx2)
{
	if (map->blocks[idx1][idx2] == '1')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->wall, idx2 * 50, idx1 * 50);
	else if (map->blocks[idx1][idx2] == '0')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->floor, idx2 * 50, idx1 * 50);
	else if (map->blocks[idx1][idx2] == 'P')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->player, idx2 * 50, idx1 * 50);
	else if (map->blocks[idx1][idx2] == 'E')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->exit, idx2 * 50, idx1 * 50);
	else if (map->blocks[idx1][idx2] == 'C')
		mlx_put_image_to_window(map->mlx.mlx,
			map->mlx.mlx_win, map->tokens, idx2 * 50, idx1 * 50);
}

void	draw_map(t_map *map)
{
	int		idx1;
	int		idx2;

	idx1 = 0;
	while (map->blocks[idx1])
	{
		idx2 = 0;
		while (map->blocks[idx1][idx2])
		{
			put_image_to_window(map, idx1, idx2);
			idx2++;
		}
		idx1++;
	}
}
