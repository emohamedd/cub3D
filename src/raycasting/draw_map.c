/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:44:22 by houattou          #+#    #+#             */
/*   Updated: 2023/10/24 23:27:06 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int is_game_running = FALSE;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
int mymap[11][15] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1}
};
 

bool	check_wall(t_all_data *mlx, float x, float y)
{
	if (x < 0 || x > WIDTH_MAP || y < 0 || y > HEIGHT_MAP)
		return (TRUE);
	x = floor(x / SIZE_TITLE);
	y = floor(y / SIZE_TITLE);
	if (x < 0 || x >= 25 || y < 0 || y >= 11)
		return (FALSE);
	if (mymap[(int)y][(int)x] == 1)
		return (TRUE);
	return (FALSE);
}
bool    check_if_have_wall(t_all_data *data, float x, float y)
{
    int map_grid_x;
    int map_grid_y;
    int old_x;
    int old_y;
    map_grid_x = floor(x /SIZE_TITLE);
    map_grid_y = floor(y / SIZE_TITLE);
    old_x = floor(data->player->x /SIZE_TITLE);
    old_y = floor(data->player->y / SIZE_TITLE);
    
    if((mymap[map_grid_y][old_x] == 1) || mymap[old_y][map_grid_x] == 1)
        return(FALSE);
    if(map_grid_y >= HEIGHT_MAP || map_grid_x >= WIDTH_MAP || map_grid_x < 0 || map_grid_y < 0 || x <= 0 || y <= 0)
        return (FALSE);
    if(mymap[map_grid_y][map_grid_x] == 1)
        return (FALSE);
    return(TRUE);
 
}


void    draw_map( mlx_t *mlx, mlx_image_t *img)
{
    int       i;
    int       j;
    int        x;
    int        y;

 (void)mlx;

    i = 0;
    while (i < 11)
    {
        j = 0;
        while (j < 15)
        {
            y = i * SIZE_TITLE;
            while (y < (SIZE_TITLE * i) + SIZE_TITLE)
            {
                x = j * SIZE_TITLE;
                while (x < (SIZE_TITLE * j) + SIZE_TITLE)
                {
                    if (mymap[i][j] == 1)
                        mlx_put_pixel(img, x, y, ft_pixel(125, 98, 0, 33));
                    else if (mymap[i][j] == 0)
                        mlx_put_pixel(img, x, y, ft_pixel(255, 255, 255, 255));
                    x++;
                }
                y++;
            }
            j++;
        }
        i++;
    }
}
/* ray_casting : --------------------------------*/

float distance_between_points(float x1, float y1, float x2, float y2)
{
    return(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
float normalize_angle(float angle)
{
    angle = remainderf(angle, M_PI * 2);
    if(angle < 0)
        angle += 2 * M_PI;
    return(angle);
}

void draw_rays_first_insertion_in_horizonatal(t_all_data *data, float ray_angle)
{
    float x_inter;
    float y_inter;
    int sign;
    int is_ray_facing_up;
    
    is_ray_facing_up = ray_angle > M_PI && ray_angle < 2 * M_PI;
	sign = 1;
	if (is_ray_facing_up)
    {
        
		sign = -1;
    }

    y_inter = floor(data->player->y / SIZE_TITLE ) * SIZE_TITLE;
	if (!is_ray_facing_up)
		y_inter += SIZE_TITLE;

    x_inter = data->player->x + (y_inter - data->player->y) / tan(ray_angle);

  
        if(check_wall(data, x_inter, y_inter) == TRUE)
        {
            // y_inter += sign *SIZE_TITLE;
            // x_inter += sign *SIZE_TITLE / tan(ray_angle);
            draw_line(data->img, data->player->x, data->player->y, x_inter, y_inter,  ft_pixel(255, 255, 0, 255));
        }
        


    printf("x_inter = %f\n", floor(x_inter / SIZE_TITLE));
    printf("y_inter = %f\n", floor(y_inter / SIZE_TITLE));
}
void render_rays(t_all_data *data)
{
    int id;
    id = 0;
    int num_of_rays = WIDTH;
    float ray_angle = normalize_angle(data->player->rotation_angle - (FOV_ANGLE / 2));
    while(id < num_of_rays)
    {
       draw_rays_first_insertion_in_horizonatal(data, ray_angle);
        // if(check_if_have_wall(data,(data->player->x + cos(ray_angle) * 80), data->player->y + sin(ray_angle) * 80) != TRUE)
            //  draw_line(data->img, data->player->x, data->player->y, data->player->x + cos(ray_angle)*80, data->player->y + sin(ray_angle)*80,  ft_pixel(255, 255, 0, 255));
        ray_angle += FOV_ANGLE / num_of_rays;
        id++;
    }
}



