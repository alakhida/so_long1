/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:41:42 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/03 18:49:36 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H


// # include "./mlx/mlx_int.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stddef.h>
#include <mlx.h>

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
	void	*mlx_img;

}	t_mlx;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
  t_mlx mlx;
    int rows;
    int     i;
    int cols;
    int     j;
    char **blocks;
    int fd;
    int  x;
    int move;
    int count;
    char *BUFFER;
    char    *str;
    int count_p;
    int player_x;
    int player_y;
    int count_c;
    int count_e;
  char *map_holder;
  void *floor;
  void *wall;
  void *player;
  void *exit;
  void *tokens;
} t_map;


size_t ft_strlen2d(char **strs);
int check_file(char   *path);
void free2d(char **strs);
void print_errors(int i);
int check_elements(int ac, char *av[]);
char   *read_map(char *path);
int	ft_getlinelength(char *path);
void	ft_rectangular_check(char *argv);
void check_new_line(char *map);
int isSurroundedByWalls(char *path, t_map *map) ;
void check_pce(char *path, t_map *map);
int check_map_and_pce(t_map *map, char *path, int ac);
void splitted_map(t_map *map, char *path);
void check_map(int ac, char *av,t_map *map);
void check_path_1(t_map map, char *av);
int print_errors_1(int i);
int check_path(char *path);
void put_win(t_map *map);
void pos_to_dim(t_map *map, int position);
int get_position(char *map ,char c);
unsigned int	dim_to_pos(char *map, int player_x, int player_y);

#endif