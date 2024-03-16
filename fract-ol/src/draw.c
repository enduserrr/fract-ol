/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 09:29:17 by asalo             #+#    #+#             */
/*   Updated: 2024/03/16 16:38:39 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}

int	draw_fractal(t_fractal *fractal, char *option)
{
	if (ft_strcmp(option, "mandel") == 0)
		draw_mandelbrot(fractal);
	else if (ft_strcmp(option, "julia") == 0)
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.745429;
			fractal->cy = 0.05;
		}
		draw_julia(fractal);
	}
	else
	{
		ft_printf("available fractals: mandel, julia\n");
		clean_exit(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}