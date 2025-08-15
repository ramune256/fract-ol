/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:42:56 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/15 21:11:12 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	map_pixel_to_complex(int x, int y, t_fractal *f)
{
	t_complex	c;

	c.real = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
	c.imag = f->max_i - (double)y * (f->max_i - f->min_i) / HEIGHT;
	return (c);
}
