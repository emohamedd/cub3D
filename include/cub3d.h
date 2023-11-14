/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:15:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/14 18:36:40 by houattou         ###   ########.fr       */
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
#define WIDTH    1500
#define HEIGHT   1000
#define FOV_ANGLE (60 * (M_PI / 180))
#define WALL_STRIP_WIDTH 1
#define WALL_STRIO_WIDTH 4
#define MUM_RAYS WIDTH/ 4
#define   MINIMAP_SCAL_FACTOR 0.2


#define TRUE 1
#define FALSE 0


#define WALL_STRIO_WIDTH 4
#include "/Users/emohamed/Desktop/MLX42/include/MLX42/MLX42.h"


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

typedef enum e_direction {
	NO,
	SO,
	WE,
	EA,
}	t_direction;

typedef struct s_map
{
	char	**all_map;
	char	**direc;
	char	**map;
	// char 	**minimap;
	int		dir_len;
	t_direction direction;
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
	int		redf;
	int		greenf;
	int		bluef;
	int		redc;
	int		greenc;
	int		bluec;

}			t_direc;



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
	bool is_player_facing_up;
	bool is_player_facing_left;
	int sign;
	bool is_vertical;
	bool is_horizontal;

}t_cord;


typedef struct s_player
{
	float x;
	float y;
	float radius;
	float rotation_angle;
	float move_speed;
	bool is_ray_facing_left;
	bool is_ray_facing_up;
	float dis_h;
	float dis_v;
   
}t_player;


typedef struct s_mouse
{
	int	x;
	int	y;
}	t_mouse;


typedef struct s_all_data
{
	t_mouse			*mouse;
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
	float	ray_angle;
	
	float	xtx;
	
	t_textrs textrs;

	int y_end;

}t_all_data;

/*----------------*RayCasting functions:----------------------------------------------*/
t_all_data *init_data(t_all_data *data);
void start_raycasting(t_all_data *data);
void draw_map(t_all_data *data);
void draw_player(t_all_data *data);
void init(t_all_data *data);
void init_mlx(t_all_data *data);
void parsing(t_all_data *data, int ac , char **av);
void    draw_map(t_all_data *data);
void drawing(t_all_data *data);
float distance_between_points(float x1, float y1, float x2, float y2);
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
void render_rays(t_all_data *data);

void cast_ray(t_all_data *data,float angle_ray, int i);
t_all_data *draw_rays(t_all_data *data, int id, float ray_angle);

void get_horizontal_intersection(t_all_data *mlx, float ray_angle);
void	get_vertical_intersection(t_all_data *mlx, float ray_angle);
void	draw_wall_with_texture(t_all_data *data, int id, float xtx,
		mlx_texture_t *texture);
void separ_direc_value(t_all_data *data);
void	load_textures(t_all_data *data);
/*parsing par--------------------------------------------------------------------*/
void		print_err(char *s);
int			check_file_cub(char *file);
int handle_color_key(t_direc *dir);
void		readfile(int fd, t_map *map, t_direc *dir);
void free_2d_arr(char **arr);
void		dir_parse(t_map *map, t_direc *direc);
void		map_parse(t_map *map);
int			valid_map(t_map *map);
int			ft_strcmp(char *s1, char *s2);
int			check_map_char(t_map *map);
int			new_atoi(const char *str);
void		check_key_color_range(t_direc *dir);
int			check_key_directions(t_direc *dir);
void		readfile(int fd, t_map *map, t_direc *dir);
void player_direction(t_map *map);
void free_all_data(t_all_data *data);
// void	readfile(int fd, t_map *map, t_direc *dir);

#endif