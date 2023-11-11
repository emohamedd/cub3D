/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houattou <houattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:24:36 by houattou          #+#    #+#             */
/*   Updated: 2022/10/29 20:22:15 by houattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*chambre;

	chambre = malloc(size * count);
	if (!chambre)
		return (NULL);
	ft_bzero(chambre, size * count);
	return (chambre);
}
