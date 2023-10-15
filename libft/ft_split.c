/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:35:33 by houattou          #+#    #+#             */
/*   Updated: 2022/10/29 21:25:04 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countchar(char const *str, char sep)
{
	size_t	count;
	size_t	j;

	count = 0;
	j = 0;
	while (str[j] && str[j] != sep)
	{
		count++;
		j++;
	}
	return (count);
}

int	ft_countword(char *str, char sep)
{
	int	wordc;
	int	i;

	i = 0;
	wordc = 0;
	while (*str)
	{
		if (*str != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			wordc++;
		str++;
	}
	return (wordc);
}

int	ft_repeatedsep(char *s, char sep)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[0] == sep)
		{
			count++;
			s++;
		}
		break ;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		numberwords;
	int		count;
	char	*str;
	char	**result;

	if (!s)
		return (NULL);
	str = (char *)s;
	numberwords = ft_countword(str, c);
	result = ft_calloc(numberwords + 1, sizeof(char *));
	if (!result)
		return (NULL);
	count = 0;
	while (count < numberwords)
	{
		str += ft_repeatedsep(str, c);
		if (str[0] && str[0] != c)
			result[count] = ft_substr(str, 0, ft_countchar(str, c));
		if (!result[count])
			return (NULL);
		str += ft_countchar(str, c);
		count++;
	}
	return (result);
}
