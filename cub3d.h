/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:15:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/07 13:31:40 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"
#define END "\033[0m"

// # include "mlx/mlx.h"
# include "get_line/get_next_line.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
    int    rows;

}			t_map;

void print_err(char *s);
int	check_file_cub(char *file);
void readfile(int fd);

#endif