/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:03:13 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/13 18:05:58 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_complex	c1 = map_pixel_to_complex(0, 0); // 左上
	t_complex	c2 = map_pixel_to_complex(WIDTH / 2, HEIGHT / 2); // 中央
	t_complex	c3 = map_pixel_to_complex(WIDTH - 1, HEIGHT - 1); // 右下

	ft_printf("Top-left (0,0) maps to: (%.2f, %.2fi)\n", c1.real, c1.imag);
	ft_printf("Center (%d,%d) maps to: (%.2f, %.2fi)\n", WIDTH / 2, HEIGHT / 2, c2.real, c2.imag);
	ft_printf("Bottom-right (%d,%d) maps to: (%.2f, %.2fi)\n", WIDTH - 1, HEIGHT - 1, c3.real, c3.imag);

	return (0);
}
