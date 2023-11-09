/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:15:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/09 21:08:20 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#define SIZE_TITLE 60
#define MAP_MUM_ROWS 25
#define MAP_MUM_COLS 11
#define FPS 30
#define WIDTH_MAP 25
#define HEIGHT_MAP 11
#define WIDTH    2500
#define HEIGHT   2500
#define FOV_ANGLE (60 * (M_PI / 180))
#define WALL_STRIP_WIDTH 1
#define WALL_STRIO_WIDTH 4
#define MUM_RAYS WIDTH/ 4
#define   MINIMAP_SCAL_FACTOR 0.2


#define TRUE 1
#define FALSE 0


#define WALL_STRIO_WIDTH 4
#include "/Users/houattou/Desktop/MLX42/include/MLX42/MLX42.h"


// # include "../../get_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include<string.h>
#include<errno.h>
#include<limits.h>
#include<string.h>
#include<fcntl.h>
#include "../libft/libft.h"

//this partie for parsing :

typedef struct s_textrs
{
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*no_texture;
}	t_textrs;


typedef struct s_map
{
	char	**all_map;
	char	**direc;
	char	**map;
	int		dir_len;
	int	width;
	int	height;

}			t_map;

typedef struct s_direc
{
	char	*key;
	char	*value;
	char 	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	char	*f;

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

void	readfile(int fd, t_map *map, t_direc *dir);


void	readfile(int fd, t_map *map, t_direc *dir);
//this part for raycasting:
typedef struct s_cord
{
	float xstep;
	float ystep;
	float xstep_v;
	float xstep_h;
	float   ystep_h;
    float   ystep_v;
	float	distance;
	bool is_vertical;
	bool is_horizontal;

}t_cord;


typedef struct s_player
{
	float x;
	float y;
	float radius;
	int turn_direction;
	int  wlk_direction;
	float rotation_angle;
	float move_speed;
	float rotation_speed;
    float wlk_speed;
	float turn_speed;
	float width;
	float heigth;

	bool is_ray_facing_up;
	bool is_ray_facing_down;
	bool is_ray_facing_left;
	bool is_ray_facing_right;
   
}t_player;


typedef struct s_all_data
{
	mlx_t *mlx;
	mlx_image_t *img;
	mlx_image_t *img_minimap;
	t_player *player;

	t_cord *cord;
	t_direc *dir;
	t_map *map;
	int exact_wall_height;
	int wall_height;
	int y_start;
	t_textrs textrs;

	int y_end;

}t_all_data;

/*----------------*RayCasting functions:----------------------------------------------*/
void    draw_map(t_all_data *data);
void drawing(t_all_data *data);

void generate3d_projection(t_all_data *data);
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

void render_rays(t_all_data *data);

void cast_ray(t_all_data *data,float angle_ray, int i);
t_all_data *draw_rays(t_all_data *data, int id, float ray_angle);

t_all_data* draw_vertical_intersection(t_all_data *mlx, float ray_angle);
t_all_data*	draw_horizontal_intersection(t_all_data *mlx, float ray_angle);
void draw_wall_with_texture(t_all_data *data, int id, float ray_angle, float hor_intercept_x, float vert_intercept_y, float xtx, mlx_texture_t *texture);

void separ_direc_value(t_all_data *data);
void	load_textures(t_all_data *data);
#endif