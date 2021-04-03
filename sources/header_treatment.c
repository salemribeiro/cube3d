/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfreitas <sfreitas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 12:10:47 by salem             #+#    #+#             */
/*   Updated: 2021/04/03 17:24:23 by sfreitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int			check_header(void)
{
	if (check_rgb(g_header.ce_color) == INCORRECT_COLOR)
		message_err(INCORRECT_COLOR);
	else if (check_rgb(g_header.fl_color) == INCORRECT_COLOR)
		message_err(INCORRECT_COLOR);
	return (SUCCESS);
}

static int	get_resolution(const char *line)
{
	char **word;

	word = ft_split(line, ' ');
	if (!word[1] || !word[2] || word[3] ||
		g_header.resolution[0] != 0 || g_header.resolution[1] != 0)
		message_err(RESOLUTION_ERRO);
	g_header.resolution[0] = ft_atoi(word[1]);
	g_header.resolution[1] = ft_atoi(word[2]);
	clear_pointer(word);
	return (SUCCESS);
}

static int	get_texture(const char *line)
{
	char **word;

	word = ft_split(line, ' ');
	if (!word[1])
		message_err(TEXTURE_EMPTY);
	if (!g_header.nor_texture && !ft_strncmp(word[0], "NO", 2) && !word[2])
		g_header.nor_texture = ft_strdup(word[1]);
	else if (!g_header.sou_texture && !ft_strncmp(word[0], "SO", 2) && !word[2])
		g_header.sou_texture = ft_strdup(word[1]);
	else if (!g_header.wes_texture && !ft_strncmp(word[0], "WE", 2) && !word[2])
		g_header.wes_texture = ft_strdup(word[1]);
	else if (!g_header.eas_texture && !ft_strncmp(word[0], "EA", 2) && !word[2])
		g_header.eas_texture = ft_strdup(word[1]);
	else if (!g_header.spr_texture && !ft_strncmp(word[0], "S", 1) && !word[2])
		g_header.spr_texture = ft_strdup(word[1]);
	else
		message_err(INVALID_TEXTURE);
	clear_pointer(word);
	return (SUCCESS);
}

static int	get_color(const char *line)
{
	char	**word;
	char	**color;

	word = ft_split(line, ' ');
	color = ft_split(word[1], ',');
	if (!color[0] || !color[1] || !color[2] || color[3] || word[2])
		message_err(INCORRECT_COLOR);
	if (!ft_strncmp(word[0], "C", 1))
	{
		if (g_header.ce_color[0] || g_header.ce_color[1] ||
			g_header.ce_color[2])
			message_err(INCORRECT_COLOR);
		add_color(color, 'C');
	}
	else if (!ft_strncmp(word[0], "F", 1))
	{
		if (g_header.fl_color[0] || g_header.fl_color[1] ||
			g_header.fl_color[2])
			message_err(INCORRECT_COLOR);
		add_color(color, 'F');
	}
	clear_pointer(word);
	clear_pointer(color);
	return (SUCCESS);
}

int			get_header(const char *line)
{
	if (ft_strlen(line))
	{
		if (line[0] == 'R' && line[1] == ' ')
			get_resolution(line);
		else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
			get_texture(line);
		else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
			get_texture(line);
		else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
			get_texture(line);
		else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
			get_texture(line);
		else if (line[0] == 'S' && line[1] == ' ')
			get_texture(line);
		else if (line[0] == 'C' && line[1] == ' ')
			get_color(line);
		else if (line[0] == 'F' && line[1] == ' ')
			get_color(line);
		else
			verify_line(line);
	}
	return (0);
}
