/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:42:56 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/13 19:28:27 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	map_pixel_to_complex(int x, int y)
{
	t_complex	c;
	// 初期表示範囲 (マンデルブロ集合全体が収まる一般的な範囲)
	double		min_r = -2.0;
	double		max_r = 2.0;
	double		min_i = -2.0;
	double		max_i = 2.0;

	// 上記の公式を適用
	c.real = min_r + (double)x / WIDTH * (max_r - min_r);
	// Y軸を反転させる (ウィンドウの上を虚数部の最大値にする)
	c.imag = max_i - (double)y / HEIGHT * (max_i - min_i);

	return (c);
}
