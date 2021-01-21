/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:03:27 by sfreitas          #+#    #+#             */
/*   Updated: 2020/02/10 15:59:13 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *source, int caracter, size_t len)
{
	unsigned char	*strtemp;
	unsigned char	temp;
	size_t			i;

	strtemp = source;
	temp = (unsigned char)caracter;
	i = 0;
	while (i < len)
	{
		strtemp[i] = temp;
		i++;
	}
	return (source);
}
