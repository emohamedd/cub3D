/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:22 by houattou          #+#    #+#             */
/*   Updated: 2023/11/07 13:32:17 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <math.h>
  
  int	get_color_from_texture(int x, int y, mlx_texture_t *texture)
{
	int	i;

	i = (x * 4) + ((y * 4) * texture->width);
	return (texture->pixels[i] << 24 | \
	texture->pixels[i + 1] << 16 | texture->pixels[i + 2] << 8 \
										| texture->pixels[i + 3]);
}
// DDA Function for line generation 
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

void draw_wall_with_texture(t_all_data *data, int id, float ray_angle ,float hor_intercept_x, float vert_intercept_y, float xtx, mlx_texture_t *texture) {
    float new_distance = data->cord->distance * cos(ray_angle - data->player->rotation_angle);
    int wall_height = (SIZE_TITLE / new_distance) * ((SIZE_TITLE * data->map->width) / 2) / tan(FOV_ANGLE / 2);

    if (wall_height > SIZE_TITLE * data->map->height) {
        wall_height = SIZE_TITLE * data->map->height;
    }

    int y_start = ((SIZE_TITLE * data->map->height) / 2) - (wall_height / 2);
    int y_end = ((SIZE_TITLE * data->map->height) / 2) + (wall_height / 2);

    // int texture_x, 
    float ytx;

        // texture_x = (int)hor_intercept_x % SIZE_TITLE;

    // texture_y = ((y_start - ((SIZE_TITLE * data->map->height) / 2) + (wall_height / 2)) / wall_height) * SIZE_TITLE;

    // mlx_texture_t* texture = mlx_load_png("/Users/emohamed/Desktop/C3/bluestone.png");
    float tx_inc = texture->height / (float)wall_height;
    
    // if (texture) {
        // int wall_color = get_color_from_texture(texture_x, texture_y, texture);

        // Draw the wall using draw_line
        // draw_line(data->img, id, y_start, id, y_end, wall_color);
        // y_start++;

        // Overlay textures on top of the wall
        float wallTopPixel;
        while (y_start < y_end) {
            // ytx = ((y_start - ((SIZE_TITLE * data->map->height) / 2) + (wall_height / 2)) / wall_height) * SIZE_TITLE;
            ytx = (y_start - wallTopPixel) * tx_inc;
            
            if (ytx >= texture->height) {
                ytx = 0;
            }

            mlx_put_pixel(data->img, id, y_start, get_color_from_texture(xtx, ytx, texture));
            y_start++;
        }

        // Don't forget to free the loaded texture when done with it
        // mlx_delete_texture(texture);
    }
