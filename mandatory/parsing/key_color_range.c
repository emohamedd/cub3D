/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_color_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:38:42 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/13 19:50:42 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_commas(t_direc *dir)
{
	int i;
	int j;

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
}

void	process_color_values(t_direc *dir)
{
	int		i;
	char	**new_array;
	int		n;

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
	i = 0;
	while (new_array[i])
	{
		if (new_atoi(new_array[i]) < 0 || new_atoi(new_array[i]) > 255)
			print_err("ERROR : Wrong color range\n");
		i++;
	}
	free_2d_arr(new_array);
}

// Combine the two functions
void check_key_color_range(t_direc *dir)
{
	check_commas(dir);
	process_color_values(dir);
}
