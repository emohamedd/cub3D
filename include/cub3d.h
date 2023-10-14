/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:15:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/14 16:43:41 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#define SIZE_TITLE 40
#define WIDTH 15 * SIZE_TITLE
#define HEIGHT 11 *SIZE_TITLE
#include "/Users/houattou/Desktop/MLX42/include/MLX42/MLX42.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include<string.h>


typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}
t_data;

typedef struct s_mlx
{
	void *mlx;
	void *mlx_win;
}
t_mlx;
typedef struct s_player
{
	double x;
	double y;
	double dir;
	double plane;
}t_player;

typedef struct s_map
{
	int start_height;
	int start_width;
	int end_height;
	int end_width;
}				t_map;
typedef struct s_all_data
{
	t_mlx *mlx;
	t_data *data;
	t_player *player;
}t_all_data;


#endif