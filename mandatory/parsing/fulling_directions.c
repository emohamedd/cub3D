/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fulling_directions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:45:35 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/14 15:44:53 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void is_key_duplicate(const t_direc *dir, const char *key) {
    
    if (strcmp(key, "NO") == 0) 
        print_err("Error: Duplicate key 'NO'\n");
     else if (strcmp(key, "SO") == 0) 
       print_err("Error: Duplicate key 'SO'\n");
     else if (strcmp(key, "EA") == 0) 
       print_err("Error: Duplicate key 'EA'\n");
     else if (strcmp(key, "WE") == 0) 
       print_err("Error: Duplicate key 'WE'\n");
     else if (strcmp(key, "F") == 0 )
       print_err("Error: Duplicate key 'F'\n");
     else if (strcmp(key, "C") == 0) 
       print_err("Error: Duplicate key 'C'\n");
    
}

int handle_color_key(t_direc *dir)
{
    check_key_color_range(dir);
    if (ft_strcmp(dir->key, "F") == 0)
    {
        char **str = ft_split(dir->value, 16);
        dir->redf = ft_atoi(str[0]);
        dir->greenf = ft_atoi(str[1]);
        dir->bluef = ft_atoi(str[2]);
        free_2d_arr(str);
        return 1;
    }
    else if (ft_strcmp(dir->key, "C") == 0)
    {
        char **str = ft_split(dir->value, 16);
        dir->redc = ft_atoi(str[0]);
        dir->greenc = ft_atoi(str[1]);
        dir->bluec = ft_atoi(str[2]);
        free_2d_arr(str);
        return 1;
    }
    return 0;
}

int check_key_directions(t_direc *dir)
{
    int i = 0;
    
    // is_key_duplicate(dir, dir->key);
    if (ft_strcmp(dir->key, "NO") == 0)
    {
        dir->no = ft_strdup(dir->value);
        return 1;
    }
    else if (ft_strcmp(dir->key, "SO") == 0)
    {
        dir->so = ft_strdup(dir->value);
        return 1;
    }
    else if (ft_strcmp(dir->key, "WE") == 0)
    {
        dir->we = ft_strdup(dir->value);
        return 1;
    }
    else if (ft_strcmp(dir->key, "EA") == 0)
    {
        dir->ea = ft_strdup(dir->value);
        return 1;
    }
    else
    {
        return handle_color_key(dir);

    }
}