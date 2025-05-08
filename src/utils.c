#include "../incs/fractol.h"

void	instructions(char *help)
{
	if (ft_strcmp(help, "help") == 0)
	{
		ft_printf("_________________________\n");
		ft_printf("\n\n\tCOMMANDS\n");
		ft_printf("\nESC\t\t:exit fractal");
		ft_printf("\nSCROLL\t\t:zoom in/out");
		ft_printf("\nA/D & ←/→\t:horizontal movement");
		ft_printf("\nW/D & ↑/↓\t:vertical movent");
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

void	error_exit(int type)
{
	if (type == 0)
	{
		ft_printf("%s\n", "ERROR: INCORRECT INPUT");
		ft_printf("For instructions: ./fractol help\n");
		exit(1);
	}
	if (type == 1)
	{
		ft_printf("ERROR:\nChoose a valid fractal to run.\n");
		ft_printf("Available fractals: Mandelbrot (mandel) & Julia (julia).\n");
		ft_printf("For more help try: './fractal help'\n");
		exit(1);
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
			fractal->max_iterations -= 21;
	}
	else if (key_code == P)
	{
		if (fractal->max_iterations < 4200)
			fractal->max_iterations += 21;
	}
}
