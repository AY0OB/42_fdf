/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:54:53 by amairia           #+#    #+#             */
/*   Updated: 2024/12/24 18:38:33 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	abs_sgn(int x, int choice)
{
	if (choice == 1)
	{
		if (x < 0)
			return (-x);
		return (x);
	}
	else
	{
		if (x < 0)
			return (-1);
		else if (x > 0)
			return (1);
		return (0);
	}
}

static void	line_more_horizontal(t_stock *fdf)
{
	int	slope;
	int	error;
	int	x;
	int	y;

	slope = 2 * fdf->dy;
	error = -(fdf->dx);
	y = fdf->y0;
	x = fdf->x0;
	while (x != fdf->x1 + fdf->inc_x)
	{
		mlx_pixel_put(fdf->mlx, fdf->window, x, y, 0xFFFFFF);//fdf->color);
		error += slope;
		if (error >= 0)
		{
			y += fdf->inc_y;
			error += -2 * fdf->dx;
		}
		x += fdf->inc_x;
	}
}

static void	line_more_vertical(t_stock *fdf)
{
	int	slope;
	int	error;
	int	x;
	int	y;

	slope = 2 * fdf->dx;
	error = -(fdf->dy);
	x = fdf->x0;
	y = fdf->y0;
	while (y != fdf->y1 + fdf->inc_y)
	{
		mlx_pixel_put(fdf->mlx, fdf->window, x, y, 0xFFFFFF);//fdf->color);
		error += slope;
		if (error >= 0)
		{
			x += fdf->inc_x;
			error += -2 * fdf->dy;
		}
		y += fdf->inc_y;
	}
}

void	trace_line(t_stock *fdf)
{
	fdf->inc_x = abs_sgn(fdf->x1 - fdf->x0, 0);
	fdf->inc_y = abs_sgn(fdf->y1 - fdf->y0, 0);
	fdf->dx = abs_sgn(fdf->x1 - fdf->x0, 1);
	fdf->dy = abs_sgn(fdf->y1 - fdf->y0, 1);
	if (fdf->dy == 0)
	{
		while (fdf->x0 != fdf->x1 + fdf->inc_x)
		{
			mlx_pixel_put(fdf->mlx, fdf->window, fdf->x0, fdf->y0, 0xFFFFFF);//fdf->color);
			fdf->x0 += fdf->inc_x;
		}
	}
	else if (fdf->dx == 0)
	{
		while (fdf->y0 != fdf->y1 + fdf->inc_y)
		{
			mlx_pixel_put(fdf->mlx, fdf->window, fdf->x0, fdf->y0, 0xFFFFFF);//fdf->color);
			fdf->y0 += fdf->inc_y;
		}
	}
	else if (fdf->dx >= fdf->dy)
		line_more_horizontal(fdf);
	else
		line_more_vertical(fdf);
}
