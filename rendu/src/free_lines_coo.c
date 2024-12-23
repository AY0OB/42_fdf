/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines_coo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:49:26 by amairia           #+#    #+#             */
/*   Updated: 2024/12/03 15:49:47 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**free_lines(char **lines, int nb_lines)
{
	if (lines)
	{
		while (nb_lines >= 0)
		{
			if (lines[nb_lines])
				free(lines[nb_lines]);
			nb_lines--;
		}
		free(lines);
	}
	return (NULL);
}

int	**free_coo(int **coo, int nb_lines_coo)
{
	nb_lines_coo--;
	if (coo)
	{
		while (nb_lines_coo >= 0)
		{
			if (coo[nb_lines_coo])
				free(coo[nb_lines_coo]);
			nb_lines_coo--;
		}
		free(coo);
	}
	return (NULL);
}
