/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:41 by houattou          #+#    #+#             */
/*   Updated: 2022/10/29 20:10:37 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	int		len;

	len = 0;
	if (!s1 || (s1[0] == '\0' && !set))
		return (NULL);
	start = 0;
	if (*s1)
		len = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[len]) && len)
		len--;
	return (ft_substr(s1, start, (len - start + 1)));
}
