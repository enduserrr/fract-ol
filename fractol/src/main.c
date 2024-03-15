/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:46:21 by asalo             #+#    #+#             */
/*   Updated: 2024/03/15 19:44:26 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	julia_params(char *name, char *arg2, char *arg3, t_fractal *fractal)
{
	if (ft_strcmp(name, "julia") == 0)
	{
		fractal->x = ft_atod(arg2);
		fractal->y = ft_atod(arg3);
		fractal->color = 0xFF5733;
		fractal->zoom = 300;
		fractal->offset_x = -1.21;
		fractal->offset_y = -1.21;
		fractal->max_iterations = 60;
	}
}

int	main(int argc, char **argv)
{
	t_fractal			*fractal;
	static t_fractal	fractal_instance;

	fractal = &fractal_instance;
	if (argc < 2 || !argv[1][0])
	{
		ft_printf("%s\n", "error: missing argument");
		exit(1);
	}
	if (argc == 2)
		init_fractal(fractal);
	else if (argc == 4)
		julia_params(argv[1], argv[2], argv[3], fractal);
	// check_input(argv[1]);
	// init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, clean_exit, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
