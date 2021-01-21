/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:46:27 by sfreitas          #+#    #+#             */
/*   Updated: 2020/02/17 19:35:10 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *source, int caracter)
{
	int		i;
	int		valid;
	char	*ptn;
	char	*pos;

	i = 0;
	valid = 0;
	ptn = (char*)source;
	while (ptn[i] != '\0')
	{
		if (ptn[i] == caracter)
		{
			pos = &ptn[i];
			valid = 1;
		}
		i++;
	}
	if (valid)
		return (pos);
	if (ptn[i] == caracter)
		return (&ptn[i]);
	return (NULL);
}
