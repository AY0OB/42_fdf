/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:07:55 by amairia           #+#    #+#             */
/*   Updated: 2024/12/23 06:07:32 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_bis(t_stock *fdf, int x, int y, int z)
{
	if (x + 1 <= fdf->size_def)
	{
		z = fdf->coo[y - 1][x] * fdf->val->scale_z;
		fdf->x1 = ((x + 1) * fdf->val->scale - y * fdf->val->scale) \
			* fdf->val->angle_x + fdf->val->inc_x;
		fdf->y1 = ((x + 1) * fdf->val->scale + y * fdf->val->scale) \
			* fdf->val->angle_y - z + fdf->val->inc_y;
		trace_line(fdf);
	}
	if (y + 1 <= fdf->nb_lines)
	{
		z = fdf->coo[y][x - 1] * fdf->val->scale_z;
		fdf->x1 = (x * fdf->val->scale - (y + 1) * fdf->val->scale) \
			* fdf->val->angle_x + fdf->val->inc_x;
		fdf->y1 = (x * fdf->val->scale + (y + 1) * fdf->val->scale) \
			* fdf->val->angle_y - z + fdf->val->inc_y;
		trace_line(fdf);
	}
}

/* A MODIFIER */
void	draw(t_stock *fdf)
{
	int	x;
	int	y;
	int	z;

	y = 1;
	while (y <= fdf->nb_lines)
	{
		x = 1;
		while (x <= fdf->size_def)
		{
			z = fdf->coo[y - 1][x - 1] * fdf->val->scale_z;
			fdf->x0 = (x * fdf->val->scale - y * fdf->val->scale) \
				* fdf->val->angle_x + fdf->val->inc_x;
			fdf->y0 = (x * fdf->val->scale + y * fdf->val->scale) \
				* fdf->val->angle_y - z + fdf->val->inc_y;
			draw_bis(fdf, x, y, z);
			x++;
		}
		y++;
	}
}
