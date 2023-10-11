/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:15:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/11 14:42:26 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define RED 0x00FF0000FF
# define GREEN 0x0000FF00FF
# define YELLOW 0x00FFFF00FF
# define BLACK 0x00000000FF
# define WHITE 0x00FFFFFFFF
# define RESET "\033[0m"
# define END "\033[0m"

// # include "mlx/mlx.h"
# include "get_line/get_next_line.h"
#include "/Users/emohamed/Desktop/MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**all_map;
	char	**direc;
	char	**map;
	int		dir_len;
	int 	width;
	int 	height;

}			t_map;

typedef struct s_direc
{
	char	*key;
	char	*value;

}			t_direc;

void		print_err(char *s);
int			check_file_cub(char *file);
void		readfile(int fd, t_map *map, t_direc *dir);
void		dir_parse(t_map *map, t_direc *direc);
void		map_parse(t_map *map);
int			valid_map(t_map *map);
int			ft_strcmp(char *s1, char *s2);
int			check_map_char(t_map *map);
int			new_atoi(const char *str);
#endif