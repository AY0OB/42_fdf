/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:13:37 by amairia           #+#    #+#             */
/*   Updated: 2025/01/17 11:14:35 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_all(t_stock *fdf)
{
	if (fdf)
	{
		if (fdf->window)
		{
			mlx_clear_window(fdf->mlx, fdf->window);
			mlx_destroy_window(fdf->mlx, fdf->window);
		}
		if (fdf->mlx)
		{
			mlx_destroy_display(fdf->mlx);
			free(fdf->mlx);
		}
		if (fdf->coo)
			free_coo(fdf->coo, fdf->nb_lines);
		if (fdf->val)
			free(fdf->val);
		free(fdf);
	}
	exit(0);
}

t_stock	*init_fdf(int x, int y)
{
	t_stock	*fdf;

	fdf = ft_calloc(sizeof(t_stock), 1);
	if (!fdf)
	{
		ft_printf("Allocation error for the fdf struct\n");
		clean_all(fdf);
	}
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->val = NULL;
	fdf->coo = NULL;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		ft_printf("MLX initialization error\n");
		clean_all(fdf);
	}
	fdf->window = mlx_new_window(fdf->mlx, x, y, "PowerRangers");
	if (!fdf->window)
	{
		ft_printf("Window error\n");
		clean_all(fdf);
	}
	return (fdf);
}

void	init_scale(t_stock *fdf)
{
	fdf->val->scale = 1;
	while ((fdf->val->scale + 1) * fdf->size_def < 1920 \
		&& (fdf->val->scale + 1) * fdf->nb_lines < 1080 / 2)
		fdf->val->scale++;
}

void	init_value(t_stock *fdf, int **coo, int nb_lines, int size_def)
{
	t_values	*val;

	val = ft_calloc(sizeof(t_values), 1);
	if (!val)
	{
		ft_printf("Allocation error for the values struct\n");
		clean_all(fdf);
	}
	fdf->val = val;
	fdf->size_def = size_def;
	fdf->nb_lines = nb_lines;
	init_scale(fdf);
	val->inc_x = (1920 - (((size_def * val->scale) - (nb_lines * val->scale)) \
				* 0.9397 - ((1 * 20) - (nb_lines * val->scale)) * 0.9397)) / 2;
	if (nb_lines > size_def)
		val->inc_y = (1080 - nb_lines * val->scale) / 3;
	else
		val->inc_y = (1080 - nb_lines * val->scale) / 2;
	fdf->coo = coo;
	val->scale_z = fdf->val->scale;
	val->angle_x = 26.57;
	val->angle_y = 26.57;
}
