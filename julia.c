#include "fractol.h"

void draw_julia(t_data *all)
{
    double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
    double zoom = 1;
    double moveX = 0;
    double moveY = 0; //you can change these to zoom and change position
    int maxIterations = 300; //after how much iterations the function should stop

    //pick some values for the constant c, this determines the shape of the Julia Set
    all->cRe = -0.7;
    all->cIm = 0.27015;

    //loop through every pixel
    for(int y = 0; y < all->image_height; y++)
    {
        for(int x = 0; x < all->image_width; x++)
        {
        //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
        newRe = 1.5 * (x - all->image_width / 2) / (0.5 * zoom * all->image_width) + moveX;
        newIm = (y - all->image_height / 2) / (0.5 * zoom * all->image_height) + moveY;
        //i will represent the number of iterations
        int i;
        //start the iteration process
        for(i = 0; i < maxIterations; i++)
        {
            //remember value of previous iteration
            oldRe = newRe;
            oldIm = newIm;
            //the actual iteration, the real and imaginary part are calculated
            newRe = oldRe * oldRe - oldIm * oldIm + all->cRe;
            newIm = 2 * oldRe * oldIm + all->cIm;
            //if the point is outside the circle with radius 2: stop
            if((newRe * newRe + newIm * newIm) > 4) 
                break;
            if (i > 0 && i < maxIterations / 2)
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, (all->color1 * i));
            else if (i < maxIterations && i > maxIterations / 2)
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, (all->color2 * i));
            else
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, 0x000000);
        }
        }
    }
}


//VLAD will help you here
void	change_julia(t_data *all, int mousecode)
{
	if (mousecode == 2 || mousecode == 5)
    {
        all->cRe = all->cRe + 1;
        all->cIm = all->cIm + 1;
    }
	else if (mousecode == 4 || mousecode == 1)
	{
		all->cRe = all->cRe - 1;
        all->cIm = all->cIm - 1;
	}
	mlx_clear_window(all->mlx_ptr, all->win_ptr);
	draw_julia(all);
}

int		mouse_hook(int mousecode, int x, int y, t_data *all)
{

		if (mousecode == 5 || mousecode == 2)
            change_julia(all, mousecode);
        return (0);
}