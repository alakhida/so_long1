/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:41:25 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/05 22:52:19 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

void	check_map(int ac, char *av, t_map *map)
{
	int		line;
	int		col;

	(void)ac;
	line = 0;
	while (map->blocks[line])
	{
		col = 0;
		while (map->blocks[line][col])
		{
			check_pce01(map);
			check_pce(av, map);
			col++;
		}
		line++;
	}
	if (map->count_p == 0 || map->count_p > 1)
		print_errors(4);
	else if (map->count_c < 1)
		print_errors(5);
	else if (map->count_e != 1)
		print_errors(6);
	free2d(map->blocks);
}

int	check_map_and_pce(t_map *map, char *path, int ac)
{
	ft_rectangular_check(path);
	check_map(ac, path, map);
	check_new_line(map->map_holder);
	if (!issurroundedbywalls(path, map))
		print_errors(1);
	check_path(path);
	return (1);
}

void	splitted_map(t_map *map, char *path)
{
	map->map_holder = read_map(path);
	map->blocks = ft_split(map->map_holder, '\n');
	free(map->map_holder);
}
