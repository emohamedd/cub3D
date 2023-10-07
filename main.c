/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:14:58 by emohamed          #+#    #+#             */
/*   Updated: 2023/10/07 13:24:18 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int ac , char **av)
{
    int fd;
    if (ac != 2)
        print_err("Wrong number of arguments\n");
    else
    {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            print_err("File not found\n");
        else
            check_file_cub(av[1]);
            readfile(fd);
    }
}