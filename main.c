#include "fractol.h"

/*
** Magic start here. Let's see what fractol they want to see....

*/


static void init_init(t_data *all)
{
    all->real_change = 0;
    all->imagine_change = 0;

}

int		main(int argc, char **argv)
{
	t_data *all = malloc(sizeof(t_data));
	all->image_height = 1000;
	all->image_width = 1000;
	all->zoom = 1;
	init_init(all);

	if (argc == 2)
	{
		all->mlx_ptr = mlx_init();
		all->win_ptr = mlx_new_window(all->mlx_ptr, all->image_height, all->image_width, "Fractols - mpetruse");
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
		{
			all->name = "mandelbrot";
			init_mandel(all);
		}
		else if (ft_strcmp(argv[1], "julia") == 0)
		{
			all->name = "julia";
			init_julia(all);
		}
		else if (ft_strcmp(argv[1], "other") == 0)
		{
			all->name = "other";
			sierpinski(all);
		}
		else
			ft_printf("Usage: ./fractol [julia] or [mandelbrot] or [other]");
		mlx_hook(all->win_ptr, 2, 5, exit_key, all);
		mlx_mouse_hook(all->win_ptr, mouse_manage, all);
		mlx_hook(all->win_ptr, 6, 5, mouse_drag, all);
		mlx_loop(all->mlx_ptr);
		free(all);
	}
	else if (argc > 2)
		ft_printf("try ./fractol arg (ex. : ./fractol mendelbrot).Only one argument allowed");
	else
		ft_printf("Don't forget the name of fractol: ./fractol arg (ex. : ./fractol mendelbrot).");
}

