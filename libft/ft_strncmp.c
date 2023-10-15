/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:52:13 by houattou          #+#    #+#             */
/*   Updated: 2022/10/29 20:09:49 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		dif;

	dif = 0;
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			dif = (int)(unsigned char)s1[i] - (int)(unsigned char)s2[i];
			if (dif > 0)
			{
				return (1);
			}
			if (dif < 0)
			{
				return (-1);
			}
			break ;
		}
		i++;
	}
	return (0);
}
