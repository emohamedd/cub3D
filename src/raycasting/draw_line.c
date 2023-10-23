/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:22 by houattou          #+#    #+#             */
/*   Updated: 2023/10/23 10:46:44 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void draw_line(mlx_image_t *image, float x1, float y1, float x2, float y2)
{
    printf("draw_line\n");
    // Calculate the difference in coordinates
    float dx = x2 - x1;
    float dy = y2 - y1;

    // Determine the number of steps required for the longest dimension
    int steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    // Calculate the step size for each dimension
    float x_increment = dx / (float)steps;
    float y_increment = dy / (float)steps;

    // Start drawing at the first point
    float x = x1;
    float y = y1;

    // Iterate through the steps and draw each point
    for (int i = 0; i <= steps; i++)
    {
        // Draw a point at (x, y)
        // printf("x = %f\n", x);
        // printf("y = %f\n", y);
        mlx_put_pixel(image, x, y,ft_pixel(255, 0, 0, 255));

        // Move to the next point
        x += x_increment;
        y += y_increment;
    }
}