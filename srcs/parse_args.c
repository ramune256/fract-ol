/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:15:10 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/18 16:26:08 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_args(int argc, char **argv, t_fractal *f)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		f->type = MANDELBROT;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
		{
			ft_putendl_fd("Error: Julia parameters must be valid numbers.", 2);
			return (0);
		}
		f->type = JULIA;
		f->julia_r = ft_atof(argv[2]);
		f->julia_i = ft_atof(argv[3]);
	}
	else
	{
		ft_putendl_fd("Usage:	./fractol mandelbrot", 2);
		ft_putendl_fd("			./fractol julia <real_value> <imag_value>", 2);
		return (0);
	}
	return (1);
}
