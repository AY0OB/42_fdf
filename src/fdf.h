/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:10:01 by amairia           #+#    #+#             */
/*   Updated: 2024/12/25 14:52:00 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft_with_gnl_printf/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct t_values
{
	int		inc_x;
	int		inc_y;
	int		scale;
	float	scale_z;
	float	angle_x;
	float	angle_y;
}	t_values;

typedef struct t_stock
{
	void		*mlx;
	void		*window;
	int			**coo;
	int			size_def;
	int			nb_lines;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			inc_x;
	int			inc_y;
	int			color;
	t_values	*val;
}	t_stock;

int		**parsing(char *fic, int *nb_lines, int *size_def);
int		**coo_creator(char ***lines, int *nb_lines, int *size_def);
void	feed_coo(int ***coo, char ***lines, int nb_lines, int size_def);
char	**free_lines(char **lines, int nb_lines);
int		**free_coo(int **coo, int nb_lines_coo);

t_stock	*init_fdf(int x, int y);
void	init_value(t_stock *fdf, int **coo, int nb_lines, int size_def);
void	clean_all(t_stock *fdf);

void	trace_line(t_stock *fdf);
void	draw(t_stock *fdf);

void	translate_map(t_stock *fdf, int keycode);
void	zoom_map(t_stock *fdf, int keycode);
void	more_relief_map(t_stock *fdf, int keycode);
void	rotate_map(t_stock *fdf, int keycode);
void	change_view(t_stock *fdf, int keycode);

#endif
