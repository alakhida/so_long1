/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:09:17 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/05 22:55:38 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

size_t	ft_strlen2d(char **strs)
{
	size_t	counter;

	counter = 0;
	while (strs[counter])
		counter++;
	return (counter);
}

void	free2d(char **strs)
{
	size_t	counter;

	counter = 0;
	while (strs[counter])
		free(strs[counter++]);
	free(strs);
}

void	pos_to_dim(t_map *map, unsigned int position)
{
	unsigned int		idx;
	unsigned int		y_idx;
	unsigned int		x_idx;

	idx = 0;
	y_idx = 0;
	x_idx = 0;
	while (map->map_holder[idx])
	{
		if (idx == position)
			break ;
		if (map->map_holder[idx] == '\n')
		{
			y_idx++;
			x_idx = -1;
		}
		idx++;
		x_idx++;
	}
	map->player_x = x_idx;
	map->player_y = y_idx;
}

unsigned int	dim_to_pos(char *map, size_t player_x, size_t player_y)
{
	size_t	idx;
	size_t	y_idx;

	idx = 0;
	y_idx = 0;
	while (map[idx])
	{
		if (map[idx] == '\n')
			y_idx++;
		if (y_idx == player_y)
			break ;
		idx++;
	}
	return (idx + player_x + 1);
}

char	*read_map(char *path)
{
	t_map	map;
	ssize_t	byte;

	map.buffer = malloc(2);
	map.str = NULL;
	map.fd = open(path, O_RDWR);
	while (1)
	{
		byte = read(map.fd, map.buffer, 1);
		map.buffer[1] = '\0';
		if (byte == 0)
			break ;
		map.str = ft_strjoin(map.str, map.buffer);
	}
	if (!map.str)
		print_errors(10);
	close (map.fd);
	free(map.buffer);
	return (map.str);
}
