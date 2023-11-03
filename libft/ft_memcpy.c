/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:07:39 by houattou          #+#    #+#             */
/*   Updated: 2022/10/29 19:59:38 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	j;

	j = 0;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (j < n)
	{
		((unsigned char *)dst)[j] = ((unsigned char *)src)[j];
		j++;
	}
	return (dst);
}
