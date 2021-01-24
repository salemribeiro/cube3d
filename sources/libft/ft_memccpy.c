/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:21:40 by sfreitas          #+#    #+#             */
/*   Updated: 2020/05/07 23:46:09 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void		*ft_memccpy(void *dest, const void *source, int c, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	carac;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	carac = (unsigned char)c;
	if (!d && !s)
		return (0);
	while (i < len)
	{
		d[i] = s[i];
		if (s[i] == carac)
			return (&d[i] + 1);
		i++;
	}
	return (0);
}
