/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:25:04 by sting             #+#    #+#             */
/*   Updated: 2024/03/19 09:42:29 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include ".././libft/libft.h"
# include "macros.h"
# include "mlx.h"
# include "structs.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// ^can also use <mlx.h>, but only in 42 macs

// * print_grid
void	print_grid(t_vars *vars, t_cord **cord);

// * PARSING
int		ft_atoi_base_fdf(char *str, char *base);
int		get_line_count(char *input);
void	parsing(char *input, t_vars *vars);

void	img_pix_put(t_img *img, int x, int y, int color);
// void		img_pix_put(t_img *img, double x_double, double y_double,
// int color);

// * MLX
int		close_window(void *params);
int		handle_key_event(int keycode, void *param);

// * RENDERING
// covers previous frame with black (reset)
void	render_background(t_img *img, int color);
int		render(void *param);
void	render_grid(t_vars *vars, t_cord ***grid);

// BRESENHAM'S LINE ALGO
void	render_line_bresenham(t_img *img, t_line_cord cord);
void	render_line_low(t_img *img, t_line_cord line);
/*
- For steep slope
- gradient > 1 OR gradient < -1
*/
void	render_line_high(t_img *img, t_line_cord line);

void	reset_grid(t_vars *vars);

// * MATRIX MULTIPLICATION
// void multiply_matrix_to_grid(t_vars *vars, t_matrix row1, t_matrix row2,
// t_matrix row3);
void	multiply_matrix_to_grid(t_vars *vars, t_cord ***cord,
			double matrix[3][3]);

// * TRANSFORMATION
// void translate_2d(t_vars *vars, double tx, double ty);
void	translate_2d(t_vars *vars, t_cord ***cord, double tx, double ty);
// void resize(t_vars *vars, int increase_amt);
void	resize(t_vars *vars); // ? meng's idea

void	rotate_about_z_axis_2d(t_vars *vars, t_cord ***cord, double angle);
void	rotate_about_x_axis(t_vars *vars, t_cord ***cord, double angle);
void	rotate_about_y_axis(t_vars *vars, t_cord ***cord, double angle);

void	rotate_about_all_axis(t_vars *vars, t_cord ***cord, t_angle angle);

// TRANSFORMATION UTILS
void	bring_center_of_grid_from_topcorner_to_origin(t_vars *vars);
void	init_vars(t_vars *vars);
void	reset_grid(t_vars *vars);
void	create_original_cord_copy(t_vars *vars);
t_cord	**duplicate_coordinates(t_vars *vars, t_cord **cord);

// * COLOR
int		gradient(int startcolor, int endcolor, int len, int pix);
void	init_default_colors(t_vars *vars);

// * SPLIT 4 VIEW
void	init_other_grids(t_vars *vars);
void	transform_4_grids(t_vars *vars);
void	render_splitview_grids(t_vars *vars);

// * FREE
void	free_cord(t_vars *vars, t_cord ***cord);
void	free_all_cord(t_vars *vars);
void	free_all_splitview_cord(t_vars *vars);
void	free_str_arr(char **str_arr);

// * RENDER SIDEBAR
void	render_sidebar(t_img *img, int color);
void	render_text(void *mlx_ptr, void *win_ptr);

#endif
