/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:07:55 by amairia           #+#    #+#             */
/*   Updated: 2024/12/25 16:16:19 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//Dark red, red, orange, light yellow, yellow-green, green, dark green.
static void	choice_color(t_stock *fdf, int z)
{
	if (z <= -25)
		fdf->color = 9109504;
	if (z > -25 && z <= -15)
		fdf->color = 16711680;
	if (z > -15 && z <= -5)
		fdf->color = 16744448;
	if (z > -5 && z < 5)
		fdf->color = 16777184;
	if (z >= 5 && z < 15)
		fdf->color = 11403055;
	if (z >= 15 && z < 25)
		fdf->color = 65280;
	if (z >= 25)
		fdf->color = 25600;
}

static void	draw_bis(t_stock *fdf, int x, int y, int z)
{
	float	pi;

	pi = 3.14159;
	if (x + 1 <= fdf->size_def)
	{
		z = fdf->coo[y - 1][x] * fdf->val->scale_z;
		fdf->x1 = ((x + 1) * fdf->val->scale - y * fdf->val->scale) \
			* cos(pi * fdf->val->angle_x / 180) + fdf->val->inc_x;
		fdf->y1 = ((x + 1) * fdf->val->scale + y * fdf->val->scale) \
			* sin(pi * fdf->val->angle_y / 180) - z + fdf->val->inc_y;
		trace_line(fdf);
	}
	if (y + 1 <= fdf->nb_lines)
	{
		z = fdf->coo[y][x - 1] * fdf->val->scale_z;
		fdf->x1 = (x * fdf->val->scale - (y + 1) * fdf->val->scale) \
			* cos(pi * fdf->val->angle_x / 180) + fdf->val->inc_x;
		fdf->y1 = (x * fdf->val->scale + (y + 1) * fdf->val->scale) \
			* sin(pi * fdf->val->angle_y / 180) - z + fdf->val->inc_y;
		trace_line(fdf);
	}
}

void	draw(t_stock *fdf)
{
	int		x;
	int		y;
	int		z;
	float	pi;

	pi = 3.14159;
	y = 1;
	while (y <= fdf->nb_lines)
	{
		x = 1;
		while (x <= fdf->size_def)
		{
			choice_color(fdf, fdf->coo[y - 1][x - 1]);
			z = fdf->coo[y - 1][x - 1] * fdf->val->scale_z;
			fdf->x0 = (x * fdf->val->scale - y * fdf->val->scale) \
				* cos(pi * fdf->val->angle_x / 180) + fdf->val->inc_x;
			fdf->y0 = (x * fdf->val->scale + y * fdf->val->scale) \
				* sin(pi * fdf->val->angle_y / 180) - z + fdf->val->inc_y;
			draw_bis(fdf, x, y, z);
			x++;
		}
		y++;
	}
}
