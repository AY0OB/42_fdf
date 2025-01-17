/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_coo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:14 by amairia           #+#    #+#             */
/*   Updated: 2024/12/25 11:45:46 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**line_spliter(int ***coo, char ***lines, int nb_lines, int i)
{
	char	**line_split;

	line_split = NULL;
	if (lines)
		line_split = ft_split((const char *)(lines[0][i]), ' ');
	if (!line_split)
	{
		*lines = free_lines(*lines, nb_lines);
		*coo = free_coo(*coo, nb_lines);
		return (NULL);
	}
	return (line_split);
}

static char	**free_l_split(char ***l_split)
{
	int	i;

	i = 0;
	if (l_split[0])
	{
		while (l_split[0][i])
			free(l_split[0][i++]);
		free(l_split[0]);
	}
	return (NULL);
}

static int	feed_l_coo(int ***coo, char ***line, int size_def, int i)
{
	int		j;
	int		value;

	j = 0;
	if (!line[0])
		return (-1);
	while (line[0][j] && j < size_def)
	{
		value = ft_atoi((const char *)line[0][j]);
		coo[0][i][j] = value;
		j++;
	}
	return (0);
}

void	feed_coo(int ***coo, char ***lines, int nb_lines, int size_def)
{
	int		i;
	int		check;
	char	**l_split;

	i = 0;
	l_split = NULL;
	while (lines[0][i] && i < nb_lines)
	{
		if (l_split)
			l_split = free_l_split(&l_split);
		l_split = line_spliter(coo, lines, nb_lines, i);
		check = feed_l_coo(coo, &l_split, size_def, i);
		if (check == -1)
		{
			*lines = free_lines(*lines, nb_lines);
			*coo = free_coo(*coo, nb_lines);
			if (l_split)
				l_split = free_l_split(&l_split);
			return ;
		}
		i++;
	}
	l_split = free_l_split(&l_split);
}
