/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/07 16:50:24 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dir_parse(t_map *map)
{
    int i = 0;
    
    map->all_map[i] = ft_strtrim(map->all_map[i], " \t");
    map->direc = ft_split(map->all_map[i], '\n');

    while(map->all_map[i] && (map->all_map[i][0] != '1'))
    {
        map->direc[i] =  map->all_map[i];

        i++;
    }
  
    map->direc[i] = NULL;
}

void map_parse(t_map * map)
{
    int i = 6;
    map->map = ft_split(map->all_map[i], '\n');
    while(map->all_map && map->all_map[i])
    {
        map->map[i] =  map->all_map[i];
        i++;
    }

    // map->map[i] = NULL;
}