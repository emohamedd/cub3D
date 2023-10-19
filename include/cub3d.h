/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:15:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/19 12:57:30 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#define SIZE_TITLE 60
#define MAP_MUM_ROWS 13
#define MAP_MUM_COLS 20
#define FPS 30
#define WIDTH   SIZE_TITLE *(MAP_MUM_COLS)
#define HEIGHT  SIZE_TITLE *(MAP_MUM_ROWS)
#define FOV_ANGLE (60 * M_PI / 180)
#define MUM_RAYS WINDOW_WIDH
#define MINIMAP_SCAL_FACTOR 0.10
#include "/Users/houattou/Desktop/MLX42/include/MLX42/MLX42.h"

# include "../libft/libft.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include<string.h>
#include<errno.h>


typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}
t_data;

typedef struct s_player
{
	double x;
	double y;
	double radius;
	int turn_direction;
	int  wlk_direction;
	double rotation_angle;
	double move_speed;
	double rotation_speed;
	float wlk_speed;
	float turn_speed;
	double width;
	double heigth;
   
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
	mlx_t *mlx;
	mlx_image_t *img;
	t_player *player;
}t_all_data;

/*----------------*RayCasting functions:----------------------------------------------*/
void    draw_map( mlx_t *mlx, mlx_image_t *img);
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
// void initialize_player(t_all_data *data);
// void draw_player(void *param);
#endif