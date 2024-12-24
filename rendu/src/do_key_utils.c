/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_key_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:08:50 by amairia           #+#    #+#             */
/*   Updated: 2024/12/24 20:22:13 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_map_bis(t_stock *fdf, int keycode)
{
	if (keycode == 65430 && fdf->val->angle_x < 90 \
			&& fdf->val->scale_z < 0)
		fdf->val->scale_z *= -1;
	else if (keycode == 65432 && fdf->val->angle_x > 90 \
			&& fdf->val->scale_z > 0)
		fdf->val->scale_z *= -1;
	draw(fdf);
}
