/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:59:29 by sfreitas          #+#    #+#             */
/*   Updated: 2020/02/15 19:18:54 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_toupper(int caracter)
{
	if (caracter >= 97 && caracter <= 122)
		return (caracter - 32);
	return (caracter);
}
