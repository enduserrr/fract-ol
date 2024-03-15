/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:14:56 by asalo             #+#    #+#             */
/*   Updated: 2024/03/15 19:55:56 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

// static int	random_nb(void)
// {
// 	static unsigned long	next;

// 	next = 1;
// 	next = next * 1103515245 + 12345;
// 	return ((unsigned int)(next / 65536) % (RANDOM_MAX + 1));
// }

// static double	generate_random_c(void)
// {
// 	return (((double)random_nb() / RANDOM_MAX) * 3.0 - 1.5);
// }

// static void	set_random_julia(double *cx, double *cy)
// {
// 	*cx = generate_random_c();
// 	*cy = generate_random_c();
// }

void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = 1.42;
	if (zoom == 1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == -1)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		clean_exit(fractal);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		init_fractal(fractal);
	else if (key_code == C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}
/*	else if (key_code == J)
	set_random_julia(&fractal->cx, &fractal->cx); */

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}
