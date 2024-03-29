/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:32 by sting             #+#    #+#             */
/*   Updated: 2024/03/07 14:35:51 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cord
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_cord;

/**
 * @param line_len amount of bytes taken by one row of our image
 * @param img_ptr pointer to the image structure created by mlx_new_image
 * @param addr pointer to the raw pixel data of the image
 */
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_flag
{
	int		iso;
	int		done_once;
	int		default_colors;
	int		split_4_view;
	int		rotate_x;
	int		rotate_y;
	int		rotate_z;
}			t_flag;

/*
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	// PARSING
	t_cord **cord;
		// coordinates here will be updated for each transformation
	t_cord **cord_ori;
		// original copy of coordinates |
		// grid center translated to frame origin(0,0)

	int		line_count;
	int		wc;
	double	gap;
	double	z_factor;
	int		offset_x;
	int		offset_y;

	// to keep track of rotated angle about each axis
	double	angle_x_axis;
	double	angle_y_axis;
	double	angle_z_axis;
	t_flag	flags;

	// split 4 view
	t_cord	**cord_bottom;
	t_cord	**cord_left;
	t_cord	**cord_right
*/
typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_cord	**cord;
	t_cord	**cord_ori;

	int		line_count;
	int		wc;
	double	gap;
	double	z_factor;
	int		offset_x;
	int		offset_y;

	double	angle_x_axis;
	double	angle_y_axis;
	double	angle_z_axis;
	t_flag	flags;

	t_cord	**cord_bottom;
	t_cord	**cord_left;
	t_cord	**cord_right;
}			t_vars;

/*
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		color;
*/
typedef struct s_line_cord
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		color1;
	int		color2;
}			t_line_cord;

typedef struct s_line_var
{
	int		dx;
	int		dy;
	int		d;
	int		x;
	int		y;
	int		xi;
	int		yi;
}			t_line_var;

typedef struct s_angle
{
	double	x;
	double	y;
	double	z;
}			t_angle;

/*
	int a;
	int b;
	int c;
*/
// typedef struct s_matrix // * not needed anymore
// {
// 	double	a;
// 	double	b;
// 	double	c;
// }			t_matrix;

#endif
