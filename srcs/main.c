/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:03:13 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/16 22:36:17 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *f)
{
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = 2.0;

	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp, &f->img.line_len, &f->img.endian);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		f.type = MANDELBROT;
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		f.type = JULIA;
		f.julia_r = ft_atof(argv[2]);
		f.julia_i = ft_atof(argv[3]);
	}
	else
		return (write(2, "Usage: ./fractol [mandelbrot | julia]\n", 38), 1);
	init_fractal(&f);
	render_mandelbrot(&f);
	mlx_mouse_hook(f.win_ptr, mouse_hook, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
