/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_generic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:50:36 by salem             #+#    #+#             */
/*   Updated: 2020/11/30 20:37:46 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_dgeneric(long double value)
{
	if (value < 0)
	{
		message_buffer('-');
		value = value * (-1);
	}
	if (g_opt.precision == -2)
		g_opt.precision = 6;
	else if (g_opt.precision == 0)
		g_opt.precision = 1;
	count_value(value, g_opt.precision);
}

int		count_value(long double value, int precision)
{
	char *ptr;

	ptr = ft_u_itoa_base((long long int)value);
	if ((int)ft_strlen(ptr) > precision && precision > 0)
	{
		g_opt.precision--;
		store_sci(value);
	}
	else
	{
		if (precision > 0)
			g_opt.precision -= (int)ft_strlen(ptr);
		else
			g_opt.precision = 0;
		store_float(value);
	}
	free(ptr);
	return (0);
}
