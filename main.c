/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <salem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:09:49 by salem             #+#    #+#             */
/*   Updated: 2021/03/28 00:28:03 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	if (argc == 1 || argc > 3)
		message_err(ARGUMENT);
	read_file(argv[1]);
	normalize_map(g_map);
	check_map(g_world.map);
	clear_pointer(g_world.map);
	clear_header();
	return (0);
}
