/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:40:52 by salem             #+#    #+#             */
/*   Updated: 2020/12/01 09:08:53 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	store_float(long double value)
{
	if (value < 0)
	{
		message_buffer('-');
		value = value * (-1);
	}
	if (g_opt.precision == -2)
		g_opt.precision = 6;
	convert_char(value, g_opt.precision);
}

int		convert_char(long double value, int precision)
{
	long long int	eint;
	char			*dint;
	int				i;

	i = 0;
	eint = (long long int)value;
	value = (value - (long double)eint) * 10;
	dint = (char*)ft_calloc(precision + 1, sizeof(char));
	while (i <= precision)
	{
		dint[i] = (char)value;
		value = (value - (long double)dint[i]) * 10;
		dint[i] = dint[i] + 48;
		i++;
	}
	if (round_number(dint, precision))
		eint++;
	mount_float(eint, dint);
	free(dint);
	return (0);
}

int		mount_float(long long int eint, char *dint)
{
	char	*ptr;

	ptr = ft_u_itoa_base((unsigned long long int)eint);
	send_buffer(ptr);
	if ((g_opt.specifier == 'g' || g_opt.specifier == 'G') && dint[0])
		remove_zero(dint);
	if (dint[0])
	{
		message_buffer('.');
		send_buffer(dint);
	}
	free(ptr);
	return (0);
}

int		round_number(char *value, int precision)
{
	int i;
	int flag;

	i = precision;
	flag = 0;
	while ((value[i] >= '5' || value[i] == -1) && i > 0)
	{
		if (value[i] == -1)
			value[i] = '0';
		if (value[i - 1] < '9' && value[i - 1] >= 0)
		{
			value[i - 1]++;
			value[precision] = '\0';
			return (0);
		}
		else if (value[i - 1] == '9')
			value[i - 1] = -1;
		i--;
	}
	flag = (value[0] == -1 || (precision == 0 && value[0] >= 53)) ? 1 : 0;
	value[0] = (value[0] == -1) ? 48 : value[0];
	value[precision] = '\0';
	return (flag);
}

int		remove_zero(char *value)
{
	int i;

	i = ft_strlen(value) - 1;
	while (value[i] == '0')
		value[i--] = '\0';
	return (0);
}
