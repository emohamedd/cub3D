/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:02:58 by houattou          #+#    #+#             */
/*   Updated: 2023/10/18 17:36:34 by houattou         ###   ########.fr       */
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
    data->player->rotation_angle = 3 * (M_PI / 2);
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
}



void update_player(t_all_data *mlx, mlx_key_data_t keydata)
{
    float new_x;
    float new_y;
    float direction_angle;
    int sign;
    float spin_speed;

    direction_angle = mlx->player->rotation_angle;
    sign = 1;
    spin_speed = 0.1;

    if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D)
    {
        printf("ana hna\n");
        if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_A)
        {
            printf("hello\n");
            sign = -1;
        }

        else if(keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_A)
            direction_angle += M_PI / 2;



    }
   else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT)
        {
            printf("Key pressed: %d\n", keydata.key); 
            printf("dkhlt\n");

            if (keydata.key == MLX_KEY_LEFT)
            { 
                mlx->player->rotation_angle -= 0.1;
                printf("left\n");
                // mlx->player->move_speed += 1.2;
                // sign = -1;
                printf("Decreased move speed: %f\n", mlx->player->move_speed);
            }
            else if (keydata.key == MLX_KEY_RIGHT)
            {
                 printf("righ\n");
                 mlx->player->rotation_angle += 0.1;
                mlx->player->move_speed -= 1.2;  
                sign = 1;
                printf("Decreased move speed: %f\n", mlx->player->move_speed);
            }
           
        }

    new_x = mlx->player->x + sign * mlx->player->move_speed * cos(direction_angle);
    new_y = mlx->player->y + sign * mlx->player->move_speed * sin(direction_angle);
    mlx->player->x = new_x;
    mlx->player->y = new_y;
    draw_map(mlx->mlx, mlx->img);
    draw_player(mlx);
    if(keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(mlx->mlx);

}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_all_data	*mlx;

	mlx = (t_all_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx->mlx);
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT \
			|| keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_A \
			|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_D)
		update_player(mlx, keydata);
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


