/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:12:35 by houattou          #+#    #+#             */
/*   Updated: 2022/10/28 23:07:13 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = -1;
	j = 0;
	if (len > len_s)
		len = len_s;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[++i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
	}
	sub[j] = '\0';
	return (sub);
}
