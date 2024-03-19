/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:14:56 by asalo             #+#    #+#             */
/*   Updated: 2024/03/19 09:20:11 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

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

static void	increment_julia(double *cx, double *cy, int opt)
{
	if (opt == 0)
	{
		*cx = *cx * 1.03;
		*cy = *cy * 1.03;
	}
	if (opt == 1)
	{
		*cx = *cx * 0.97;
		*cy = *cy * 0.97;
	}
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		clean_exit(fractal);
	else if (key_code == LEFT || key_code == A)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT || key_code == D)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP || key_code == W)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN || key_code == S)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == R)
		init_fractal(fractal);
	else if (key_code == LEFT_SHIFT)
		increment_julia(&fractal->cx, &fractal->cx, 0);
	else if (key_code == LEFT_CTRL)
		increment_julia(&fractal->cx, &fractal->cx, 1);
	else if (key_code == C)
		fractal->color += (90 * 90 * 90) / 100;
	else if (key_code == M || key_code == P)
		change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}
