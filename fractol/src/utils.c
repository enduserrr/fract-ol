/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:10:10 by asalo             #+#    #+#             */
/*   Updated: 2024/03/15 13:07:51 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	check_input(char *option)
{
	if (ft_strcmp(option, "mandel") != 0
		&& ft_strcmp(option, "julia") != 0)
	{
		ft_printf("error: incorrect argument!!!!!\n");
		ft_printf("\n\tINSTRUCTIONS\n");
		ft_printf("\nESC\t\t:exit fractal");
		ft_printf("\nSCROLL\t\t:zoom in/out");
		ft_printf("\nA/D\t\t:horizontal movement");
		ft_printf("\nW/D\t\t:vertical movent");
		ft_printf("\nC\t\t:change color");
		ft_printf("\nP\t\t:increase depth");
		ft_printf("\nM\t\t:decrease depth");
		ft_printf("\nJ\t\t:generate random (julia)");
		ft_printf("\nR\t\t:reset the fractal\n");
		ft_printf("--------------------------------------------------\n");
		ft_printf("try: './fractol <fractal_name>' (julia or mandel)\n");
		ft_printf("--------------------------------------------------\n");
		exit (1);
	}
}

int	clean_exit(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	exit(0);
}

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == M)
	{
		if (fractal->max_iterations > 42)
			fractal->max_iterations -= 42;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 42;
	}
}
