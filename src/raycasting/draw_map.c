/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:44:22 by houattou          #+#    #+#             */
/*   Updated: 2023/11/02 13:54:02 by houattou         ###   ########.fr       */
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
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
 

bool	is_has_wall(t_all_data *mlx, float x, float y)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (TRUE);
 
    
	x = floor(x / SIZE_TITLE);
	y = floor(y / SIZE_TITLE);
	if (x < 0 || x >=  WIDTH_MAP|| y < 0 || y >= HEIGHT_MAP)
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
                        mlx_put_pixel(img, x*MINIMAP_SCAL_FACTOR, y*MINIMAP_SCAL_FACTOR, ft_pixel(125, 98, 0, 33));
                    else if (mymap[i][j] == 0)
                        mlx_put_pixel(img, x*MINIMAP_SCAL_FACTOR, y*MINIMAP_SCAL_FACTOR, ft_pixel(255, 255, 255, 255));
                    x++;
                }
                y++;
            }
            j++;
        }
        i++;
    }
}






