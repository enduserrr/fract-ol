/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:20:41 by asalo             #+#    #+#             */
/*   Updated: 2024/03/16 16:22:32 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../mlx/mlx.h"
# include "../../libft/incs/libft.h"
/* # include <math.h> */

# define WIDTH 800
# define HIGHT 800
# define RANDOM_MAX 32767

/* KEYCODES */
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define P 35
# define M 46
# define ESC 53

/* MOUSECODES */
# define SCROLL_UP 5
# define SCROLL_DOWN 4

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

double		ft_atod(char *s);
int			clean_exit(t_fractal *fractal);
void		error_exit(int type);
void		instructions(char *help);
void		change_iterations(t_fractal *fractal, int key_code);
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);
void		calculate_mandelbrot(t_fractal *fractal);
void		calculate_julia(t_fractal *fractal);
int			draw_fractal(t_fractal *fractal, char *option);
void		color_pixel(t_fractal *fractal, int x, int y, int colour);
void		*draw_mandelbrot(void *fractal_void);
void		draw_julia(t_fractal *fractal);
int			key_hook(int key_code, t_fractal *fractal);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
void		*draw_mandelbrot(void *fractal_void);
void		draw_julia(t_fractal *fractal);

#endif