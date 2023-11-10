/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fulling_directions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:45:35 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/10 10:45:44 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int handle_color_key(t_direc *dir)
{
    check_key_color_range(dir);
    
    if (ft_strcmp(dir->key, "F") == 0)
    {
        dir->f = ft_strdup(dir->value);
        return 1;
    }
    else if (ft_strcmp(dir->key, "C") == 0)
    {
        dir->s = ft_strdup(dir->value);
        return 1;
    }
    
    return 0;
}

int check_key_directions(t_direc *dir)
{
    int i = 0;
    
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