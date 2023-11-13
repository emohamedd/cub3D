/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emohamed <emohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:21:49 by emohamed          #+#    #+#             */
/*   Updated: 2023/11/13 13:02:20 by emohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_s_lenght(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

char	*allocat_s(const char *s, char c)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	p = malloc(sizeof(char *) * (count_s_lenght(s, c) + 1));
	if (!p)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			p[j] = allocat_s(&s[i], c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	p[j] = NULL;
	return (p);
}

// int main()
// {
// 	char *s = "    Hello           World !     ";

// 	char **str = ft_split(s, ' ');
// 	printf("%s\n", str[0]);
// }