/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:04:01 by emohamed          #+#    #+#             */
/*   Updated: 2023/05/14 09:49:44 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udest;
	unsigned char	*usrc;

	if (!dst && !src)
		return (NULL);
	udest = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (udest > usrc)
	{
		while (len--)
			udest[len] = usrc[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
