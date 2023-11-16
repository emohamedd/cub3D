/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:00:37 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/16 12:56:14 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	lenght_of_the_long_line_in_map(t_map *map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			j++;
		}
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

int	only_size_of_map(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i - 6);
}

int	map_height(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		i++;
	}
	return (i);
}

void	player_direction(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'N')
				map->direction = NO;
			else if (map->map[y][x] == 'S')
				map->direction = SO;
			else if (map->map[y][x] == 'W')
				map->direction = WE;
			else if (map->map[y][x] == 'E')
				map->direction = EA;
			x++;
		}
		y++;
	}
}

void	map_parse(t_map *map)
{
	int	j;
	int	i;
	int	len;

	j = 6;
	i = 0;
	len = only_size_of_map(map->all_map);
	if (len < 0)
	{
		print_err("Error Invalid Param\n");
	}
	map->map = malloc(sizeof(char *) * (len + 1));
	while (map->all_map && map->all_map[j])
	{
		map->map[i] = ft_strdup(map->all_map[j]);
		i++;
		j++;
	}
	map->map[i] = NULL;
	map->width = lenght_of_the_long_line_in_map(map);
	map->height = map_height(map);
	player_direction(map);
}
