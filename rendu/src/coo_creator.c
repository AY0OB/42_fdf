/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coo_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:36:42 by amairia           #+#    #+#             */
/*   Updated: 2024/12/24 17:10:44 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	skip_space(const char *str, int *i)
{
	if (str[*i] == ' ' || str[*i] == '\n')
	{
		while (str[*i] && (str[*i] == ' ' || str[*i] == '\n'))
			*i = *i + 1;
	}
}

static int	check_content(const char *str)
{
	int	i;
	int	count;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	while (str[i])
	{
		skip_space(str, &i);
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] && str[i] >= '0' && str[i] <= '9')
				i++;
			count += 1;
		}
		if ((str[i] && ((str[i] <= '0' || str[i] >= '9') && str[i] != ' '
					&& str[i] != '\n')) || (str [i] && (str[i - 1] == '-'
					|| str[i - 1] == '+')))
			return (-1);
	}
	return (count);
}

int	**coo_creator(char ***lines, int *nb_lines, int *size_def)
{
	int	i;
	int	size;
	int	**coo;

	*size_def = check_content((const char *)lines[0][0]);
	if (*size_def <= 0)
	{
		*lines = free_lines(*lines, *nb_lines);
		return (NULL);
	}
	coo = ft_calloc(*nb_lines, sizeof(int *));
	i = 0;
	while (lines[0][i])
	{
		size = check_content((const char *)(lines[0][i]));
		if (size != *size_def)
		{
			*lines = free_lines(*lines, *nb_lines);
			coo = free_coo(coo, i);
			return (coo);
		}
		coo[i] = ft_calloc(*size_def, sizeof(int));
		i++;
	}
	return (coo);
}
