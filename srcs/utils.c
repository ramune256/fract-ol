/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:46:20 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/19 14:16:37 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_double(char *str)
{
	int		dot_count;
	int		has_digit;

	dot_count = 0;
	has_digit = 0;
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			has_digit = 1;
		else if (*str == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else
			return (0);
		str++;
	}
	return (has_digit);
}

int	error_exit(char *message, t_fractal *f)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
	cleanup(f);
	exit(EXIT_FAILURE);
	return (0);
}

int	success_exit(t_fractal *f)
{
	cleanup(f);
	exit(EXIT_SUCCESS);
	return (1);
}

void	cleanup(t_fractal *f)
{
	if (f)
	{
		if (f->img.img_ptr)
			mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
		if (f->win_ptr)
			mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		if (f->mlx_ptr)
		{
			mlx_destroy_display(f->mlx_ptr);
			free(f->mlx_ptr);
		}
	}
}

void	init_fractal(t_fractal *f)
{
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = 2.0;
	f->current_iterations = INITIAL_ITERATIONS;
	f->needs_redraw = 1;
	f->pixels_drawn_this_frame = 0;
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		error_exit("mlx_init() failed.", f);
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (!f->win_ptr)
		error_exit("mlx_new_window() failed.", f);
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
		error_exit("mlx_new_image() failed.", f);
	f->img.addr = mlx_get_data_addr(\
		f->img.img_ptr, &f->img.bpp, &f->img.line_len, &f->img.endian);
	if (!f->img.addr)
		error_exit("mlx_get_data_addr() failed.", f);
}
