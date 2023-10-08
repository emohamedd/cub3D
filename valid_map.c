/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:36:44 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/08 21:15:54 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int valid_map(t_map *map)
{
    int i = 0;
    int j;
    while(map->map[i])
    {
        j = 0;
        while(map->map[i][j])
        {
            // printf("%c\n", map->map[i][j]);
            if (map->map[i][j] == '0')
            {
                // printf("%c", map->map[i][j]);
                if ((map->map[i][j - 1] == ' ' || map->map[i][j - 1] == '\0') || 
                    (map->map[i][j + 1] == ' ' || map->map[i][j + 1] == '\0') || 
                    (map->map[i - 1][j] == ' ' || map->map[i - 1][j] == '\0') || 
                    (map->map[i + 1][j] == ' ' || map->map[i + 1][j] == '\0'))
                    return (0);
            }
                j++;
        }
        i++;
    }
    return (1);
}
int check_map_char(t_map *map)
{
    int i = 0;
    int j;
    int n_count = 0;
    int s_count = 0;
    int e_count = 0;
    int w_count = 0;
    int all_count = 0;
    while(map->map[i])
    {
        j = 0;
        while(map->map[i][j])
        {
            if (map->map[i][j] != '0' && map->map[i][j] != '1' &&
             map->map[i][j] != 'N' && map->map[i][j] != 'S' &&
              map->map[i][j] != 'E' && map->map[i][j] != 'W' &&
               map->map[i][j] != ' ')
                return (0);
            if (map->map[i][j] == 'N')
            {
                n_count++;
                all_count++;
            }
            else if (map->map[i][j] == 'S')
            {
                s_count++;
                all_count++;
            }
            else if (map->map[i][j] == 'E')
            {
                e_count++;
                all_count++;
            }
            else if (map->map[i][j] == 'W')
            {
                w_count++;
                all_count++;
            }
            j++;
        }
        i++;
    }
    if ((n_count > 1 || s_count > 1 || e_count > 1 || w_count > 1) || all_count > 1)
        return (0);
    return (1);
}
