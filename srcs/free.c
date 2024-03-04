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

void	free_cord(t_vars *vars, t_cord ***cord) // ! NOT CHECKED
{
	int y = 0;
	while (y < vars->line_count)
	{
		free((*cord)[y]);
		y++;
	}
	free((*cord));
}

void free_all_cord(t_vars *vars)
{
	free_cord(vars, &vars->cord);
	free_cord(vars, &vars->cord_back);
	free_cord(vars, &vars->cord_left);
	free_cord(vars, &vars->cord_right);
}

void free_all_splitview_cord(t_vars *vars)
{
	free_cord(vars, &vars->cord_back);
	free_cord(vars, &vars->cord_left);
	free_cord(vars, &vars->cord_right);
}