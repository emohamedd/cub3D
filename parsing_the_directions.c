/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/08 11:50:35 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_key_color_range(t_direc *dir)
{
    int i = 0;
    int j = 0;
    printf("---> dir->value = %s\n", dir->value);
    while(dir->value[i])
    {
      if (dir->value[i] == ',')
        j++;
            i++;
    }
    if (j != 2)
        print_err("ERROR : Wrong number of commas\n");
    i = 0;
    while(dir->value[i])
    {
        if (dir->value[i] == ',')
            dir->value[i] = 16;
        i++;
    }
    i = 0;
    char **new_array = ft_split(dir->value, 16);
    int n = 0;
    while ( n < 3)
    {
        if (!new_array[n])
            print_err("ERROR : Wrong color format\n");
        n++;
    }
    if (!new_array)
        print_err("ERROR : Wrong color format\n");
    while(new_array[i])
    {
        if (ft_atoi(new_array[i]) < 0 || ft_atoi(new_array[i]) > 255)
            print_err("ERROR : Wrong color range\n");
        i++;
    }
}
int check_key_directions(t_direc *dir)
{
    int len = ft_strlen(dir->key);

    if (ft_strncmp(dir->key, "NO", len) == 0)
        return (1);
    else if (ft_strncmp(dir->key, "SO", len) == 0)
        return (1);
    else if (ft_strncmp(dir->key, "WE", len) == 0)
        return (1);
    else if (ft_strncmp(dir->key, "EA", len) == 0)
        return (1);
    else if (ft_strncmp(dir->key, "F", len) == 0)
    {
        check_key_color_range(dir);
        return (1);
    }
    else if (ft_strncmp(dir->key, "C", len) == 0)
    {
        check_key_color_range(dir);
        return (1);
    }
    else
        return (0);
}
void dir_parse(t_map *map, t_direc *dir)
{
    int dir_len = 0;
    int i = 0;
    char **new_array;
    map->all_map[i] = ft_strtrim(map->all_map[i], " \t");
    map->direc = ft_split(map->all_map[i], '\n');

    while(map->all_map[i] && (map->all_map[i][0] != '1'))
    {
        map->direc[i] =  map->all_map[i];
        i++;
    }
    dir_len = i;
    if (dir_len != 6)
        print_err("ERROR : Wrong number of directions\n");
    i = 0;
    int j = 0;
    while(i < dir_len)
    {
        j = 0;
        while (map->direc[i][j])
        {
            if (map->direc[i][j] == ' ' || map->direc[i][j] == '\t')
                map->direc[i][j] = 16;
            j++;
        }
        i++;    
    }
    i = 0;
    while (i < dir_len)
    {
        new_array = ft_split(map->direc[i], 16);
        dir->key = new_array[0];
        dir->value = new_array[1];
        if (check_key_directions(dir) == 0)
            print_err("ERROR : Wrong key\n");
        i++;
    }
    
        map->direc[i] = NULL;
}

