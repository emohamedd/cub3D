/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_color_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:38:42 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/16 13:22:39 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	replace_commas_with_separator(t_direc *dir)
{
	int	i;

	i = 0;
	while (dir->value[i])
	{
		if (dir->value[i] == ',')
			dir->value[i] = 16;
		i++;
	}
}

char	**split_color_values(t_direc *dir)
{
	char	**new_array;

	new_array = ft_split(dir->value, 16);
	return (new_array);
}

void	check_color_format_and_range(char **new_array)
{
	int	n;

	n = 0;
	while (n < 3)
	{
		if (!new_array[n] || new_atoi(new_array[n]) < 0
			|| new_atoi(new_array[n]) > 255)
			print_err("ERROR : Wrong color format or range\n");
		n++;
	}
	if (!new_array)
		print_err("ERROR : Wrong color format\n");
}

void	process_color_values(t_direc *dir)
{
	char	**new_array;

	replace_commas_with_separator(dir);
	new_array = split_color_values(dir);
	check_color_format_and_range(new_array);
	free_2d_arr(new_array);
}

void	check_key_color_range(t_direc *dir)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dir->value[i])
	{
		if (!ft_isdigit(dir->value[i]) && dir->value[i] != ',')
			print_err("ERROR : Invalid Char in Colors\n");
		else if (dir->value[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		print_err("ERROR : Wrong number of commas\n");
	process_color_values(dir);
}
