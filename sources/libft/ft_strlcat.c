/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:53:20 by sfreitas          #+#    #+#             */
/*   Updated: 2020/05/07 20:53:30 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	tdest;
	size_t	tsrc;
	size_t	i;
	size_t	c;

	tdest = ft_strlen(dest);
	tsrc = ft_strlen(src);
	if (tdest >= size)
		return (tsrc + size);
	i = 0;
	c = tdest;
	while (src[i] != '\0' && c < (size - 1) && size != '\0')
	{
		dest[c] = (char)src[i];
		c++;
		i++;
	}
	dest[c] = '\0';
	return (tsrc + tdest);
}
