/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:00:37 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/09 16:07:29 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	map_parse(t_map *map)
{
	int	j;
	int	i;
	int	len;

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
	map->map[i] = NULL;
}
