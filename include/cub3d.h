/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:15:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/25 10:53:10 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#define SIZE_TITLE 60
#define MAP_MUM_ROWS 25
#define MAP_MUM_COLS 11
#define FPS 30
#define WIDTH   (SIZE_TITLE *(MAP_MUM_ROWS))
#define HEIGHT  (SIZE_TITLE *(MAP_MUM_COLS))
#define FOV_ANGLE (60 * (M_PI / 180))
#define WALL_STRIO_WIDTH 4
#define MUM_RAYS WIDTH/ 4
#define   MINIMAP_SCAL_FACTOR 1.0

#define WIDTH_MAP 25
#define HEIGHT_MAP 11

#define TRUE 1
#define FALSE 0


#define WALL_STRIO_WIDTH 4
#include "/Users/houattou/Desktop/MLX42/include/MLX42/MLX42.h"

# include "../libft/libft.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include<string.h>
#include<errno.h>
#include<limits.h>

typedef struct s_cord
{
	int xstep;
	int ystep;

}t_cord;


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

typedef struct rays
{
	float rays_angle;
	float wall_hits_x;
	float wall_hits_y;
	float distance;
	int hit_vertical;
	float hit_horizantal;
	int is_ray_facing_up;
	int is_ray_facing_down;
	int is_ray_facing_left;
	int is_ray_facing_right;
	int wall_hit_content;
}t_rays[];

typedef struct s_all_data
{
	mlx_t *mlx;
	mlx_image_t *img;
	t_player *player;
	t_rays *rays;
	t_cord *cord;
}t_all_data;

/*----------------*RayCasting functions:----------------------------------------------*/
void    draw_map(mlx_t *mlx, mlx_image_t *img);
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void initialize_player(t_all_data *data);
void draw_player(t_all_data *data);
void ratate_player(mlx_key_data_t keydata, t_all_data *data);
void update_player(t_all_data *mlx, mlx_key_data_t keydata);
void draw_line(mlx_image_t *image, float x1, float y1, float x2, float y2, int color);
void	my_keyhook(mlx_key_data_t keydata, void *param);
bool	is_has_wall(t_all_data *mlx, float x, float y);
bool    check_if_have_wall(t_all_data *data, float x, float y);
float normalize_angle(float angle);

void cast_all_rays(t_all_data *data);

void cast_ray(t_all_data *data,float angle_ray, int i);
void render_rays(t_all_data *data);

#endif