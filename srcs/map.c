/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:42:56 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/15 20:29:22 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	map_pixel_to_complex(int x, int y, t_range *range)
{
	t_complex	c;

	// 上記の公式を適用
	c.real = range->min_r + (double)x / WIDTH * (range->max_r - range->min_r);
	// Y軸を反転させる (ウィンドウの上を虚数部の最大値にする)
	c.imag = range->max_i - (double)y / HEIGHT * (range->max_i - range->min_i);

	return (c);
}
