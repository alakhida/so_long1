/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:41:42 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/04 20:12:28 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <mlx.h>

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
	void	*mlx_img;

}	t_mlx;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	t_mlx	mlx;
	int		rows;
	int		i;
	int		cols;
	int		j;
	char	**blocks;
	int		fd;
	int		x;
	int		move;
	int		count;
	char	*buffer;
	char	*str;
	int		count_p;
	int		player_x;
	int		player_y;
	int		count_c;
	int		count_e;
	char	*map_holder;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*tokens;
}	t_map;

size_t			ft_strlen2d(char **strs);
int				check_file(char	*path);
void			free2d(char **strs);
void			print_errors(int i);
char			*read_map(char *path);
void			ft_rectangular_check(char *argv);
void			check_new_line(char *map);
int				issurroundedbywalls(char *path, t_map *map);
void			check_pce(char *path, t_map *map);
int				check_map_and_pce(t_map *map, char *path, int ac);
void			splitted_map(t_map *map, char *path);
void			check_map(int ac, char *av, t_map *map);
void			check_path_1(t_map map, char *av);
int				check_path(char *path);
void			put_win(t_map *map);
void			pos_to_dim(t_map *map, int position);
int				get_position(char *map, char c);
unsigned int	dim_to_pos(char *map, int player_x, int player_y);
void			check_pce01(t_map *map);
void			go_right(t_map *map);
void			go_up(t_map *map);
void			go_down(t_map *map);
void			go_left(t_map *map);
void			draw_map(t_map *map);
int				get_next_pos(t_map *map, int x, int y);
int				move(int keycode, t_map *para);
void			get_win_size(t_map *map);
void			init_images(t_map *map);
void			get_win_size(t_map *map);
void			print_step(t_map *map);
int				is_done(t_map *para);

#endif
