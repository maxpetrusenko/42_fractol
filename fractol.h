#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "./libft/header/libft.h"
# include "./minilibx/mlx.h"
# include <stdbool.h>

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
}				t_data;

void draw_mandel(t_data *all);
void draw_julia(t_data *all);
int		mouse_hook(int mousecode, int x, int y, t_data *all);
void	change_julia(t_data *all, int mousecode);


#endif
