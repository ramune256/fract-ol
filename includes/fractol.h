/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:38:43 by shunwata          #+#    #+#             */
/*   Updated: 2025/08/16 22:06:06 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

# define MAX_ITERATIONS 100

#define ZOOM_FACTOR 0.9

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	t_fractal_type	type;
	double		julia_r;
	double		julia_i;
}			t_fractal;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}	t_fractal_type;

int			mouse_hook(int button, int x, int y, t_fractal *f);
double		ft_atof(const char *str);
t_complex	map_pixel_to_complex(int x, int y, t_fractal *f);
void		render_mandelbrot(t_fractal *f);

#endif
