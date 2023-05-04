/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:02:31 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/04 20:11:02 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

void	print_step(t_map *map)
{
	char	*str;

	map->move = map->move + 1;
	str = ft_itoa(map->move);
	write(1, str, ft_strlen(str));
	write(1, "\e[4;34m:ch7al tmchiti\r", 22);
	free(str);
}

int	get_next_pos(t_map *map, int x, int y)
{
	int		player_pos;
	int		next_pos;

	player_pos = get_position(map->map_holder, 'P');
	pos_to_dim(map, player_pos);
	next_pos = dim_to_pos(map->map_holder,
			map->player_x + x, map->player_y + y);
	return (next_pos);
}

int	is_done(t_map *para)
{
	if (get_position(para->map_holder, 'C') == -1)
		return (1);
	return (0);
}

int	move(int keycode, t_map *para)
{
	if (keycode == 0 || keycode == 123)
		go_left(para);
	else if (keycode == 1 || keycode == 125)
		go_down(para);
	else if (keycode == 13 || keycode == 126)
		go_up(para);
	else if (keycode == 2 || keycode == 124)
		go_right(para);
	else if (keycode == 53)
	{
		mlx_destroy_window(para->mlx.mlx, para->mlx.mlx_win);
		exit (1);
	}
	return (0);
}
