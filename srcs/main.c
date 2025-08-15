/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:03:13 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/13 18:43:42 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractal	f;

	f.mlx_ptr = mlx_init();
	// ... エラーチェック ...
	f.win_ptr = mlx_new_window(f.mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
	// ... エラーチェック ...

	// イメージの作成
	f.img.img_ptr = mlx_new_image(f.mlx_ptr, WIDTH, HEIGHT);
	f.img.addr = mlx_get_data_addr(f.img.img_ptr, &f.img.bpp, &f.img.line_len, &f.img.endian);

	// 描画関数の呼び出し
	render_mandelbrot(&f);

	mlx_loop(f.mlx_ptr);
	return (0);
}
