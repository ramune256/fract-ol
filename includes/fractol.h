/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:38:43 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/13 18:01:34 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"

# define WIDTH 800
# define HEIGHT 600

// 複素数を表す構造体
typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

// 描画に必要な情報をまとめる構造体
typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	// ここに後々、描画範囲やフラクタルの種類などを追加していく
}			t_fractal;


t_complex	map_pixel_to_complex(int x, int y);

#endif
