/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 09:47:11 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/15 14:35:19 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*p;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = count_len(n);
	p = malloc((count_len(n) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	p[i] = '\0';
	i--;
	if (n == 0)
		p[i] = 0 + '0';
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		p[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (p);
}
