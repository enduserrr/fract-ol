/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalo <asalo@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 09:10:10 by asalo             #+#    #+#             */
/*   Updated: 2024/03/18 13:16:36 by asalo            ###   ########.fr       */
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
		ft_printf("\nA/D & ←/→\t\t:horizontal movement");
		ft_printf("\nW/D & ↑/↓\t\t:vertical movent");
		ft_printf("\nC\t\t:change color");
		ft_printf("\nP\t\t:increase depth");
		ft_printf("\nM\t\t:decrease depth");
		ft_printf("\nJ\t\t:generate random (julia)");
		ft_printf("\nR\t\t:reset the fractal\n");
		ft_printf("___________________________________________\n");
		ft_printf("\n\n\tEXECUTE\n");
		ft_printf("\n'./fractol <mandel>' & './fractol <julia> <option>'\n");
		ft_printf("\noptions:\n→ empty ()\n");
		ft_printf("→ 0 (x=-0.8, y=0.156)\n→ 1 (x=0.285, y=0.01)\n");
		ft_printf("→ 2 (x=-0.70176, y=-0.3842)\n→ 3 (x=-0.4, y=-0.4)");
		ft_printf("\n→ custom (e.g. 0.259 -0.045 or 0.4 -0.4)\n");
		ft_printf("_________________________________\n");
		exit (0);
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
