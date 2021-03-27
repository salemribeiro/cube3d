/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_arg_solve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 23:09:08 by sfreitas          #+#    #+#             */
/*   Updated: 2020/12/01 09:13:41 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	message_arg_solve(va_list item)
{
	char sp;

	sp = g_opt.specifier;
	if (sp == 'd' || sp == 'i' || sp == 'u' || sp == 'x' || sp == 'X' ||
	sp == 'o')
		arg_integer(item, sp);
	else if (sp == 'c' || sp == 's' || sp == 'p')
		arg_csp(item, sp);
	else if (sp == 'f' || sp == 'F' || sp == 'e' ||
			sp == 'E' || sp == 'g' || sp == 'G')
		arg_double(item, sp);
	else if (sp == '%')
		store_percent(g_opt.width, g_opt.flags);
	else if (sp == 'n')
		store_n(item);
}

void	arg_integer(va_list item, char sp)
{
	int len;

	len = g_opt.length;
	if (sp == 'd' || sp == 'i')
	{
		if (len == LL)
			store_int(va_arg(item, long long int));
		else if (len == LONG)
			store_int(va_arg(item, long int));
		else
			store_int(va_arg(item, int));
	}
	else if (sp == 'u' || sp == 'x' || sp == 'X' || sp == 'o')
	{
		if (len == LL)
			store_u_int(va_arg(item, unsigned long long int));
		else if (len == LONG)
			store_u_int(va_arg(item, unsigned long int));
		else
			store_u_int(va_arg(item, unsigned int));
	}
}

void	arg_csp(va_list item, char sp)
{
	if (sp == 'c')
		store_char((char)va_arg(item, int));
	else if (sp == 's')
		store_string(va_arg(item, char*), g_opt.width, g_opt.precision,
		g_opt.flags);
	else if (sp == 'p')
		store_u_int(store_pointer(va_arg(item, void*)));
}

void	arg_double(va_list item, char sp)
{
	int len;

	len = g_opt.length;
	if (sp == 'f' || sp == 'F')
		if (len == LLONG)
			store_float(va_arg(item, long double));
		else
			store_float(va_arg(item, double));
	else if (sp == 'e' || sp == 'E')
	{
		if (len == LLONG)
			store_sci(va_arg(item, long double));
		else
			store_sci(va_arg(item, double));
	}
	else if (sp == 'g' || sp == 'G')
	{
		if (len == LLONG)
			store_dgeneric(va_arg(item, long double));
		else
			store_dgeneric(va_arg(item, double));
	}
}

char	*manager_value(char *source, int total, char c)
{
	int		i;
	int		size;
	char	*tmp;
	char	*text;

	i = 0;
	size = total - ft_strlen(source);
	if (size <= 0)
		return (source);
	text = ft_calloc(size + 1, sizeof(char));
	while (i < size)
		text[i++] = c;
	text[i] = '\0';
	tmp = ft_strjoin(text, source);
	free(text);
	free(source);
	return (tmp);
}
