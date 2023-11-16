/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/16 12:43:46 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	process_direction(t_direc *dir, char **new_array)
{
	dir->key = new_array[0];
	dir->value = new_array[1];
	if (check_key_directions(dir) == 0)
	{
		free_2d_arr(new_array);
		print_err("ERROR : Wrong key\n");
	}
}

void	allocate_and_copy_directions(t_map *map, int len)
{
	int	i;

	i = 0;
	map->direc = malloc(sizeof(char *) * (len + 1));
	while (map->all_map[i] && (map->all_map[i][0] != '1'))
	{
		map->direc[i] = ft_strdup(map->all_map[i]);
		i++;
	}
	map->direc[i] = NULL;
	map->dir_len = i;
}

void	check_for_duplicate_keys(t_map *map)
{
	int	j;
	int	k;

	j = 0;
	while (j < map->dir_len)
	{
		k = 0;
		while (k < map->dir_len)
		{
			if (j != k && ft_strncmp(map->direc[j], map->direc[k], 1) == 0)
				print_err("ERROR : Duplicate key\n");
			k++;
		}
		j++;
	}
}

void	dir_parse(t_map *map, t_direc *dir)
{
	int		len;
	int		i;
	char	**new_array;

	trim_map_lines(map);
	len = len_of_direction(map);
	allocate_and_copy_directions(map, len);
	check_direction_count(map);
	check_for_duplicate_keys(map);
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
