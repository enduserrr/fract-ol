/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:46:21 by asalo             #+#    #+#             */
/*   Updated: 2024/03/18 12:37:40 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

static void	julia_params(char *arg2, char *arg3, t_fractal *fractal)
{
	fractal->cx = ft_atod(arg2);
	fractal->cy = ft_atod(arg3);
}

static void	julia_options(t_fractal	*fractal, char *name)
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
		fractal->cx = -0.4;
		fractal->cy = -0.4;
	}
	else
		error_exit(0);
}

static void	check_input(t_fractal *fractal, int argc, char **argv)
{
	if (argc < 2 || !argv[1][0] || argc > 4)
		error_exit(0);
	else if (ft_strcmp(argv[1], "mandel") != 0
		&& ft_strcmp(argv[1], "julia") != 0
		&& ft_strcmp(argv[1], "help") != 0)
		error_exit(0);
	else if (ft_strcmp(argv[1], "mandel") == 0 && argc != 2)
		error_exit(0);
	if (ft_strcmp(argv[1], "help") == 0)
		instructions(argv[1]);
	if (argc == 3 && ft_strcmp(argv[1], "julia") == 0)
		julia_options(fractal, argv[2]);
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
		julia_params(argv[2], argv[3], fractal);
}

int	main(int argc, char **argv)
{
	t_fractal			*fractal;
	static t_fractal	fractal_instance;
	long				n;
	int					i;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_exit(0);
		i++;
	}
	fractal = &fractal_instance;
	check_input(fractal, argc, argv);
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, clean_exit, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
