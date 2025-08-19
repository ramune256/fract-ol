/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:39:37 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/19 14:27:46 by shunwata         ###   ########.fr       */
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

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	render_fractal_optimized(t_fractal *f)
{
	static int	x = 0;
	static int	y = 0;
	t_complex	c;
	t_complex	z;
	int			i;
	double		z_real_sq;
	double		z_imag_sq;

	if (x == 0 && y == 0)
		f->pixels_drawn_this_frame = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			if (f->pixels_drawn_this_frame >= PIXELS_PER_FRAME)
				return;
			if (f->type == JULIA)
			{
				z = map_pixel_to_complex(x, y, f);
				c.real = f->julia_r;
				c.imag = f->julia_i;
			}
			else
			{
				z.real = 0;
				z.imag = 0;
				c = map_pixel_to_complex(x, y, f);
			}
			i = 0;
			while (i < f->current_iterations)
			{
				z_real_sq = z.real * z.real;
				z_imag_sq = z.imag * z.imag;
				if (z_real_sq + z_imag_sq > 4.0)
					break;
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = z_real_sq - z_imag_sq + c.real;
				i++;
			}
			my_pixel_put(&f->img, x, y, get_color_psychedelic(i));
			x++;
		}
		x = 0;
		y++;
	}
	if (y >= HEIGHT)
	{
		mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
		y = 0;
		x = 0;
		if (f->current_iterations < MAX_ITERATIONS)
		{
			f->current_iterations += ITERATION_STEP;
			if (f->current_iterations > MAX_ITERATIONS)
				f->current_iterations = MAX_ITERATIONS;
		}
		else
			f->needs_redraw = 0;
	}
}
