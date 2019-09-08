
#include "fractol.h"

int			exit_key(int key, t_data *all)
{
	if (key == 53)
		exit(0);
	return (0);
}

int			mouse_manage(int mousecode, int x, int y, t_data *all)
{
	if (ft_strcmp(all->name, "mandelbrot") == 0)
	{
		if (mousecode == 1 || mousecode == 5)
			zoom_it(x, y, all);
		else if (mousecode == 2 || mousecode == 4)
            //dezoom_it(x, y, all);
            draw_mandel(all);
		mlx_clear_window(all->mlx_ptr, all->win_ptr);
		draw_mandel(all);
	}
	else if (ft_strcmp(all->name, "julia") == 0)
	{
		if (mousecode == 1 || mousecode == 5)
			all->zoom *= 1.05;
		else if (mousecode == 2 || mousecode == 4)
            all->zoom /= 1.05;
        mlx_clear_window(all->mlx_ptr, all->win_ptr);
	    draw_julia(all);
	}
  
	else if( ft_strcmp(all->name, "other") == 0)
		sierpinski(all);
	return (0);
}

// void		mouse_manage_if(int mousecode, int x, int y, t_data *all)
// {
// 	double mouse_re = 0;
// 	double mouse_im = 0;
// 	all->mouse_x = 0;
// 	all->mouse_y = 0;
// 	all->real_change = 0;
// 	all->imagine_change = 0;

// 	mouse_re = (double)x / (all->image_width / (all->maxReal - all->minReal))
// 	+ all->minReal;
// 	mouse_im = (double)y / (all->image_height / (all->maxImagine
// 	- all->minImagine)) + all->minImagine;
// 	if (mousecode == 1 || mousecode == 5)
// 	{
// 		all->zoom *= 1.04;
// 		zoom(mouse_re, mouse_im, all);
// 	}
// 	else if (mousecode == 2 || mousecode == 4)
// 	{
// 		all->zoom = 1.0 / 1.05;
// 		zoom(mouse_re, mouse_im, all);
// 	}
// 	mlx_clear_window(all->mlx_ptr, all->win_ptr);
// 	draw_mandel(all);
// }R

void	zoom_it(int x, int y, t_data *all)
{
	all->cRe = (x / all->zoom + all->cRe) - (x / (all->zoom * 1.2));
	all->cIm = (y / all->zoom + all->cIm) - (y / (all->zoom * 1.2));
	all->zoom *= 1.2;
	all->n++;
}

// int			mouse_drag(int x, int y, t_data *all)
// {
// 	if ((x < 900 && x > 0) && (y < 900 && y > 0))
// 	{
// 		if (x > all->mouse_x)
// 			all->real_change += 0.1;
// 		else
// 			all->real_change -= 0.1;
// 		if (y > all->mouse_y)
// 			all->imagine_change += 0.1;
// 		else
// 			all->imagine_change -= 0.1;
// 	}
// 	all->mouse_x = x;
// 	all->mouse_y = y;
// 	mlx_clear_window(all->mlx_ptr, all->win_ptr);
// 	if (ft_strcmp(all->name, "mandelbrot") == 0)
// 		draw_mandel(all);
// 	else if (ft_strcmp(all->name, "julia") == 0)
// 		draw_julia(all);
// 	else if( ft_strcmp(all->name, "other") == 0)
// 		sierpinski(all);
// 	return (0);
// }

// double		interpolate(double start, double end, double interpolation)
// {
// 	return (start + ((end - start) * interpolation));
// }

// void		zoom(int mouse_re, int mouse_im, t_data *all)
// {
// 	all->interpolation = 1.0 / all->zoom;
// 	all->minReal = interpolate(mouse_re, all->minReal, all->interpolation);
// 	all->minImagine = interpolate(mouse_im, all->minImagine, all->interpolation);
// 	all->maxReal = interpolate(mouse_re, all->maxReal, all->interpolation);
// 	all->maxImagine = interpolate(mouse_im, all->maxImagine, all->interpolation);
// }