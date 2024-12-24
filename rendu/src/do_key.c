/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 05:30:19 by amairia           #+#    #+#             */
/*   Updated: 2024/12/24 20:21:31 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//arrow keys
void	translate_map(t_stock *fdf, int keycode)
{
	if (keycode == 65362)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->inc_y -= 30;
	}
	else if (keycode == 65364)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->inc_y += 30;
	}
	else if (keycode == 65361)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->inc_x -= 30;
	}
	else if (keycode == 65363)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->inc_x += 30;
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
		fdf->val->scale_z += 0.05;
	}
	else if (keycode == 45)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		if (fdf->val->scale >= 5)
		{
			fdf->val->scale -= 2;
			if (fdf->val->scale_z >= 0.05)
				fdf->val->scale_z -= 0.05;
		}
	}
	draw(fdf);
}

// + and - numpad
void	more_relief_map(t_stock *fdf, int keycode)
{
	if (keycode == 65451)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		if (fdf->val->scale_z < -0.5 || fdf->val->scale_z > 0.5)
			fdf->val->scale_z += 0.5;
		else
			fdf->val->scale_z += 0.1;
	}
	else if (keycode == 65453)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		if (fdf->val->scale_z < -0.5 || fdf->val->scale_z > 0.5)
			fdf->val->scale_z -= 0.5;
		else
			fdf->val->scale_z -= 0.1;
	}
	draw(fdf);
}

// 6, 2, 4 and 8 numpad
void	rotate_map(t_stock *fdf, int keycode)
{
	mlx_clear_window(fdf->mlx, fdf->window);
	if (keycode == 65432 && fdf->val->angle_x < 180)
		fdf->val->angle_x += 5;
	else if (keycode == 65433)
	{
		if (fdf->val->angle_y > 0 && fdf->val->scale_z < 0)
			fdf->val->scale_z *= -1;
		if (fdf->val->angle_y < 90)
			fdf->val->angle_y += 5;
		if (fdf->val->angle_y < 70)
			fdf->val->inc_y -= 1 * fdf->val->scale;
	}
	else if (keycode == 65430 && fdf->val->angle_x > 0)
		fdf->val->angle_x -= 5;
	else if (keycode == 65431)
	{
		if (fdf->val->angle_y < 0 && fdf->val->scale_z > 0)
			fdf->val->scale_z *= -1;
		if (fdf->val->angle_y > -90)
			fdf->val->angle_y -= 5;
		if (fdf->val->angle_y > -70)
			fdf->val->inc_y += 1 * fdf->val->scale;
	}
	rotate_map_bis(fdf, keycode);
}

// * and /
void	change_view(t_stock *fdf, int keycode)
{
	if (keycode == 65450)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->angle_x = 0;
		fdf->val->angle_y = 0;
		fdf->val->inc_x = (1920 - (((fdf->size_def * fdf->val->scale) \
					- (fdf->nb_lines * fdf->val->scale)) * 0.9397 - ((1 * 20) \
					- (fdf->nb_lines * fdf->val->scale)) * 0.9397)) / 2;
		fdf->val->inc_y = 500;
	}
	else if (keycode == 65455)
	{
		mlx_clear_window(fdf->mlx, fdf->window);
		fdf->val->angle_x = 26.57;
		fdf->val->angle_y = 26.57;
		fdf->val->inc_x = (1920 - (((fdf->size_def * fdf->val->scale) \
					- (fdf->nb_lines * fdf->val->scale)) * 0.9397 - ((1 * 20) \
					- (fdf->nb_lines * fdf->val->scale)) * 0.9397)) / 2;
		fdf->val->inc_y = (1080 - fdf->nb_lines * fdf->val->scale) / 3;
		fdf->val->scale_z = scale_z_base(fdf);
	}
	draw(fdf);
}
