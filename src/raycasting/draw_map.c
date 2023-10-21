/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:44:22 by houattou          #+#    #+#             */
/*   Updated: 2023/10/21 17:04:59 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#define WIDTH_MAP 15
#define HEIGHT_MAP 11
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



// bool    check_if_have_wall(t_all_data *data, float x, float y)
// {
//     int map_grid_x;
//     int map_grid_y;
//     int old_x;
//     int old_y;
//     map_grid_x = floor(x /SIZE_TITLE);
//     map_grid_y = floor(y / SIZE_TITLE);
//     old_x = floor(data->player->x /SIZE_TITLE);
//     old_y = floor(data->player->y / SIZE_TITLE);
    
//     // if((mymap[map_grid_y][old_x] == 1) || mymap[old_y][map_grid_x] == 1)
//     //     return(FALSE);
//     if(map_grid_y >= HEIGHT_MAP || map_grid_x >= WIDTH_MAP || map_grid_x < 0 || map_grid_y < 0 || x <= 0 || y <= 0)
//         return (FALSE);
//     if(mymap[map_grid_y][map_grid_x] == 1)
//         return (FALSE);
//     return(TRUE);
 
// }


bool check_if_have_wall(t_all_data *data, float x, float y)
{
    int map_grid_x = (int)(x / SIZE_TITLE);
    int map_grid_y = (int)(y / SIZE_TITLE);

    // Check if (map_grid_x, map_grid_y) is within valid bounds of your map
    if (map_grid_x >= 0 && map_grid_x < WIDTH_MAP && map_grid_y >= 0 && map_grid_y < HEIGHT_MAP)
    {
        // Check if there's a wall at the specified grid cell
        if (mymap[map_grid_y][map_grid_x] == 1)
        {
            return false; // Wall found
        }
    }

    // The position is either outside the map boundaries or there's no wall
    return true; // No wall found
}

//distance_between_points
int   distance_between_points(float x1, float y1, float x2, float y2)
{
    return(sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))); 
}
void cast_ray(t_all_data *data,float angle_ray, int i)
{
    int is_facing_down;
    int is_facing_up;
    int is_facing_left;
    int is_facing_right;

    angle_ray  = normalize_angle(angle_ray);
    is_facing_down = angle_ray > 0  && angle_ray < M_PI;
    is_facing_up = !is_facing_down;
    is_facing_right = angle_ray < M_PI * 0.5 || angle_ray > 1.5 * M_PI;
    is_facing_left = !is_facing_right;

    float xintercept, yintercept;
    float xstep, ystep;
    int found_horz_wall_hit = FALSE;
    float horz_wall_hit_x = 0;
    float horz_wall_hit_y = 0;
    int horz_wall_content = 0;
    
    yintercept = floor(data->player->y / SIZE_TITLE) * SIZE_TITLE;
    yintercept += is_facing_down ? SIZE_TITLE : 0;

    xintercept = data->player->x + (yintercept - data->player->y) / tan(angle_ray);
    ystep = SIZE_TITLE;
    ystep *= is_facing_up ? -1 : 1;
    xstep = SIZE_TITLE / tan(angle_ray);
    xstep *= (is_facing_left && xstep > 0) ? -1 : 1;
    xstep *= (is_facing_right && xstep < 0) ? -1 : 1;
    
    float next_horz_touch_x = xintercept;
    float next_horz_touch_y = yintercept;
    
    while(next_horz_touch_x >= 0 && next_horz_touch_x <= WIDTH && next_horz_touch_y >= 0 && next_horz_touch_y <= HEIGHT)
    {
        float x_to_check = next_horz_touch_x;
        float y_to_check = next_horz_touch_y + (is_facing_up ? -1 : 0);
        if(check_if_have_wall(data, x_to_check, y_to_check))
        {
            horz_wall_hit_x = next_horz_touch_x;
            horz_wall_hit_y = next_horz_touch_y;
            horz_wall_content = mymap[(int)floor(y_to_check / SIZE_TITLE)][(int)floor(x_to_check / SIZE_TITLE)];
            found_horz_wall_hit = TRUE;
            break;
        }
        else
        {
            next_horz_touch_x += xstep;
            next_horz_touch_y += ystep;
        }
 
       
    }
    
  /*Vertical */  

  int found_vert_wall_hit = FALSE;
  int vert_wall_hit_x = 0;
  int vert_wall_hit_y = 0;
  int vert_wall_content = 0;
  // Find the x-coordinate of the closest horizontal grid intersection
    xintercept = floor(data->player->x / SIZE_TITLE) * SIZE_TITLE;
    xintercept += is_facing_right ? SIZE_TITLE : 0;
    // Find the y-coordinate of the closest horizontal grid intersection
    yintercept = data->player->y + (xintercept - data->player->x) * tan(angle_ray);
    xstep = SIZE_TITLE;
    xstep *= is_facing_left ? -1 : 1;
    ystep = SIZE_TITLE * tan(angle_ray);
    ystep *= (is_facing_up && ystep > 0) ? -1 : 1;
    ystep *= (is_facing_down && ystep < 0) ? -1 : 1;
    float next_vert_touch_x = xintercept;
    float next_vert_touch_y = yintercept;
    
    while(next_vert_touch_x >= 0 && next_vert_touch_x <= WIDTH && next_vert_touch_y >= 0 && next_vert_touch_y <= HEIGHT)
    {
        float x_to_check = next_vert_touch_x + (is_facing_left ? -1 : 0);
        float y_to_check = next_vert_touch_y;
        if(check_if_have_wall(data, x_to_check, y_to_check))
        {
            vert_wall_hit_x = next_vert_touch_x;
            vert_wall_hit_y = next_vert_touch_y;
            vert_wall_content = mymap[(int)floor(y_to_check / SIZE_TITLE)][(int)floor(x_to_check / SIZE_TITLE)];
            found_vert_wall_hit = TRUE;
            break;
        }
        else
        {
            next_vert_touch_x += xstep;
            next_vert_touch_y += ystep;
        }
        next_vert_touch_x++;
        next_vert_touch_y++;
    }
    float horz_hit_distance = found_horz_wall_hit ? distance_between_points(data->player->x, data->player->y, horz_wall_hit_x, horz_wall_hit_y) : INT_MAX;
    float vert_hit_distance = found_vert_wall_hit ? distance_between_points(data->player->x, data->player->y, vert_wall_hit_x, vert_wall_hit_y) : INT_MAX; 
    if(vert_hit_distance < horz_hit_distance)
    {
        data->rays[i].distance = vert_hit_distance;
        data->rays[i].wall_hits_x = vert_wall_hit_x;
        data->rays[i].wall_hits_y = vert_wall_hit_y;
        data->rays[i].wall_hit_content = vert_wall_content;
        data->rays[i].hit_vertical = TRUE;
    }
    else
    {
        data->rays[i].distance = horz_hit_distance;
        data->rays[i].wall_hits_x = horz_wall_hit_x;
        data->rays[i].wall_hits_y = horz_wall_hit_y;
        data->rays[i].wall_hit_content = horz_wall_content;
        data->rays[i].hit_vertical = FALSE;
    }
    data->rays[i].rays_angle = angle_ray;
    data->rays[i].is_ray_facing_down = is_facing_down;
    data->rays[i].is_ray_facing_up = is_facing_up;
    data->rays[i].is_ray_facing_left = is_facing_left;
    data->rays[i].is_ray_facing_right = is_facing_right;
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
                        mlx_put_pixel(img, x, y, ft_pixel(0, 0, 0, 255));
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