/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:39:37 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/20 19:24:27 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color_psychedelic(int i)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	if (i == MAX_ITERATIONS)
		return (0x00000000);
	t = (double)i / MAX_ITERATIONS;
	red = (int)(sin(t * 10.0 + 0) * 127 + 128);
	green = (int)(sin(t * 10.0 + 2) * 127 + 128);
	blue = (int)(sin(t * 10.0 + 4) * 127 + 128);
	return ((red << 16) | (green << 8) | blue);
}

void	prepare_formula(t_fractal *f, t_pixel *pixel, t_complex *c, t_complex *z)
{
	if (f->type == JULIA)
	{
		*z = map_pixel_to_complex(pixel->x, pixel->y, f);
		c->real = f->julia_r;
		c->imag = f->julia_i;
	}
	else
	{
		z->real = 0;
		z->imag = 0;
		*c = map_pixel_to_complex(pixel->x, pixel->y, f);
	}
}

int	iterate_point(t_complex z, t_complex c, int iter)
{
	int		i;
	double	z_real_sq;
	double	z_imag_sq;

	i = 0;
	while (i < iter)
	{
		z_real_sq = z.real * z.real;
		z_imag_sq = z.imag * z.imag;
		if (z_real_sq + z_imag_sq > 4.0)
			break ;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = z_real_sq - z_imag_sq + c.real;
		i++;
	}
	return (i);
}

void	get_next_iter(t_fractal *f)
{
	if (f->current_iterations + ITERATION_STEP > MAX_ITERATIONS)
		f->current_iterations = MAX_ITERATIONS;
	else
		f->current_iterations += ITERATION_STEP;
}

void	render_fractal_optimized(t_fractal *f)
{
	t_pixel		pixel;
	t_complex	c;
	t_complex	z;

	pixel.x = 0;
	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		while (pixel.x < WIDTH)
		{
			prepare_formula(f, &pixel, &c, &z);
			my_pixel_put(&f->img, pixel.x, pixel.y, get_color_psychedelic(\
				iterate_point(z, c, f->current_iterations)));
			pixel.x++;
		}
		pixel.x = 0;
		pixel.y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
	if (f->current_iterations < MAX_ITERATIONS)
		get_next_iter(f);
	else
		f->needs_redraw = 0;
}
