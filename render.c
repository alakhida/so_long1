/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:16:59 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/03 19:51:50 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "so_long.h"

static void init_images(t_map *map)
{
	int width;
	int heigth;
	
	map->floor = mlx_xpm_file_to_image(map->mlx.mlx, "./imgs/floor_2.xpm", &width, &heigth);
	map->wall = mlx_xpm_file_to_image(map->mlx.mlx, "./imgs/wall_1.xpm", &width, &heigth);
	map->player = mlx_xpm_file_to_image(map->mlx.mlx, "./imgs/player.xpm", &width, &heigth);
	map->exit = mlx_xpm_file_to_image(map->mlx.mlx, "./imgs/exit.xpm", &width, &heigth);
	map->tokens = mlx_xpm_file_to_image(map->mlx.mlx, "./imgs/tokens_2.xpm", &width, &heigth);
}

static void get_win_size(t_map *map)
{
	map->x = ft_strlen(map->blocks[0]) * 50;
	map->j = ft_strlen2d(map->blocks) * 50;
}

void draw_map(t_map *map)
{
	int idx1;
	int idx2;

	idx1 = 0;
	while (map->blocks[idx1])
	{
		idx2 = 0;
		while (map->blocks[idx1][idx2])
		{
			if (map->blocks[idx1][idx2] == '1')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->wall, idx2 * 50, idx1 * 50);
			else if (map->blocks[idx1][idx2] == '0')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->floor, idx2 * 50, idx1 * 50);
			else if (map->blocks[idx1][idx2] == 'P')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->player, idx2 * 50, idx1 * 50);
			else if (map->blocks[idx1][idx2] == 'E')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->exit, idx2 * 50, idx1 * 50);
			else if (map->blocks[idx1][idx2] == 'C')
				mlx_put_image_to_window(map->mlx.mlx, map->mlx.mlx_win, map->tokens, idx2 * 50, idx1 * 50);
			
			idx2++;
		}
		idx1++;
	}
}

static void	print_step(t_map *map)
{
	char	*str;

	map->move = map->move + 1;
	str = ft_itoa(map->move);
	write(1, str, ft_strlen(str));
	write(1, "\e[4;34m:ch7al tmchiti\r", 22);
	free(str);
}

int get_next_pos(t_map *map, int x, int y)
{
	int player_pos;
	int next_pos;
	player_pos = get_position(map->map_holder, 'P');
	pos_gitm(map, player_pos);
	next_pos = dim_to_pos(map->map_holder, map->player_x + x, map->player_y + y);
	return (next_pos);
}

void go_left(t_map *map)
{
	int next_pos;
	int player_pos;

	player_pos = get_position(map->map_holder, 'P');
	pos_to_dim(map, player_pos);
	next_pos = dim_to_pos(map->map_holder, map->player_x - 1, map->player_y);
	if (map->map_holder[next_pos] == '1' || map->map_holder[next_pos] == 'E')
		return;
	map->map_holder[player_pos] = '0';
	map->map_holder[next_pos] = 'P';
	print_step(map);
	free2d(map->blocks);
	map->blocks = ft_split(map->map_holder, '\n');
	draw_map(map);
}

void go_down(t_map *map)
{
	int next_pos;
	int player_pos;

	player_pos = get_position(map->map_holder, 'P');
	pos_to_dim(map, player_pos);
	next_pos = dim_to_pos(map->map_holder, map->player_x, map->player_y + 1);
	if (map->map_holder[next_pos] == '1' || map->map_holder[next_pos] == 'E')
		return;
	map->map_holder[player_pos] = '0';
	map->map_holder[next_pos] = 'P';
	print_step(map);
	free2d(map->blocks);
	map->blocks = ft_split(map->map_holder, '\n');
	draw_map(map);
}
void go_up(t_map *map)
{
	int next_pos;
	int player_pos;

	player_pos = get_position(map->map_holder, 'P');
	pos_to_dim(map, player_pos);
	next_pos = dim_to_pos(map->map_holder, map->player_x, map->player_y - 1);
	if (map->map_holder[next_pos] == '1' || map->map_holder[next_pos] == 'E')
		return;
	map->map_holder[player_pos] = '0';
	map->map_holder[next_pos] = 'P';
	print_step(map);
	free2d(map->blocks);
	map->blocks = ft_split(map->map_holder, '\n');
	draw_map(map);
}
void go_right(t_map *map)
{
	int next_pos;
	int player_pos;

	player_pos = get_position(map->map_holder, 'P');
	pos_to_dim(map, player_pos);
	next_pos = dim_to_pos(map->map_holder, map->player_x + 1, map->player_y);
	if (map->map_holder[next_pos] == '1' || map->map_holder[next_pos] == 'E')
		return;
	map->map_holder[player_pos] = '0';
	map->map_holder[next_pos] = 'P';
	print_step(map);
	free2d(map->blocks);
	map->blocks = ft_split(map->map_holder, '\n');
	draw_map(map);
	}

int move(int keycode, t_map *para)
{
	if (keycode == 0 || keycode == 123)
	{
		if (para->map_holder[get_next_pos(para, -1 , 0)] == 'E' && get_position(para->map_holder, 'C') == -1)
			exit(0);
		go_left(para);
	}
	else if (keycode == 1 || keycode == 125)
	{
		if (para->map_holder[get_next_pos(para, 0 , 1)] == 'E' && get_position(para->map_holder, 'C') == -1)
			exit(0);
		go_down(para);
	}
	else if (keycode == 13 || keycode == 126)
	{
		if (para->map_holder[get_next_pos(para, 0 , -1)] == 'E' && get_position(para->map_holder, 'C') == -1)
			exit(0);
		go_up(para);
	}
		else if (keycode == 2 || keycode == 124)
		{
			if (para->map_holder[get_next_pos(para, 1 , 0)] == 'E' && get_position(para->map_holder, 'C') == -1)
			exit(0);
			go_right(para);
		}
	else if (keycode == 53)
	{
		mlx_destroy_window(para->mlx.mlx, para->mlx.mlx_win);
		exit (1);
	}
	return (0);
}

 int	quit(void)
 {
	exit(1);
 }

void put_win(t_map *map)
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
