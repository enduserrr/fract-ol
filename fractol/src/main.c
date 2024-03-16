/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:46:21 by asalo             #+#    #+#             */
/*   Updated: 2024/03/16 11:09:37 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	error_exit(t_fractal *fractal, int type)
{
	if (type == 0)
		ft_printf("%s\n", "error: missing argument");
	else if (type == 1)
		ft_printf("\nerror: incorrect argument");
		ft_printf("\ntry: ./fractol mandel/julia <options>");
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	exit(1);
}

void	julia_params(char *name, char *arg2, char *arg3, t_fractal *fractal)
{
	if (ft_strcmp(name, "julia") == 0)
	{
		fractal->cx = ft_atod(arg2);
		fractal->cy = ft_atod(arg3);
	}
}

int	main(int argc, char **argv)
{
	t_fractal			*fractal;
	static t_fractal	fractal_instance;

	fractal = &fractal_instance;
	if (argc < 2 || !argv[1][0])
		error_exit(fractal, 0);
	init_fractal(fractal);
	if (argc == 3 && ft_strcmp(argv[1], "julia") == 0)
		julia_options(fractal, argv[2]);
	else if (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
		julia_params(argv[1], argv[2], argv[3], fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, clean_exit, fractal);
	draw_fractal(fractal, argv[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
