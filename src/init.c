#include "../incs/fractol.h"

static void	julia_offset(t_fractal *fractal)
{
	fractal->offset_x = -1.3255;
	fractal->offset_y = -0.995;
	fractal->name = "julia";
}

static void	mandel_offset(t_fractal *fractal)
{
	fractal->offset_x = -2.03;
	fractal->offset_y = -1.05;
	fractal->name = "mandel";
}

void	init_fractal(t_fractal *fractal, char *name)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0x114ffc;
	fractal->zoom = 300;
	fractal->max_iterations = 60;
	if (ft_strcmp(name, "mandel") == 0)
		mandel_offset(fractal);
	else if (ft_strcmp(name, "julia") == 0)
		julia_offset(fractal);
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
