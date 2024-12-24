/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:46:57 by amairia           #+#    #+#             */
/*   Updated: 2024/12/24 19:26:22 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	instructions(void)
{
	ft_printf("Use the arrow keys to move, + and - to zoom, the + and - keys");
	ft_printf(" on the numpad to change the relief, the 8, 2, 6, and 4");
	ft_printf(" keys on the numpad to rotate, / and * to change the view.\n");
}

static int	close_window(t_stock *fdf)
{
	ft_printf("window closing\n");
	clean_all(fdf);
	return (0);
}

static int	handle_key(int keycode, t_stock *fdf)
{
	if (keycode == 65307)
		close_window(fdf);
	else if (keycode == 65362 || keycode == 65364 \
			|| keycode == 65361 || keycode == 65363)
		translate_map(fdf, keycode);
	else if (keycode == 61 || keycode == 45)
		zoom_map(fdf, keycode);
	else if (keycode == 65451 || keycode == 65453)
		more_relief_map(fdf, keycode);
	else if (keycode == 65432 || keycode == 65433 \
			|| keycode == 65430 || keycode == 65431)
		rotate_map(fdf, keycode);
	else if (keycode == 65450 || keycode == 65455)
		change_view(fdf, keycode);
	return (0);
}

void	check(char *fic, int ac)
{
	if (ac != 2)
	{
		ft_printf("Argument error\n");
		exit(0);
	}
	ac = 0;
	while (fic[ac] && fic[ac] != '.')
		ac++;
	if (fic[ac] != '.' || fic[ac + 1] != 'f' || fic[ac + 2] != 'd'\
		|| fic[ac + 3] != 'f' || fic[ac + 4] != 0)
	{
		ft_printf("Format error\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_stock	*fdf;
	int		nb_lines;
	int		size_def;
	int		**coo;

	check(av[1], ac);
	fdf = init_fdf(1920, 1080);
	mlx_key_hook(fdf->window, handle_key, fdf);
	mlx_hook(fdf->window, 17, 0, close_window, fdf);
	coo = parsing(av[1], &nb_lines, &size_def);
	if (!coo)
	{
		ft_printf("Map error\n");
		clean_all(fdf);
	}
	init_value(fdf, coo, nb_lines, size_def);
	draw(fdf);
	instructions();
	mlx_loop(fdf->mlx);
	return (0);
}
