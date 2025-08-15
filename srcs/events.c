/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 20:33:50 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/15 20:47:24 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *f, t_range *range)
{
	t_complex	mouse_pos;
	double		new_range_r;
	double		new_range_i;
	double		zoom;

	if (button == 4 || button == 5)
	{
		mouse_pos = map_pixel_to_complex(x, y, range);
		if (button == 4)
			zoom = ZOOM_FACTOR;
		else
			zoom = 1.0 / ZOOM_FACTOR;
		new_range_r = (range->max_r - range->min_r) * zoom;
		new_range_i = (range->max_i - range->min_i) * zoom;
		range->min_r = mouse_pos.real - \
			((double)x / WIDTH) * new_range_r;
		range->max_r = range->min_r + new_range_r;
		range->min_i = mouse_pos.imag - \
			((double)(HEIGHT - y) / HEIGHT) * new_range_i;
		range->max_i = range->min_i + new_range_i;
		render_mandelbrot(f, range);
	}
	return (0);
}
