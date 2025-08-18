/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 23:03:13 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/18 16:26:38 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	f;

	if(!(parse_args(argc, argv, &f)))
		return (1);
	init_fractal(&f);
	render_fractal(&f);
	mlx_mouse_hook(f.win_ptr, mouse_hook, &f);
	mlx_key_hook(f.win_ptr, key_hook, &f);
	mlx_hook(f.win_ptr, 17, 0, success_exit, &f);
	mlx_loop(f.mlx_ptr);
	success_exit(&f);
	return (0);
}
