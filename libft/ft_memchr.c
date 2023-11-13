/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:48:03 by emohamed          #+#    #+#             */
/*   Updated: 2023/05/16 15:27:15 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*u;

	i = 0;
	u = (unsigned char *)s;
	while (i < n)
	{
		if (u[i] == (unsigned char)c)
			return (&u[i]);
		i++;
	}
	return (NULL);
}
