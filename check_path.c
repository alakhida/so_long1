/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:45:41 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/04 17:10:23 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

char	get_char(char *map, int position)
{
	int		idx;

	idx = 0;
	while (map[idx])
	{
		if (idx == position)
			return (map[idx]);
		idx++;
	}
	return (0);
}

int	get_position(char *map, char c)
{
	int		idx;

	idx = 0;
	while (map[idx])
	{
		if (map[idx] == c)
			return (idx);
		idx++;
	}
	return (-1);
}

int	start_checking_path(char *map, int player_x, int player_y)
{
	int		selected_pos;

	map[dim_to_pos(map, player_x, player_y)] = 'P';
	selected_pos = dim_to_pos(map, player_x + 1, player_y);
	if (map[selected_pos] == '0' || map[selected_pos] == 'C')
		start_checking_path(map, player_x + 1, player_y);
	selected_pos = dim_to_pos(map, player_x, player_y - 1);
	if (map[selected_pos] == '0' || map[selected_pos] == 'C')
		start_checking_path(map, player_x, player_y - 1);
	selected_pos = dim_to_pos(map, player_x - 1, player_y);
	if (map[selected_pos] == '0' || map[selected_pos] == 'C')
		start_checking_path(map, player_x - 1, player_y);
	selected_pos = dim_to_pos(map, player_x, player_y + 1);
	if (map[selected_pos] == '0' || map[selected_pos] == 'C')
		start_checking_path(map, player_x, player_y + 1);
	return (0);
}

void	check_exit(t_map map)
{
	if (get_char(map.map_holder,
			dim_to_pos(map.map_holder, map.player_x + 1, map.player_y)) != 'P'
		&& get_char(map.map_holder,
			dim_to_pos(map.map_holder, map.player_x, map.player_y - 1)) != 'P'
		&& get_char(map.map_holder,
			dim_to_pos(map.map_holder, map.player_x - 1, map.player_y)) != 'P'
		&& get_char(map.map_holder,
			dim_to_pos(map.map_holder, map.player_x, map.player_y + 1)) != 'P')
		print_errors(7);
}

int	check_path(char *path)
{
	t_map	map;
	int		playerpos;
	int		dor_pos;

	map.map_holder = read_map(path);
	playerpos = get_position(map.map_holder, 'P');
	pos_to_dim(&map, playerpos);
	start_checking_path(map.map_holder, map.player_x, map.player_y);
	if (get_position(map.map_holder, 'C') != -1)
		print_errors(8);
	dor_pos = get_position(map.map_holder, 'E');
	pos_to_dim(&map, dor_pos);
	check_exit(map);
	free(map.map_holder);
	return (1);
}
