/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:15:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/08 21:14:46 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"
#define END "\033[0m"

// # include "mlx/mlx.h"
# include "get_line/get_next_line.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char	**all_map;
    int     all_rows;
    char    **direc;
    char    **map;
    int     dir_len;

}			t_map;

typedef struct s_direc
{
    char    *key;
    char   *value;

}			t_direc;

void print_err(char *s);
int	check_file_cub(char *file);
void readfile(int fd, t_map *map, t_direc *dir);
void dir_parse(t_map *map, t_direc *direc);
// void map_parse(t_map * map, t_direc *direc);
void map_parse(t_map * map);
int valid_map(t_map *map);
// int map_surrendred_by_1(t_map *map);
int	ft_strcmp(char *s1,  char *s2);
int check_map_char(t_map *map);
#endif