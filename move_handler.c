/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:06:43 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/04 20:10:49 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

void	go_left(t_map *map)
{
	int		next_pos;
	int		player_pos;

	if (map->map_holder[get_next_pos(map, -1, 0)] == 'E' && is_done(map))
		exit(0);
	player_pos = get_position(map->map_holder, 'P');
	pos_to_dim(map, player_pos);
	next_pos = dim_to_pos(map->map_holder, map->player_x - 1, map->player_y);
	if (map->map_holder[next_pos] == '1' || map->map_holder[next_pos] == 'E')
		return ;
	map->map_holder[player_pos] = '0';
	map->map_holder[next_pos] = 'P';
	print_step(map);
	free2d(map->blocks);
	map->blocks = ft_split(map->map_holder, '\n');
	draw_map(map);
}

void	go_down(t_map *map)
{
	int		next_pos;
	int		player_pos;

	if (map->map_holder[get_next_pos(map, 0, 1)] == 'E' && is_done(map))
		exit(0);
	player_pos = get_position(map->map_holder, 'P');
	pos_to_dim(map, player_pos);
	next_pos = dim_to_pos(map->map_holder, map->player_x, map->player_y + 1);
	if (map->map_holder[next_pos] == '1' || map->map_holder[next_pos] == 'E')
		return ;
	map->map_holder[player_pos] = '0';
	map->map_holder[next_pos] = 'P';
	print_step(map);
	free2d(map->blocks);
	map->blocks = ft_split(map->map_holder, '\n');
	draw_map(map);
}

void	go_up(t_map *map)
{
	int		next_pos;
	int		player_pos;

	if (map->map_holder[get_next_pos(map, 0, -1)] == 'E' && is_done(map))
		exit(0);
	player_pos = get_position(map->map_holder, 'P');
	pos_to_dim(map, player_pos);
	next_pos = dim_to_pos(map->map_holder, map->player_x, map->player_y - 1);
	if (map->map_holder[next_pos] == '1' || map->map_holder[next_pos] == 'E')
		return ;
	map->map_holder[player_pos] = '0';
	map->map_holder[next_pos] = 'P';
	print_step(map);
	free2d(map->blocks);
	map->blocks = ft_split(map->map_holder, '\n');
	draw_map(map);
}

void	go_right(t_map *map)
{
	int		next_pos;
	int		player_pos;

	if (map->map_holder[get_next_pos(map, 1, 0)] == 'E' && is_done(map))
		exit(0);
	player_pos = get_position(map->map_holder, 'P');
	pos_to_dim(map, player_pos);
	next_pos = dim_to_pos(map->map_holder, map->player_x + 1, map->player_y);
	if (map->map_holder[next_pos] == '1' || map->map_holder[next_pos] == 'E')
		return ;
	map->map_holder[player_pos] = '0';
	map->map_holder[next_pos] = 'P';
	print_step(map);
	free2d(map->blocks);
	map->blocks = ft_split(map->map_holder, '\n');
	draw_map(map);
}
