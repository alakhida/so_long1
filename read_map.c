/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:31:45 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/04 20:26:38 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

void	check_new_line(char *map)
{
	int		idx;

	idx = 0;
	while (map[idx])
	{
		if (map[idx] == '\n' && map[idx + 1] == '\n')
			print_errors(1);
		idx++;
	}
}

void	ft_rectangular_check(char *argv)
{
	char	*map;
	char	**map_splited;
	int		idx;
	int		len;

	idx = 0;
	map = read_map(argv);
	map_splited = ft_split(map, '\n');
	len = ft_strlen(map_splited[0]);
	while (map_splited[idx])
	{
		if (ft_strlen(map_splited[idx]) != len)
			print_errors(2);
		idx++;
	}
	free(map);
	free2d(map_splited);
}

void	check_pce01(t_map *map)
{
	int		line;
	int		col;

	line = 0;
	while (map->blocks[line])
	{
		col = 0;
		while (map->blocks[line][col])
		{
			if (map->blocks[line][col] != '0'
			&& map->blocks[line][col] != 'P'
			&& map->blocks[line][col] != '1'
			&& map->blocks[line][col] != 'C'
			&& map->blocks[line][col] != 'E')
				print_errors(9);
				col++;
		}
		line++;
	}
}

void	check_pce(char *path, t_map *map)
{
	map->map_holder = read_map(path);
	map->i = 0;
	map->count_c = 0;
	map->count_e = 0;
	map->count_p = 0;
	while (map->map_holder[map->i])
	{
		if (map->map_holder[map->i] == 'P')
			map->count_p++;
		if (map->map_holder[map->i] == 'C')
			map->count_c++;
		if (map->map_holder[map->i] == 'E')
			map->count_e++;
		map->i++;
	}
	free(map->map_holder);
}

int	issurroundedbywalls(char *path, t_map *map)
{
	map->i = 0;
	map->map_holder = read_map(path);
	map->blocks = ft_split(map->map_holder, '\n');
	map->rows = ft_strlen2d(map->blocks);
	map->cols = ft_strlen(map->blocks[0]);
	while (map->blocks[0][map->i] != '\0')
	{
		if (map->blocks[0][map->i] != '1' ||
			map->blocks[map->rows - 1][map->i] != '1')
			exit (1);
		map->i++;
	}
	map->j = 0;
	while (map->j != '\0')
	{
		if (map->blocks[map->j][0] != '1' ||
			map->blocks[map->j][map->cols - 1] != '1')
			exit (1);
		map->j++;
	}
	return (1);
}
