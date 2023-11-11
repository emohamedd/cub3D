/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:23:47 by houattou          #+#    #+#             */
/*   Updated: 2022/10/29 20:10:00 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (haystack == ((void *)0) && len == 0)
		return (0);
	while (needle[i])
		i++;
	if (i == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && needle[j] == haystack[i + j] && i + j < len)
				j++;
			if (needle[j] == 0)
				return ((char *)haystack + i);
		}
		if (++i == len)
			return (0);
	}
	return (0);
}
