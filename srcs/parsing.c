/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sting <sting@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 09:55:04 by sting             #+#    #+#             */
/*   Updated: 2024/02/05 14:52:27 by sting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/fdf.h"

void free_str_arr(char **str_arr)
{
	int i;
	
	i = 0;
	while (str_arr[i] != NULL)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

int	count_words(char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (*str != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (*str == c)
		{
			flag = 1;
		}
		str++;
	}
	return (count);
}

/**
 * returns line_count of an open file.
 * - run gnl until it return NULL, to get number of lines in file
 */
int	get_line_count(char *input)
{
	int		line_count;
	int fd;

    fd = open(input, O_RDONLY);
    if (fd == -1) 
	{
        perror("Unable to open the file");
        return 1;
	}
	line_count = 0;
	while (1)
	{
		input = get_next_line(fd);
		if (input == NULL)
			break ;
		line_count++;
	}
	close(fd);
	return (line_count);
}

t_cord	**parsing(char *input)
{
	t_cord	**cord;
	int		y;
	int		x;
	char	*line;
	int		line_count;
	char	**str_arr;
	int		wc;
	int		i;
	int fd;

	line_count = get_line_count(input);
    fd = open(input, O_RDONLY);
    if (fd == -1) 
	{
        perror("Unable to open the file");
        exit (1);
	}
	cord = malloc(line_count * sizeof(t_cord *));
	y = 0;
	while (y < line_count)
	{
		line = get_next_line(fd);
		str_arr = ft_split(line, ' ');
		wc = count_words(line, ' ');
		cord[y] = malloc(wc * sizeof(t_cord));
		x = 0;
		while (str_arr[x])
		{
			cord[y][x].z = ft_atoi(str_arr[x]);
			if (ft_strchr((const char *)str_arr[x], ',') != NULL)
			{
				i = 0;
				while (str_arr[x][i] != 'x')
					i++;
				cord[y][x].color = ft_atoi_base((&str_arr[x][++i]), "0123456789ABCDEF");
			}
			else
				cord[y][x].color = 0; // Set a default color if none is provided
			x++;
		}
		free_str_arr(str_arr);
		y++;
	}
	
    // Print the contents of the 2D array
    y = 0; 
	for (y = 0; y < line_count; y++)
    {
        for (x = 0; x < wc; x++)
        {
            printf("%d,%d  ", cord[y][x].z, cord[y][x].color);
            // printf("%3d ", cord[y][x].z);
        }
        printf("\n");
    }
	return (cord);
}
