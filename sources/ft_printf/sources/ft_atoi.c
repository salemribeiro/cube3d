/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:47:11 by sfreitas          #+#    #+#             */
/*   Updated: 2020/11/28 21:19:40 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int		ft_spaces(int i, char *str)
{
	while ((str[i] == '\t' || str[i] == '\v' || str[i] == '\f') ||
			(str[i] == '\f' || str[i] == '\r' || str[i] == '\n') ||
			(str[i] == ' '))
		i++;
	return (i);
}

long long int	ft_atoi(const char *str)
{
	char						*atstr;
	unsigned long long int		ans;
	int							neg;
	int							i;

	atstr = (char*)str;
	neg = 1;
	ans = 0;
	i = 0;
	i = ft_spaces(i, atstr);
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9' && ans <= LONG_MAX)
	{
		ans = (ans * 10) + (str[i] - 48);
		i++;
	}
	if (ans > LONG_MAX && neg == 1)
		return (-1);
	else if (ans > LONG_MAX && neg == -1)
		return (0);
	else
		return ((long long int)ans * neg);
}
