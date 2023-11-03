/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:53:39 by houattou          #+#    #+#             */
/*   Updated: 2022/10/29 19:53:23 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	signe;
	int	number;

	signe = 1;
	while (*str == '\t' || *str == '\n' || *str == '\f' || *str == '\v'
		|| *str == '\r' || *str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			signe = signe * (-1);
		}
		str++;
	}
	number = 0;
	while (*str >= 48 && *str <= 57)
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (number * signe);
}
