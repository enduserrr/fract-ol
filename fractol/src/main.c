/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:46:21 by asalo             #+#    #+#             */
/*   Updated: 2024/03/15 11:44:31 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

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
	if (argc > 2)
	{
		ft_printf("%s\n", "error: too many arguments");
		exit(1);
	}
	check_input(argv[1]);
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, clean_exit, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
