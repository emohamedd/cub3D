/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/10/18 13:26:01 by houattou         ###   ########.fr       */
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
    data->player->rotation_angle = M_PI / 2;
    data->player->move_speed = 3;
    data->player->rotation_speed = 3* (M_PI / 180);
}


void draw_player(t_all_data *data)
{
//    t_all_data *data = param;
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
 
    mlx_put_pixel(data->img, cos(data->player->rotation_angle)*30, sin(data->player->rotation_angle)*30, ft_pixel(255, 0, 0, 255));
}



void update( mlx_key_data_t keydata, t_all_data *data)
{
    if(keydata.key == MLX_KEY_UP)
        data->player->y -= 1;
    else if(keydata.key == MLX_KEY_DOWN)
        data->player->x += 1;
    data->player->rotation_angle += data->player->turn_direction * data->player->rotation_speed;
    data->player->x += cos(data->player->rotation_angle) * data->player->move_speed * data->player->wlk_direction;
    data->player->y += sin(data->player->rotation_angle) * data->player->move_speed * data->player->wlk_direction;
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    draw_map(data->mlx, data->img);
    draw_player(data);
}
void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_all_data *data = param;
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN )
        update(keydata, data);
        
  
	else if (keydata.key == MLX_KEY_ESCAPE)
		    mlx_close_window(data->mlx);
         
    printf("here insinde of function: %f\n", data->player->wlk_direction);
    printf("here inside of function: %f\n", data->player->turn_direction);        
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
    
    mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    return EXIT_SUCCESS;
}


