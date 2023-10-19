/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/10/19 13:37:32 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./include/cub3d.h"

void initialize_player(t_all_data *data)
{
    data->player->x = WIDTH / 2;
    data->player->y = HEIGHT / 2;
    data->player->radius = 3;
    data->player->turn_direction = 0;
    data->player->wlk_direction = 0;
    data->player->rotation_angle = (M_PI/ 2);
    data->player->move_speed = 3;
    data->player->rotation_speed = 3* (M_PI / 180);

    data->player->heigth = 1;
    data->player->width = 1;
    data->player->wlk_speed = 100;
    data->player->turn_speed = 45 * (M_PI / 180);
}


void draw_line(t_all_data *data)
{
 
    float x;
    float y;
    float new_x;
    float new_y;
   x = MINIMAP_SCAL_FACTOR *data->player->x;
   y = MINIMAP_SCAL_FACTOR *data->player->y;
   new_x = x + cos(data->player->rotation_angle) * 40;
   new_y = y + sin(data->player->rotation_angle) * 40;
   mlx_put_pixel(data->img, new_x, new_y, ft_pixel(76, 59, 255, 255));
}
void draw_player(t_all_data *data)
{

   int center_x;
   int center_y;
   int radius;
   int x;
   int y;
   center_x = data->player->x;
   center_y = data->player->y;
   radius = data->player->radius;
   x = center_x - radius;
   while (x <= center_x + radius) {
         y = center_y - radius;
        while (y <= center_y + radius) {
            if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= radius * radius) {
                mlx_put_pixel(data->img, x, y, ft_pixel(255, 0, 0, 255));
            }
            y++;
        }
        x++;
    } 
}



void update_player(t_all_data *mlx, mlx_key_data_t keydata)
{
    float new_x;
    float new_y;
    if (keydata.key == MLX_KEY_S)
    {
        new_x = mlx->player->x + mlx->player->move_speed * cos(mlx->player->rotation_angle);
        new_y = mlx->player->y + mlx->player->move_speed * sin(mlx->player->rotation_angle);
    }
    else if (keydata.key == MLX_KEY_D)
    {
        new_x = mlx->player->x + mlx->player->move_speed * cos(mlx->player->rotation_angle - M_PI / 2);
        new_y = mlx->player->y + mlx->player->move_speed * sin(mlx->player->rotation_angle - M_PI / 2);
    }
    else if (keydata.key == MLX_KEY_A)
    {
        new_x = mlx->player->x + mlx->player->move_speed * cos(mlx->player->rotation_angle + M_PI / 2);
        new_y = mlx->player->y + mlx->player->move_speed * sin(mlx->player->rotation_angle + M_PI / 2);
    }
    else if (keydata.key == MLX_KEY_W)
    {
        new_x = mlx->player->x - mlx->player->move_speed * cos(mlx->player->rotation_angle);
        new_y = mlx->player->y - mlx->player->move_speed * sin(mlx->player->rotation_angle);
    }

    mlx->player->x = new_x;
    mlx->player->y = new_y;

    draw_map(mlx->mlx, mlx->img);
    draw_player(mlx);
    draw_line(mlx);
}
void ratate_player(mlx_key_data_t keydata, t_all_data *data)
{
    printf("dkhlt \n");
    if(keydata.key == MLX_KEY_DOWN)
        data->player->rotation_angle = -M_PI /2;
    else if(keydata.key == MLX_KEY_UP)
        data->player->rotation_angle = M_PI /2;
    else if(keydata.key == MLX_KEY_LEFT)
        data->player->rotation_angle -= 0.1;
    else if(keydata.key == MLX_KEY_RIGHT)
        data->player->rotation_angle += 0.1;
    
    
}
void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_all_data	*mlx;

	mlx = (t_all_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		   mlx_close_window(mlx->mlx);
      
	else if (  keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A \
			|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
                 update_player(mlx, keydata);
    else
        ratate_player(keydata, mlx);             

}

int main()
{
    t_all_data *data = (t_all_data*)malloc(sizeof(t_all_data));
    data->player = (t_player *)malloc(sizeof(t_player));
   
    
    initialize_player(data);
    data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    draw_map(data->mlx, data->img);
    draw_player(data);
    draw_line(data);
    mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    return EXIT_SUCCESS;
}


