/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:27:47 by sfreitas          #+#    #+#             */
/*   Updated: 2020/02/17 18:21:03 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *source, int caracter)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char*)source;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == caracter)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == caracter)
		return (&ptr[i]);
	return (0);
}
