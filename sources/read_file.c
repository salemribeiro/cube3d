/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salem <salem@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:10:05 by salem             #+#    #+#             */
/*   Updated: 2021/04/01 23:56:50 by salem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_next_line.h"

static void	check_full(void)
{
	char check;

	check = 1;
	check = (g_header.resolution[0] || g_header.resolution[1]) && check ? 1 : 0;
	check = g_header.nor_texture && check ? 1 : 0;
	check = g_header.sou_texture && check ? 1 : 0;
	check = g_header.wes_texture && check ? 1 : 0;
	check = g_header.eas_texture && check ? 1 : 0;
	check = g_header.spr_texture && check ? 1 : 0;
	check = (g_header.ce_color[0] || g_header.ce_color[1] || g_header.ce_color[2]) &&
	check ? 1 : 0;
	check = (g_header.fl_color[0] || g_header.fl_color[1] || g_header.fl_color[2]) &&
	check ? 1 : 0;
	g_header.full = check;
}

static int	build_to_memory(int fd)
{
	int		ret;
	char	*line;

	ret = get_next_line(fd, &line);
	while (line)
	{
		if (!g_header.full)
		{
			get_header(line);
			check_full();
		}
		else if (check_header() == SUCCESS)
			get_map(line);
		free(line);
		if (ret <= 0)
		{
			if (!g_header.full)
				message_err(INVALID_FILE);
			break ;
		}
		ret = get_next_line(fd, &line);
	}
	g_map = change_matriz(g_map, NULL, g_count_line);
	return (SUCCESS);
}

int			read_file(const char *source)
{
	int	fd;

	fd = open(source, O_RDONLY);
	if (fd < 2)
		message_err(OPEN_FILE);
	build_to_memory(fd);
	return (SUCCESS);
}
