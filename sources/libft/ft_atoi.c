/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <sfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 20:47:11 by sfreitas          #+#    #+#             */
/*   Updated: 2021/04/03 15:26:02 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return ((int)ans * neg);
}
