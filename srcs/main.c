/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:03:13 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/15 21:09:53 by shunwata         ###   ########.fr       */
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
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp, &f->img.line_len, &f->img.endian);
}

int	main(void)
{
	t_fractal	f;

	init_fractal(&f);
	render_mandelbrot(&f);
	mlx_mouse_hook(f.win_ptr, mouse_hook, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
