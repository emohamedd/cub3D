/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:25:57 by houattou          #+#    #+#             */
/*   Updated: 2022/10/28 17:20:40 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			j;
	unsigned char	a;

	a = (unsigned char)c;
	j = 0;
	while (j < len)
	{
		((unsigned char *)b)[j] = a;
		j++;
	}
	return (b);
}
