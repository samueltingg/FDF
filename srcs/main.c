// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/01/22 12:00:19 by sting             #+#    #+#             */
// /*   Updated: 2024/01/23 15:11:28 by sting            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include ".././includes/fdf.h"



// works best if pixel_size equot to size of INT
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT) // * IMPORTANT!
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel /               8));
	*(unsigned int*)dst = color;
}



int close_window(int keycode, void *params)
{
	t_vars *vars = (t_vars *)params;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(vars->mlx_ptr, vars->img.img_ptr);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	return 0;
}

int	main(int argc, char **argv)
{
	t_vars vars;
	// t_cord **cord;
	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./fdf_linux <filename>\n", 2);
		exit (1);
	}
	(void)argv;
	// cord = parsing(argv[1]); // PARSING

	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		return (MLX_ERROR);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (vars.win_ptr == NULL)
	{
		mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
		return (MLX_ERROR);
	}
	vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_len,
								&vars.img.endian);

	mlx_loop_hook(vars.mlx_ptr, &render, &vars);

	mlx_key_hook(vars.win_ptr, &close_window, &vars);
	mlx_loop(vars.mlx_ptr);
	// mlx_destroy_image(vars.mlx_ptr, vars.img.img_ptr);
}
