/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:00:37 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/08 10:00:48 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_parse(t_map * map)
{
    int i = 6;
    map->map = ft_split(map->all_map[i], '\n');
    while(map->all_map && map->all_map[i])
    {
        map->map[i] =  map->all_map[i];
        printf("%s\n", map->map[i]);
        i++;
    }
      map->map[i] = NULL;
    

    map->map[i] = NULL;
}