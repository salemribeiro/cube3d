/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 21:45:19 by salem             #+#    #+#             */
/*   Updated: 2020/11/29 11:30:37 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u_itoa_base(unsigned long long int n)
{
	char	*ptr;

	ptr = NULL;
	if (g_opt.specifier == 'x' || g_opt.specifier == 'X')
	{
		ptr = get_u_base(n, 16);
		if (g_opt.specifier == 'X')
			ptr = str_toupper(ptr);
	}
	else if (g_opt.specifier == 'o')
		ptr = get_u_base(n, 8);
	else if (g_opt.specifier == 'b')
		ptr = get_u_base(n, 2);
	else
		ptr = get_u_base(n, 10);
	return (ptr);
}

char	*get_u_base(t_ulli value, int b)
{
	unsigned long long int	tmp;
	char					*ptr;
	int						d;

	tmp = value;
	ptr = NULL;
	d = 1;
	while (tmp > 0)
	{
		tmp /= b;
		d++;
	}
	ptr = (char*)ft_calloc(sizeof(char), d + 1);
	d = value > 0 ? (d - 2) : (d - 1);
	while (d >= 0 && ptr)
	{
		if (b == 16)
			ptr[d] = (value % b) < 10 ? (value % b) + 48 : (value % b) + 87;
		else
			ptr[d] = (value % b + 48);
		value /= b;
		d--;
	}
	return (ptr);
}

char	*str_toupper(char *source)
{
	int		i;

	i = 0;
	while (source[i])
	{
		source[i] = ft_toupper(source[i]);
		i++;
	}
	return (source);
}
