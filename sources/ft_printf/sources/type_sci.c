/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sci.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:59:36 by salem             #+#    #+#             */
/*   Updated: 2020/11/28 23:02:57 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		store_sci(long double value)
{
	if (value < 0)
	{
		message_buffer('-');
		value = value * (-1);
	}
	else if (value == 0 && (g_opt.specifier == 'g' || g_opt.specifier == 'G'))
	{
		message_buffer('0');
		return (0);
	}
	count_expoent(value);
	return (0);
}

int		count_expoent(long double value)
{
	int i;

	i = 0;
	while (value > 0 && (value < 1 || value >= 10))
	{
		if (value < 1)
		{
			value = value * 10;
			i--;
		}
		else if (value >= 10)
		{
			value = value / 10;
			i++;
		}
	}
	store_float(value);
	solve_expoent(i);
	return (0);
}

int		solve_expoent(int value)
{
	char *ptr;

	if (g_opt.specifier == 'e' || g_opt.specifier == 'g')
		message_buffer('e');
	else if (g_opt.specifier == 'E' || g_opt.specifier == 'G')
		message_buffer('E');
	if (value < 0)
	{
		message_buffer('-');
		value = value * (-1);
	}
	else if (value >= 0)
		message_buffer('+');
	if (value >= 0 && value < 10)
		message_buffer('0');
	ptr = ft_itoa(value);
	send_buffer(ptr);
	free(ptr);
	return (0);
}
