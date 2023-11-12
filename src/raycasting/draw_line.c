/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:22 by houattou          #+#    #+#             */
/*   Updated: 2023/11/12 14:34:03 by houattou         ###   ########.fr       */
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

void draw_wall_with_texture(t_all_data *data, int id, float ray_angle ,float hor_intercept_x, float vert_intercept_y, float xtx, mlx_texture_t *texture) 
{
    float ytx;
 

    float tx_inc = texture->height / (float)data->exact_wall_height;

        float tmpYstart = ((HEIGHT)/ 2) - (data->exact_wall_height/2);
        float wallTopPixel = tmpYstart;
        while (data->y_start < data->y_end) {
            ytx = (data->y_start - wallTopPixel) * tx_inc;
            
            if (ytx >= texture->height) {
                ytx = 0;
            }

            mlx_put_pixel(data->img, id, data->y_start, get_color_from_texture(xtx, ytx, texture));
            data->y_start++;
            tmpYstart++;
     
        }

        // mlx_delete_texture(texture);
    }
