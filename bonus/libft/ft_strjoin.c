/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:12:35 by houattou          #+#    #+#             */
/*   Updated: 2022/10/27 21:42:21 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*room;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			i++;
	if (s2)
		while (s2[j])
			j++;
	room = (char *)malloc(i + j + 1);
	if (room == NULL)
		return (NULL);
	j = -1;
	while (s1[++j])
		room[j] = s1[j];
	j = -1;
	while (s2[++j])
		room[i + j] = s2[j];
	room[i + j] = 0;
	return (room);
}
