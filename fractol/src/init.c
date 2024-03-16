/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:10:50 by asalo             #+#    #+#             */
/*   Updated: 2024/03/16 11:20:42 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	julia_options(t_fractal	*fractal, char *name)
{
	if (ft_strcmp(name, "0") == 0)
	{
		fractal->cx = -0.8 ;
		fractal->cy = 0.156;
	}
	else if (ft_strcmp(name, "1") == 0)
	{
		fractal->cx = 0.285;
		fractal->cy = 0.01;
	}
	else if (ft_strcmp(name, "2") == 0)
	{
		fractal->cx = -0.70176;
		fractal->cy = -0.3842;
	}
	else if (ft_strcmp(name, "3") == 0)
	{
		fractal->cx = -0.7269;
		fractal->cy = 0.1889;
	}
}

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFF5733;
	fractal->zoom = 300;
	fractal->max_iterations = 60;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, WIDTH, HIGHT, "Fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, WIDTH, HIGHT);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
}
