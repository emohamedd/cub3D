/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:00:37 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/08 20:55:07 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int only_size_of_map(char **s)
{
  int i = 0;
    while(s[i])
    {
        // printf("%s\n", s[i]);
        i++;
    }
    return (i - 6);
}

void map_parse(t_map *map)
{
    int j = 6;
    int i = 0;
    int len = only_size_of_map(map->all_map);
    // printf("len = %d\n", len);
 
    map->map = malloc(sizeof(char *) * len + 1);
    while(map->all_map && map->all_map[j])
    {
        map->map[i] =  map->all_map[j];
        // printf("%s\n", map->map[i]);
        i++;
        j++;
    }
      map->map[i] = NULL;
    
}