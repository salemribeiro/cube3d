/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <sfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:57:20 by sfreitas          #+#    #+#             */
/*   Updated: 2021/04/03 15:28:13 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			numberdigits(unsigned n)
{
	int i;

	i = 0;
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*createstring(char *ptr, unsigned int value, char signal, int d)
{
	ptr[--d] = '\0';
	d--;
	while (d >= signal)
	{
		ptr[d] = (value % 10) + '0';
		value /= 10;
		d--;
	}
	if (signal == 1)
		ptr[d] = '-';
	return (ptr);
}

char		*ft_itoa(long long int n)
{
	unsigned int	value;
	int				digits;
	int				signal;
	char			*ptr;

	signal = 0;
	if (n < 0)
	{
		signal = 1;
		value = (unsigned int)n;
		value *= (-1);
	}
	else
		value = (unsigned int)n;
	if (value != 0)
		digits = numberdigits(value) + signal + 1;
	else
		digits = 2;
	ptr = (char*)malloc(sizeof(char) * digits);
	if (!ptr)
		return (NULL);
	return (createstring(ptr, value, signal, digits));
}
