/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:21:10 by salem             #+#    #+#             */
/*   Updated: 2020/12/01 09:08:05 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			resolve_negative(int value, char option)
{
	if (value < 0 && option == 0)
	{
		value = value * (-1);
		if ((g_opt.flags & MINUS) != MINUS)
			g_opt.flags = g_opt.flags ^ MINUS;
	}
	else if (value < 0 && option == 1)
		value = -2;
	return (value);
}

int			ft_printf(const char *format, ...)
{
	va_list		item;
	int			len;

	clear_struct(1);
	va_start(item, format);
	len = 0;
	while (search_percent((char*)format))
	{
		if (g_opt.specifier == '\0')
		{
			g_opt.count = -1;
			break ;
		}
		if (g_opt.width == -1)
			g_opt.width = resolve_negative(va_arg(item, int), 0);
		if (g_opt.precision == -1)
			g_opt.precision = resolve_negative(va_arg(item, int), 1);
		message_arg_solve(item);
		clear_struct(0);
	}
	message_buffer(END_TEXT);
	len = g_opt.count;
	va_end(item);
	return (len);
}

char		search_percent(char *text)
{
	static int	i;

	while (text[i])
	{
		if (text[i] == '%')
		{
			i += specifier_options((char*)&text[i]);
			return (1);
		}
		else
			message_buffer(text[i]);
		i++;
	}
	i = 0;
	return (0);
}
