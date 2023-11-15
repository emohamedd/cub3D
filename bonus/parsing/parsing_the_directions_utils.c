/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_directions_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:15:22 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/15 17:02:49 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	len_of_direction(t_map *map)
{
	int	i;

	i = 0;
	while (map->all_map[i] && (map->all_map[i][0] != '1'))
		i++;
	return (i);
}

void	trim_and_replace(char *str, char replace, char *trim)
{
	int	j;

	(void)replace;
	j = 0;
	while (str[j])
	{
		if (str[j] == ' ' || str[j] == '\t')
			str[j] = *trim;
		j++;
	}
}

void	trim_map_lines(t_map *map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map->all_map[i])
	{
		tmp = map->all_map[i];
		map->all_map[i] = ft_strtrim(map->all_map[i], " \t");
		free(tmp);
		i++;
	}
}

void	check_direction_count(t_map *map)
{
	if (map->dir_len != 6)
		print_err("ERROR : Wrong number of directions\n");
}

void	check_direction_arguments(char **new_array)
{
	if (new_array[2])
	{
		free_2d_arr(new_array);
		print_err("ERROR : Wrong number of directions arguments\n");
	}
}
