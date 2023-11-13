/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:38:12 by emohamed          #+#    #+#             */
/*   Updated: 2023/08/04 18:55:26 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	sizee;
	void	*p;
	// size_t	i;

	p = NULL;
	// i = 0;
	sizee = count * size;
	p = malloc(sizee);
	if (!p)
		return (NULL);
	ft_bzero(p, sizee);
	return (p);
}
// int main()
// {
// 	char *str;
// 			str = (char *)ft_calloc(30, 1);
//     if (!str)
//         write(1, "NULL", 4);
//     else
//         write(1, str, 30);
// }
