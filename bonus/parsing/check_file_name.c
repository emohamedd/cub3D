/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:09:59 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/14 17:03:11 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../libft/libft.h"

int	check_file_cub(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + (len - 4), ".cub", 4) == 0)
		return (1);
	else
	{
		print_err("The string does not end with .cub\n");
	}
	return (0);
}
