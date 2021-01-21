/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:10:24 by sfreitas          #+#    #+#             */
/*   Updated: 2020/02/10 15:29:36 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int caracter)
{
	if ((caracter >= 'A' && caracter <= 'Z')
			|| (caracter >= 'a' && caracter <= 'z')
			|| (caracter >= '0' && caracter <= '9'))
		return (1);
	return (0);
}
