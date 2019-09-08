#include "fractol.h"

/*
** Magic start here. Let's see what fractol they want to see....
*/
int		main(int argc, char **argv)
{
	t_data *all = malloc(sizeof(t_data));
	all->image_height = 800;
	all->image_width = 600;
	all->color1 = 0x800080;
	all->color2 = 0xffff1a;

	if (argc == 2)
	{
		all->mlx_ptr = mlx_init();
		all->win_ptr = mlx_new_window(all->mlx_ptr, all->image_height, all->image_width, "Fractols - mpetruse");
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			draw_mandel(all);
		else if (ft_strcmp(argv[1], "julia") == 0)
			draw_julia(all);
		// else if (ft_strcmp(argv[1], "other") == 0)
		// 	// fern_init(all);
		else
			ft_printf("Usage: ./fractol [julia] or [mandelbrot] or [other]");
		// mlx_key_hook(all->win_ptr, keys, all);
		mlx_hook(all->win_ptr, 4, 0, mouse_hook, all);
		mlx_loop(all->mlx_ptr);
		free(all);
	}
	else if (argc > 2)
		ft_printf("try ./fractol arg (ex. : ./fractol mendelbrot).Only one argument allowed");
	else
		ft_printf("Don't forget the name of fractol: ./fractol arg (ex. : ./fractol mendelbrot).");
}
