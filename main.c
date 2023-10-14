/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/10/14 17:06:07 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"
# include <stdio.h>
# include <string.h>




int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}



int mymap[11][15] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
void    draw( mlx_t *mlx, mlx_image_t *img)
{
    int        i;
    int        j;
    int        x;
    int        y;

 

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
                        mlx_put_pixel(img, x, y, ft_pixel(89, 63, 98, 255));
                    else if (mymap[i][j] == 0)
                        mlx_put_pixel(img, x, y, ft_pixel(132, 153, 177, 255));
                    x++;
                }
                y++;
            }
            j++;
        }
        i++;
    }
}



int main()
{
   
    mlx_image_t *img;
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    if (mlx == NULL)
        exit(EXIT_FAILURE);
    // Creates a whole new image.
    img = mlx_new_image(mlx, WIDTH, HEIGHT);
    // Creates a new instance/copy of an already existing image.
    mlx_image_to_window(mlx, img, 0, 0);
    draw(mlx, img);
	mlx_loop(mlx);
    // mlx_terminate(mlx);


    return EXIT_SUCCESS;
}
