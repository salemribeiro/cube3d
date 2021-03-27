/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:55:10 by salem             #+#    #+#             */
/*   Updated: 2020/12/03 17:30:41 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*manager_precision(char *ptr, t_lli value, int *signal, int len)
{
	char	*tmp;

	if (g_opt.precision && g_opt.precision >= len)
	{
		ptr = manager_value(ptr, g_opt.precision, '0');
		if (*signal == -1)
		{
			tmp = ptr;
			ptr = ft_strjoin("-", ptr);
			*signal = 1;
			free(tmp);
		}
		else
			ptr = solve_signal(ptr, *signal);
	}
	else if (g_opt.precision == 0 && value == 0)
	{
		free(ptr);
		ptr = ft_strdup("");
	}
	return (ptr);
}

static char	*manager_width(char *ptr, int *signal)
{
	if ((g_opt.flags & ZERO) == ZERO && g_opt.precision != 0)
	{
		g_opt.width = ((*signal == -1 || (g_opt.flags & PLUS) == PLUS ||
		(g_opt.flags & SPACE) == SPACE) && g_opt.width > 0) ?
		g_opt.width - 1 : g_opt.width;
		ptr = manager_value(ptr, g_opt.width, '0');
		ptr = solve_signal(ptr, *signal);
	}
	else
	{
		if (ptr[0] != '-' && *signal == -1)
			ptr = solve_signal(ptr, *signal);
		else if (ptr[0] != '-')
			ptr = solve_signal(ptr, *signal);
		ptr = manager_value(ptr, g_opt.width, ' ');
	}
	return (ptr);
}

static char	*manager_minus(char *ptr, int *signal, char *caractere)
{
	int		len;
	char	*tmp;
	char	*man;

	len = ft_strlen(ptr);
	if ((g_opt.flags & MINUS) == MINUS)
	{
		tmp = ptr;
		if (*signal == -1 || (g_opt.flags & PLUS) == PLUS ||
			(g_opt.flags & SPACE) == SPACE)
			len++;
		man = manager_value(ft_strdup(""), g_opt.width - len, *caractere);
		ptr = ft_strjoin(ptr, man);
		ptr = solve_signal(ptr, *signal);
		free(tmp);
		free(man);
	}
	else
		ptr = manager_width(ptr, signal);
	return (ptr);
}

void		store_int(long long int value)
{
	char	*ptr;
	int		len;
	int		signal;
	char	caractere;

	signal = value < 0 ? -1 : 1;
	value = convert_int(value) * signal;
	ptr = ft_itoa(value);
	len = ft_strlen(ptr);
	caractere = ' ';
	ptr = manager_precision(ptr, value, &signal, len);
	if ((g_opt.flags & ZERO) == ZERO && g_opt.precision > 0)
		g_opt.flags = g_opt.flags ^ ZERO;
	len = ft_strlen(ptr);
	ptr = manager_minus(ptr, &signal, &caractere);
	send_buffer(ptr);
	free(ptr);
}

t_lli		convert_int(long long int value)
{
	if (g_opt.length == LONG)
		value = (long long int)(long int)value;
	else if (g_opt.length == 0)
		value = (long long int)(int)value;
	else if (g_opt.length == H)
		value = (long long int)(short int)value;
	else if (g_opt.length == HH)
		value = (long long int)(char)value;
	return (value);
}
