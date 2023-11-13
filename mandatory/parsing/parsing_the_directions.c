/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/13 19:47:48 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void trim_and_replace(char *str, char replace, char *trim)
{
    int j = 0;
    while (str[j])
    {
        if (str[j] == ' ' || str[j] == '\t')
            str[j] = *trim;
        j++;
    }
}

void check_direction_arguments(char **new_array)
{
    if (new_array[2])
    {
        print_err("ERROR : Wrong number of directions arguments\n");
    }
}

void process_direction(t_direc *dir, char **new_array)
{
    dir->key = new_array[0];
    dir->value = new_array[1];

    if (check_key_directions(dir) == 0)
        print_err("ERROR : Wrong key\n");
        
}
int len_of_direction(t_map *map)
{
    int i = 0;
    while (map->all_map[i] && (map->all_map[i][0] != '1'))
        i++;
    return i;
}

void dir_parse(t_map *map, t_direc *dir)
{
    int i = 0;
    char **new_array;
    i = 0;
    while(map->all_map[i])
    {
        char *tmp = map->all_map[i];
        map->all_map[i] = ft_strtrim(map->all_map[i], " \t");
        free(tmp);
        i++;
    }
    
    // pause();
    int len = len_of_direction(map);
    map->direc = malloc(sizeof(char *) * (len + 1));
    i = 0;
    while (map->all_map[i] && (map->all_map[i][0] != '1'))
    {
        map->direc[i] = ft_strdup(map->all_map[i]);
        i++;
    }
    map->direc[i] = NULL;
    map->dir_len = i;
    if (map->dir_len != 6)
        print_err("ERROR : Wrong number of directions\n");

    i = 0;
    while (i < map->dir_len)
    {
        trim_and_replace(map->direc[i], 16, " ");
        new_array = ft_split(map->direc[i], ' ');
        free(map->direc[i]);
        check_direction_arguments(new_array);
        process_direction(dir, new_array);
        free_2d_arr(new_array);
        i++;
    }
}
