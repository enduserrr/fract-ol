/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:10:10 by asalo             #+#    #+#             */
/*   Updated: 2024/03/16 17:05:09 by asalo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fractol.h"

void	instructions(char *help)
{
	if (ft_strcmp(help, "help") == 0)
	{
		ft_printf("_________________________\n");
		ft_printf("\n\n\tCOMMANDS\n");
		ft_printf("\nESC\t\t:exit fractal");
		ft_printf("\nSCROLL\t\t:zoom in/out");
		ft_printf("\nA/D\t\t:horizontal movement");
		ft_printf("\nW/D\t\t:vertical movent");
		ft_printf("\nC\t\t:change color");
		ft_printf("\nP\t\t:increase depth");
		ft_printf("\nM\t\t:decrease depth");
		ft_printf("\nJ\t\t:generate random (julia)");
		ft_printf("\nR\t\t:reset the fractal\n");
		ft_printf("___________________________________________\n");
		ft_printf("\n./fractol <mandel> OR ./fractol <julia> <option>\n");
		ft_printf("[options: empty, 0-3 or custom (0.259 -0.045)]\n");
		ft_printf("_________________________________\n");
	}
}

double	ft_atod(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}

void	error_exit(int type)
{
	if (type == 0)
	{
		ft_printf("%s\n", "ERROR: INCORRECT INPUT");
		ft_printf("For instructions: ./fractol help\n");
	}
	else if (type == 1)
		instructions("help");
	exit(1);
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
