#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "./libft/header/libft.h"
# include "./minilibx/mlx.h"
# include <stdbool.h>
# include<stdlib.h>
# include<time.h>
 
#define pi M_PI

typedef struct	s_all
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			color1;
	int 		color2;
	int 		image_height;
	int			image_width;
	double		cRe;
	double		cIm;
	char*		name;
	double		zoom;
	double		maxReal;
	double		minReal;
	double		maxImagine;
	double		minImagine;
	int			mouse_x;
	int			mouse_y;
	int			real_change;
	int			imagine_change;
	unsigned int maxIterations;
	double		z_re;
	double		z_im;
	double		interpolation;
	int			moveX;
	int			moveY;
	int			n;
}				t_data;

void	draw_mandel(t_data *all);
void	draw_julia(t_data *all);
int		mouse_hook(int mousecode, int x, int y, t_data *all);
void	change_julia(t_data *all, int mousecode);
int		exit_key(int key, t_data *all);
// void	zoom(int mouse_re, int mouse_im, t_data *all);
// double	interpolate(double start, double end, double interpolation);
// int		mouse_drag(int x, int y, t_data *all);
// void	mouse_manage_if(int mousecode, int x, int y, t_data *all);
int		mouse_manage(int mousecode, int x, int y, t_data *all);
void	zoom_it(int x, int y, t_data *all);
void 	init_julia(t_data *all);

void 	sierpinski(t_data *all);
void	init_sierpinski(t_data *all);

void 	init_mandel(t_data *all);



#endif
