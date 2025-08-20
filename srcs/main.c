/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:03:13 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/20 19:07:47 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	f;

	ft_bzero(&f, sizeof(t_fractal));
	if (!(parse_args(argc, argv, &f)))
		return (1);
	init_fractal(&f);
	mlx_mouse_hook(f.win_ptr, mouse_hook, &f);
	mlx_key_hook(f.win_ptr, key_hook, &f);
	mlx_hook(f.win_ptr, 17, 0, success_exit, &f);
	mlx_loop_hook(f.mlx_ptr, loop_hook, &f);
	mlx_loop(f.mlx_ptr);
	return (0);
}
