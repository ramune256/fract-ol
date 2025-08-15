/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:39:37 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/15 21:11:40 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// イメージバッファの指定したピクセルに色を書き込むヘルパー関数
void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

// マンデルブロ集合の計算と描画を行うメイン関数
void	render_mandelbrot(t_fractal *f)
{
	int			x;
	int			y;
	t_complex	c;
	t_complex	z;
	int			i;
	double		z_real_sq;
	double		z_imag_sq;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = map_pixel_to_complex(x, y, f); // Day 2の関数
			z.real = 0;
			z.imag = 0;
			i = 0;
			while (i < MAX_ITERATIONS)
			{
				z_real_sq = z.real * z.real;
				z_imag_sq = z.imag * z.imag;
				// |Z|^2 > 4 かチェック
				if (z_real_sq + z_imag_sq > 4.0)
					break;
				// Z = Z^2 + C
				z.imag = 2 * z.real * z.imag + c.imag;
				z.real = z_real_sq - z_imag_sq + c.real;
				i++;
			}
			if (i == MAX_ITERATIONS)
				my_pixel_put(&f->img, x, y, 0x00000000); // 集合内部は黒
			else
				my_pixel_put(&f->img, x, y, 0x00FFFFFF * (i / (double)MAX_ITERATIONS)); // 外部は白系のグラデーション
			x++;
		}
		y++;
	}
	// イメージをウィンドウに表示
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
}
