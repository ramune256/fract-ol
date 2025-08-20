/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:39:37 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/20 16:14:51 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

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

void	init_x_y(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

void	prepare_formula(t_fractal *f, int x, int y, t_complex *c, t_complex *z)
{
	if (f->type == JULIA)
	{
		*z = map_pixel_to_complex(x, y, f);
		c->real = f->julia_r;
		c->imag = f->julia_i;
	}
	else
	{
		z->real = 0;
		z->imag = 0;
		*c = map_pixel_to_complex(x, y, f);
	}
}

int	iterate_point(t_complex z, t_complex c, int max_iterations)
{
	int		i;
	double	z_real_sq;
	double	z_imag_sq;

	i = 0;
	while (i < max_iterations)
	{
		z_real_sq = z.real * z.real;
		z_imag_sq = z.imag * z.imag;
		if (z_real_sq + z_imag_sq > 4.0)
			break;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = z_real_sq - z_imag_sq + c.real;
		i++;
	}
	return (i);
}

void	get_next_iter(t_fractal *f)
{
	if (f->current_iterations < MAX_ITERATIONS)
	{
		f->current_iterations += ITERATION_STEP;
		if (f->current_iterations > MAX_ITERATIONS)
			f->current_iterations = MAX_ITERATIONS;
	}
	else
		f->needs_redraw = 0;
}

void	render_fractal_optimized(t_fractal *f)
{
	static int	x = 0;
	static int	y = 0;
	t_complex	c;
	t_complex	z;
	int			i;

	f->pixels_drawn_this_frame = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			// if (f->pixels_drawn_this_frame >= PIXELS_PER_FRAME)
			// 	return;
			prepare_formula(f, x, y, &c, &z);
			i = iterate_point(z, c, f->current_iterations);
			my_pixel_put(&f->img, x, y, get_color_psychedelic(i));
			f->pixels_drawn_this_frame++;
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
	init_x_y(&x, &y);
	get_next_iter(f);
}
