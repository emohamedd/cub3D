/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/10/15 18:55:50 by houattou         ###   ########.fr       */
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

// void draw_player(void *param)
// {
//     t_all_data *data = param;

//     int centerX = data->player->x;
//     int centerY = data->player->y;
//     int radius = data->player->radius;
//     int color = ft_pixel(255, 0, 0, 255);

//     for (int x = centerX - radius; x <= centerX + radius; x++) {
//         for (int y = centerY - radius; y <= centerY + radius; y++) {
//             if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= radius * radius) {
//                 mlx_put_pixel(data->img, x, y, color);
//             }
//         }
//     }
// }

void draw_player(void *param)
{
   t_all_data *data = param;
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

void key_press(void *param) 
{
   
    t_all_data *mlx = param; 
    if(mlx != NULL && mlx->player != NULL)
    {
        if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
            mlx_close_window(mlx->mlx);
        else if (mlx_is_key_down(mlx->mlx, MLX_KEY_UP))
        mlx->player->wlk_direction = +1;
        else if (mlx_is_key_down(mlx->mlx, MLX_KEY_DOWN))
            mlx->player->wlk_direction = -1;
        else if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
            mlx->player->turn_direction = +1;
        else if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
            mlx->player->turn_direction = -1;
        
    }
    printf("here insinde of function: %f\n", mlx->player->wlk_direction);
    printf("here inside of function: %f\n", mlx->player->turn_direction);
    
}
void key_released(void *param)
{
    t_all_data *mlx = param; 
    if(mlx != NULL && mlx->player != NULL)
    {
        if (mlx_is_key_down(mlx->mlx, MLX_KEY_ESCAPE))
            mlx_close_window(mlx->mlx);
        else if (mlx_is_key_down(mlx->mlx, MLX_KEY_UP))
        mlx->player->wlk_direction = 0;
        else if (mlx_is_key_down(mlx->mlx, MLX_KEY_DOWN))
            mlx->player->wlk_direction = 0;
        else if (mlx_is_key_down(mlx->mlx, MLX_KEY_LEFT))
            mlx->player->turn_direction = 0;
        else if (mlx_is_key_down(mlx->mlx, MLX_KEY_RIGHT))
            mlx->player->turn_direction = 0;
        
    }
    printf("here insinde of function: %f\n", mlx->player->wlk_direction);
    printf("here inside of function: %f\n", mlx->player->turn_direction);
}

int main()
{
     t_all_data *data = (t_all_data*)malloc(sizeof(t_all_data));
     data->player = (t_player *)malloc(sizeof(t_player));
   
    
    initialize_player(data);
    data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
  
    if (data->mlx== NULL)
        exit(EXIT_FAILURE);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if(data->img == NULL)
    {
        mlx_close_window(data->mlx);
        ft_putstr_fd(strerror(errno), STDERR_FILENO);
        return(EXIT_FAILURE);
        
    }
    if(mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
    {
        mlx_close_window(data->mlx);
        ft_putstr_fd(strerror(errno), STDERR_FILENO);
        return(EXIT_FAILURE);
    }
    draw_map(data->mlx, data->img);

   
    mlx_loop_hook(data->mlx, draw_player,data);
    mlx_loop_hook(data->mlx,key_press, data );
	mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    return EXIT_SUCCESS;
}


