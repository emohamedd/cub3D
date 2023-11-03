/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:00:37 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/02 19:48:57 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int lenght_of_the_long_line_in_map(t_map * map)
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = 0;
	while (map->all_map[i])
	{
		j = 0;
		while (map->all_map[i][j])
		{
			j++;
		}
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

int only_size_of_map(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i - 6);
}

void map_parse(t_map *map)
{
	int j;
	int i;
	int len;

	j = 6;
	i = 0;
	len = only_size_of_map(map->all_map);
	map->map = malloc(sizeof(char *) * len + 1);
	while (map->all_map && map->all_map[j])
	{
		map->map[i] = map->all_map[j];
		i++;
		j++;
	}
	map->width = lenght_of_the_long_line_in_map(map);
	map->height = len;
	map->map[i] = NULL;

}
