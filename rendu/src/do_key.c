/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 05:30:19 by amairia           #+#    #+#             */
/*   Updated: 2024/12/23 06:18:56 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//arrow keys
void	translate_map(t_stock *fdf, int keycode)
{
	if (keycode == 65362)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->inc_y -= 20;
	}
	else if (keycode == 65364)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->inc_y += 20;
	}
	else if (keycode == 65361)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->inc_x -= 20;
	}
	else if (keycode == 65363)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->inc_x += 20;
	}
	draw(fdf);
}

//+ and -
void	zoom_map(t_stock *fdf, int keycode)
{
	if (keycode == 61)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->scale += 2;
	}
	else if (keycode == 45)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->scale -= 2;
	}
	draw(fdf);
}

// + and - numpad
void	more_relief_map(t_stock *fdf, int keycode)
{
	if (keycode == 65451)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->scale_z += 1;
	}
	else if (keycode == 65453)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->scale_z -= 1;
	}
	draw(fdf);
}

// 8, 2, 6 and 4 numpad
void	rotate_map(t_stock *fdf, int keycode)
{
	if (keycode == 65432)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->angle_x += 0.1;
	}
	else if (keycode == 65433)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->angle_y += 0.1;
		fdf->val->inc_y -= 50;
	}
	else if (keycode == 65430)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->angle_x -= 0.1;
	}
	else if (keycode == 65431)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->angle_y -= 0.1;
		fdf->val->inc_y += 50;
	}
	draw(fdf);
}
