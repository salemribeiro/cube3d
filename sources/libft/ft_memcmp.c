/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:36 by sfreitas          #+#    #+#             */
/*   Updated: 2020/05/07 23:17:31 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*value1;
	unsigned char	*value2;
	size_t			i;

	value1 = (unsigned char*)s1;
	value2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (value1[i] != value2[i])
			return (value1[i] - value2[i]);
		i++;
	}
	return (0);
}
