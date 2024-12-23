/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:44:34 by amairia           #+#    #+#             */
/*   Updated: 2024/12/23 06:16:56 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	line_count(char *fic)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(fic, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

static char	**lines_creator(char *fic, int *nb_lines)
{
	char	**lines;
	char	*line;
	int		fd;
	int		i;

	*nb_lines = line_count(fic);
	if (*nb_lines == 0)
		return (NULL);
	lines = ft_calloc(*nb_lines + 1, sizeof(char *));
	if (!lines)
		return (NULL);
	i = 0;
	fd = open(fic, O_RDONLY);
	line = get_next_line(fd);
	lines[i] = line;
	while (line)
	{
		line = get_next_line(fd);
		i++;
		lines[i] = line;
	}
	if (!lines[*nb_lines - 1])
		lines = free_lines(lines, *nb_lines);
	return (lines);
}

int	**parsing(char *fic, int *nb_lines, int *size_def)
{
	char	**lines;
	int		**coo;

	lines = lines_creator(fic, nb_lines);
	if (!lines)
		return (NULL);
	coo = coo_creator(&lines, nb_lines, size_def);
	if (coo)
		feed_coo(&coo, &lines, *nb_lines, *size_def);
	if (lines)
		lines = free_lines(lines, *nb_lines);
	else
		if (coo)
			coo = free_coo(coo, *nb_lines);
	return (coo);
}
