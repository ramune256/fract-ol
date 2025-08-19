/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:06:16 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/19 14:18:13 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *f)
{
	t_complex	mouse_pos;
	double		range_r;
	double		range_i;
	double		zoom;

	if (button == 4 || button == 5)
	{
		mouse_pos = map_pixel_to_complex(x, y, f);
		if (button == 4)
			zoom = ZOOM_FACTOR;
		else
			zoom = 1.0 / ZOOM_FACTOR;
		range_r = (f->max_r - f->min_r) * zoom;
		range_i = (f->max_i - f->min_i) * zoom;
		f->min_r = mouse_pos.real - ((double)x / WIDTH) * range_r;
		f->max_r = f->min_r + range_r;
		f->min_i = mouse_pos.imag - \
			((double)(HEIGHT - y) / HEIGHT) * range_i;
		f->max_i = f->min_i + range_i;
		f->needs_redraw = 1;
		f->current_iterations = INITIAL_ITERATIONS;
	}
	return (0);
}

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == KEY_ESC)
		success_exit(f);
	// else if (keycode == KEY_SPACE)
	// {
	// 	f->needs_redraw = 1;
	// 	f->current_iterations = INITIAL_ITERATIONS;
	// }
	else if (keycode == KEY_R)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
		f->needs_redraw = 1;
		f->current_iterations = INITIAL_ITERATIONS;
	}
	return (0);
}

int	loop_hook(t_fractal *f)
{
	if (f->needs_redraw)
		render_fractal_optimized(f);
	return (0);
}
