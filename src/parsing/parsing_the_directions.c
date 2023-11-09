/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_the_directions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:48 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/09 19:29:50 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"

void	check_key_color_range(t_direc *dir)
{
	int		i;
	int		j;
	char	**new_array;
	int		n;

	i = 0;
	j = 0;
	while (dir->value[i])
	{
		if (dir->value[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		print_err("ERROR : Wrong number of commas\n");
	i = 0;
	while (dir->value[i])
	{
		if (dir->value[i] == ',')
			dir->value[i] = 16;
		i++;
	}
	i = 0;
	new_array = ft_split(dir->value, 16);
	n = 0;
	while (n < 3)
	{
		if (!new_array[n])
			print_err("ERROR : Wrong color format\n");
		n++;
	}
	if (!new_array)
		print_err("ERROR : Wrong color format\n");
	while (new_array[i])
	{
		if (new_atoi(new_array[i]) < 0 || new_atoi(new_array[i]) > 255)
			print_err("ERROR : Wrong color range\n");
		i++;
	}
}

int	check_key_directions(t_direc *dir)
{
	int i  = 0;
	// while(i < 6)
	// {
	// 	 printf(" --- > dir->key[i] = %s\n", dir->key);
	// 	 i++;
	// }
	if (ft_strcmp(dir->key, "NO") == 0)
	{
		dir->no = ft_strdup(dir->value);
		return (1);
	}
	else if (ft_strcmp(dir->key, "SO") == 0)
	{
		dir->so = ft_strdup(dir->value);
		return (1);
	}
	else if (ft_strcmp(dir->key, "WE") == 0)
	{
		dir->we = ft_strdup(dir->value);
		return (1);
	}
	else if (ft_strcmp(dir->key, "EA") == 0)
	{
		dir->ea = ft_strdup(dir->value);
		return (1);
	}
	else if (ft_strcmp(dir->key, "F") == 0)
	{
		check_key_color_range(dir);
		dir->f = ft_strdup(dir->value);
		return (1);
	}
	else if (ft_strcmp(dir->key, "C") == 0)
	{
		check_key_color_range(dir);
		dir->s = ft_strdup(dir->value);
		return (1);
	}
	else
		return (0);
}

void	dir_parse(t_map *map, t_direc *dir)
{
	int		i;
	char	**new_array;
	int		j;

	i = 0;
	map->all_map[i] = ft_strtrim(map->all_map[i], " \t");
	map->direc = ft_split(map->all_map[i], '\n');
	while (map->all_map[i] && (map->all_map[i][0] != '1'))
	{
		map->direc[i] = map->all_map[i];
		i++;
	}
	map->dir_len = i;
	if (map->dir_len != 6)
		print_err("ERROR : Wrong number of directions\n");
	i = 0;
	j = 0;
	while (i < map->dir_len)
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
	while (i < map->dir_len)
	{
		new_array = ft_split(map->direc[i], 16);
		if (new_array[2])
			print_err("ERROR : Wrong number of directions arguments\n");
		dir->key = new_array[0];
		dir->value = new_array[1];
		if (check_key_directions(dir) == 0)
			print_err("ERROR : Wrong key\n");
		i++;
	}
	map->direc[i] = NULL;
}
