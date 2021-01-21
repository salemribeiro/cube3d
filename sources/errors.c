/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 02:57:18 by salem             #+#    #+#             */
/*   Updated: 2021/01/20 03:00:14 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	g_errors[][50] =
{
	"number of arguments",
	"source is not found",
	"can not open file",
	"read file",
	"file was not read in full",
	"resolution is incorrect",
	"source for texture is empty",
	"incorrect value or invalid range for color"

};

int		message_err(const int err_number)
{
	printf("Erros:\n%s\n", g_errors[err_number]);
	exit(1);
}
