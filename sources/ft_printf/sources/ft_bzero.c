/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:43:00 by sfreitas          #+#    #+#             */
/*   Updated: 2020/02/10 15:43:32 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *source, size_t len)
{
	unsigned char	*strtemp;
	size_t			i;

	strtemp = source;
	i = 0;
	while (i < len)
	{
		strtemp[i] = '\0';
		i++;
	}
}
