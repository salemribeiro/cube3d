/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:19:07 by salem             #+#    #+#             */
/*   Updated: 2020/11/29 19:17:21 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_hex(char *ptr)
{
	char *tmp;

	tmp = NULL;
	if (g_opt.specifier == 'x')
	{
		tmp = ptr;
		ptr = ft_strjoin("0x", ptr);
	}
	else if (g_opt.specifier == 'X')
	{
		tmp = ptr;
		ptr = ft_strjoin("0X", ptr);
	}
	else if (g_opt.specifier == 'o')
	{
		tmp = ptr;
		ptr = ft_strjoin("0", ptr);
	}
	if (tmp)
		free(tmp);
	return (ptr);
}

char	*manager_minus_hash(char *ptr, char **tmp, char **val, int len)
{
	if ((g_opt.flags & MINUS) == MINUS)
	{
		ptr = (g_opt.flags & HASH) == HASH ? put_hex(ptr) : ptr;
		*tmp = ptr;
		len = ft_strlen(ptr);
		*val = manager_value(ft_strdup(""), g_opt.width - len, ' ');
		ptr = ft_strjoin(ptr, *val);
		free(*val);
		free(*tmp);
	}
	else
	{
		if ((g_opt.flags & ZERO) == ZERO && g_opt.precision != 0)
		{
			ptr = manager_value(ptr, g_opt.width, '0');
			ptr = (g_opt.flags & HASH) == HASH ? put_hex(ptr) : ptr;
		}
		else
		{
			ptr = (g_opt.flags & HASH) == HASH ? put_hex(ptr) : ptr;
			ptr = manager_value(ptr, g_opt.width, ' ');
		}
	}
	return (ptr);
}

void	store_u_int(long long int value)
{
	char	*ptr;
	char	*val;
	char	*tmp;
	int		len;

	value = convert_u_int(value);
	ptr = ft_u_itoa_base(value);
	len = ft_strlen(ptr);
	if (g_opt.precision > 0 && g_opt.precision > len)
		ptr = manager_value(ptr, g_opt.precision, '0');
	else if (g_opt.precision == 0 && value == 0)
	{
		free(ptr);
		ptr = ft_strdup("");
	}
	if ((g_opt.flags & ZERO) == ZERO && g_opt.precision > 0)
		g_opt.flags = g_opt.flags ^ ZERO;
	len = ft_strlen(ptr);
	ptr = manager_minus_hash(ptr, &tmp, &val, len);
	send_buffer(ptr);
	free(ptr);
}

t_ulli	convert_u_int(long long int value)
{
	if (g_opt.length == LONG)
		value = (unsigned long long int)(unsigned long int)value;
	else if (g_opt.length == 0)
		value = (unsigned long long int)(unsigned int)value;
	else if (g_opt.length == H)
		value = (unsigned long long int)(unsigned short int)value;
	else if (g_opt.length == HH)
		value = (unsigned long long int)(unsigned char)value;
	if ((g_opt.flags & SPACE) == SPACE)
		g_opt.flags = g_opt.flags ^ SPACE;
	if ((g_opt.flags & PLUS) == PLUS)
		g_opt.flags = g_opt.flags ^ PLUS;
	return (value);
}
