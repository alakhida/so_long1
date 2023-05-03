/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:41:25 by alakhida          #+#    #+#             */
/*   Updated: 2023/05/03 19:00:50 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"


int check_map_and_pce(t_map *map, char *path, int ac)
{
    if (check_file(path) == 0)
        return (0);
    
   ft_rectangular_check(path);
   check_map(ac, path, map);
   check_new_line(map->map_holder);
   if(!isSurroundedByWalls(path, map))
        exit(1);
    check_path(path);
    return (1);
}

void splitted_map(t_map *map, char *path)
{
    map->map_holder = read_map(path);
    map->blocks = ft_split(map->map_holder, '\n');
    free(map->map_holder);
}




