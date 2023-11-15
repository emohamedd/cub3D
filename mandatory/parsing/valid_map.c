/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:36:44 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/15 15:21:07 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	lenght_count(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	valid_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == '0' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'S' || map->map[i][j] == 'N'
				|| map->map[i][j] == 'W')
			{
				if (i - 1 < 0 || i + 1 >= map->height)
					return (0);
				if ((map->map[i][j - 1] == ' ' || map->map[i][j - 1] == '\0')
					|| (map->map[i][j + 1] == ' ' || map->map[i][j + 1] == '\0')
					|| (map->map[i - 1][j] == ' ' || map->map[i - 1][j] == '\0')
					|| (map->map[i + 1][j] == ' ' || map->map[i
						+ 1][j] == '\0'))
					return (0);
			}
		}
	}
	return (1);
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ');
}

int	count_player(t_map *map, char player)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == player)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_map_char(t_map *map)
{
	int	i;
	int	j;
	int	all_count;

	i = 0;
	all_count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!is_valid_char(map->map[i][j]))
				return (0);
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				all_count += count_player(map, map->map[i][j]);
			j++;
		}
		i++;
	}
	if (all_count != 1)
		return (0);
	return (1);
}
