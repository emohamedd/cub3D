/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:49:17 by houattou          #+#    #+#             */
/*   Updated: 2023/11/14 17:02:33 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void draw_line(mlx_image_t* img, float X0, float Y0, float X1, float Y1, int color)
{ 
    // calculate dx & dy 
    float dx = X1 - X0; 
    float dy = Y1 - Y0; 
    // calculate steps required for generating pixels 
    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float)steps; 
    float Yinc = dy / (float)steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) { 
        mlx_put_pixel(img, X, Y,color); 
        if(img == NULL)
            break;// put pixel at (X,Y) 
        X += Xinc; // increment in x at each step 
        Y += Yinc; // increment in y at each step 
    } 
}


// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

 

void render_single_tile(mlx_image_t *img, int x, int y, unsigned int color)
{
    int i;
    int j;

    j = (y * SIZE_TITLE) * MINIMAP_SCAL_FACTOR;
    while (j < ((y * SIZE_TITLE) + SIZE_TITLE) * MINIMAP_SCAL_FACTOR)
    {
        i = (x * SIZE_TITLE) * MINIMAP_SCAL_FACTOR;
        while (i < ((x * SIZE_TITLE) + SIZE_TITLE) * MINIMAP_SCAL_FACTOR)
        {
            mlx_put_pixel(img, i, j, color);
            i++;
        }
        j++;
    }
}

void draw_map(t_all_data *data)
{
    int i;
    int j;

    j = 0;
    while (j < data->map->height)
    {
        i = 0;
        while (i < data->map->width && data->map->map[j][i])
        {
            if (data->map->map[j][i] == '1')
                render_single_tile(data->img_minimap, i, j, ft_pixel(0, 0, 0, 255));
            else
                render_single_tile(data->img_minimap, i, j, ft_pixel(255, 255, 255, 255));
			i++;	
        }
		j++;
    }
}


void draw_player(t_all_data *data)
{
   float center_x;
   float center_y;
   float radius;
  float x;
  float y;
   center_x = data->player->x;
   center_y = data->player->y;
   radius = data->player->radius;
   x = center_x - radius;
   while (x <= center_x + radius) {
         y = center_y - radius;
        while (y <= center_y + radius) {
            if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= radius * radius) {
                mlx_put_pixel(data->img_minimap, x*MINIMAP_SCAL_FACTOR, y*MINIMAP_SCAL_FACTOR , ft_pixel(255, 55, 40, 255));
            }
            y++;
        }
        x++;
    }
    start_raycasting(data);
}