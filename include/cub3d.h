/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:15:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/16 14:00:37 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SIZE_TITLE 60
# define WIDTH 1500
# define HEIGHT 1000
# define MINIMAP_SCAL_FACTOR 0.2
# define TRUE 1
# define FALSE 0
# include "../libft/libft.h"
# include "/Users/houattou/Desktop/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textrs
{
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*no_texture;
}					t_textrs;

typedef enum e_direction
{
	NO,
	SO,
	WE,
	EA,
}					t_direction;

typedef struct s_map
{
	char			**all_map;
	char			**direc;
	char			**map;
	int				dir_len;
	t_direction		direction;
	int				width;
	int				height;

}					t_map;

typedef struct s_direc
{
	char			*key;
	char			*value;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			*f;
	int				redf;
	int				greenf;
	int				bluef;
	int				redc;
	int				greenc;
	int				bluec;

}					t_direc;

typedef struct s_cord
{
	float			xstep;
	float			ystep;
	float			xstep_v;
	float			xstep_h;
	float			ystep_h;
	float			ystep_v;
	float			distance;
	bool			is_player_facing_up;
	bool			is_player_facing_left;
	int				sign;
	bool			is_vertical;
	bool			is_horizontal;

}					t_cord;

typedef struct s_player
{
	float			x;
	float			y;
	float			radius;
	float			rotation_angle;
	float			move_speed;
	bool			is_ray_facing_left;
	bool			is_ray_facing_up;
	float			dis_h;
	float			dis_v;
	float			fov_angle;

}					t_player;

typedef struct s_mouse
{
	int				x;
	int				y;
}					t_mouse;

typedef struct s_s
{
	int				k;
	int				x;
	int				y;
	int				m;
	int				n;
	int				pixel_x;
	int				pixel_y;
	int				num_stars;
	int				star_radius;

}					t_s;

typedef struct s_all_data
{
	t_mouse			*mouse;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_player		*player;
	t_cord			*cord;
	t_direc			*dir;
	t_map			*map;
	t_s				s;
	int				exact_wall_height;
	int				wall_height;
	int				y_start;
	float			ray_angle;
	float			xtx;
	t_textrs		textrs;
	int				y_end;

}					t_all_data;

/*----------------*RayCasting functions:--------------*/
float				convert_degree(float degree);
t_all_data			*init_data(t_all_data *data);
void				start_raycasting(t_all_data *data);
void				init(t_all_data *data);
void				init_mlx(t_all_data *data);
void				parsing(t_all_data *data, int ac, char **av);
void				drawing(t_all_data *data);
float				distance_between_points(float x1, float y1, float x2,
						float y2);
void				initialize_player(t_all_data *data);
void				ratate_player(mlx_key_data_t keydata, t_all_data *data);
void				update_player(t_all_data *mlx, mlx_key_data_t keydata);
void				my_keyhook(mlx_key_data_t keydata, void *param);
bool				is_has_wall(t_all_data *mlx, float x, float y);
bool				check_if_have_wall(t_all_data *data, float x, float y);
float				normalize_angle(float angle);
void				get_horizontal_intersection(t_all_data *mlx,
						float ray_angle);
void				get_vertical_intersection(t_all_data *mlx, float ray_angle);
void				draw_wall_with_texture(t_all_data *data, int id, float xtx,
						mlx_texture_t *texture);
void				load_textures(t_all_data *data);
/*---------PARSING functions------------------------------------------------*/
void				print_err(char *s);
int					check_file_cub(char *file);
int					handle_color_key(t_direc *dir);
void				readfile(int fd, t_map *map, t_direc *dir);
void				free_2d_arr(char **arr);
void				dir_parse(t_map *map, t_direc *direc);
void				map_parse(t_map *map);
int					valid_map(t_map *map);
int					ft_strcmp(char *s1, char *s2);
int					check_map_char(t_map *map);
int					new_atoi(const char *str);
void				check_key_color_range(t_direc *dir);
int					check_key_directions(t_direc *dir);
void				readfile(int fd, t_map *map, t_direc *dir);
void				player_direction(t_map *map);
void				free_all_data(t_all_data *data);
int					len_of_direction(t_map *map);
void				trim_and_replace(char *str, char replace, char *trim);
void				trim_map_lines(t_map *map);
void				check_direction_count(t_map *map);
void				check_for_duplicate_keys(t_map *map);
void				check_direction_arguments(char **new_array);
void				check_and_exit_if_invalid_map(t_map *map);
void				check_file_opening(int fd, char *line);
void				check_empty_map(char *line);
void				check_empty_string(char *line);
void				check_and_exit_if_empty_string(char *line);
void				add_stars_to_sky(t_all_data *data);

#endif