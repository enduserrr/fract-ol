/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:46:21 by asalo             #+#    #+#             */
/*   Updated: 2024/03/16 18:51:50 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

static void	julia_params(char *arg2, char *arg3, t_fractal *fractal)
{
	int i;

	i = 0;
	
	if (arg2[i] == '-' && i != 0)
		error_exit(0);
	else if (!ft_isdigit(arg2[i]))
		error_exit(0);
	else if (arg3[i] == '-' && i != 0)
		error_exit(0);
	else if (!ft_isdigit(arg3[i]))
		error_exit(0);
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
		fractal->cx = 0.4;
		fractal->cy = 0.4;
	}
}

static void	check_input(int argc, char **argv)
{
	if (argc < 2 || !argv[1][0] || argc > 4)
		error_exit(0);
	else if (ft_strcmp(argv[1], "mandel") != 0 
			&& ft_strcmp(argv[1], "julia") != 0
			&& ft_strcmp(argv[1], "help") != 0)
		error_exit(0);
	else if (ft_strcmp(argv[1], "mandel") == 0 && argc > 2)
		error_exit(0);
	else if (ft_strcmp(argv[1], "help") == 0)
		error_exit(1);
}
// static void	arg34(char *arg2, char *arg3)
// {
// 	int	i;

// 	i = 0;
// 	while (i < ft_strlen(arg2))
// 	{
		
// 		if (arg2[i] == "-" && !ft_isdigit(ft_atoi(arg2[i + 1])))
// 			error_exit(0);
// 		else if (arg2[i] == "." && !ft_isdigit(ft_atoi(arg2[i + 1]))
// 			&& !ft_isdigit(ft_atoi(arg2[i - 1])))
// 			error_exit(0);
// 		else if (!ft_isdigit(ft_atoi(arg2)))
// 			error_exit(0);
// 	}
// }
int	main(int argc, char **argv)
{
	t_fractal			*fractal;
	static t_fractal	fractal_instance;

	fractal = &fractal_instance;
	check_input(argc, argv);
	init_fractal(fractal);
	if (argc == 3 && ft_strcmp(argv[1], "julia") == 0)
		julia_options(fractal, argv[2]);
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
		julia_params(argv[2], argv[3], fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, clean_exit, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
