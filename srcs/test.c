/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:03:13 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/13 15:32:26 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

int	main(void)
{
	t_data	data;
	int		x;

	// 1. MiniLibXの初期化
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);

	// 2. ウィンドウの作成
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (data.win_ptr == NULL)
		return (1); // エラー処理は実際にはメモリ解放などが必要です

	// 3. ピクセルの描画 (対角線)
	x = 0;
	while (x < HEIGHT && x < WIDTH)
	{
		// mlx_pixel_put(mlx_ptr, win_ptr, x, y, color)
		mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, x, 0x00FF0000); // 赤色
		x++;
	}

	// 4. イベントループの開始
	mlx_loop(data.mlx_ptr);
	return (0);
}

// #include "mlx.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1280, 720, "Hello world!");
// 	(void)mlx_win;
// 	mlx_loop(mlx);
// }
