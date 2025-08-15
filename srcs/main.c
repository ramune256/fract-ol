/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:03:13 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/15 20:46:52 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_range(t_range *range)
{
	range->min_r = -2.0;
	range->max_r = 2.0;
	range->min_i = -2.0;
	range->max_i = 2.0;
}

int	main(void)
{
	t_fractal	f;
	t_range		range;

	f.mlx_ptr = mlx_init();
	// ... エラーチェック ...
	f.win_ptr = mlx_new_window(f.mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");
	// ... エラーチェック ...

	init_range(&range);

	// イメージの作成
	f.img.img_ptr = mlx_new_image(f.mlx_ptr, WIDTH, HEIGHT);
	f.img.addr = mlx_get_data_addr(f.img.img_ptr, &f.img.bpp, &f.img.line_len, &f.img.endian);

	// 描画関数の呼び出し
	render_mandelbrot(&f, &range);

	mlx_mouse_hook(f.win_ptr, mouse_hook, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
