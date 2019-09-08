#include "fractol.h"

void init_julia(t_data *all)
{
    all->real_change = 0;
	all->imagine_change = 0;
    all->cRe = -0.7 + all->real_change;
    all->cIm = 0.27015 + all->imagine_change;
    all->maxIterations = 50;
    all->minReal = -2.05;
    all->minImagine = -1.3;
    all->maxReal  = 1.2;
    all->maxImagine = 1.2;
    all->color1 = 0xd482e8;
	all->color2 = 0x82b0ff;
    all->moveX = 0;
    all->moveY = 0;
    draw_julia(all);
}

void draw_julia(t_data *all)
{
    for(int y = 0; y < all->image_height; y++)
    {
        for(int x = 0; x < all->image_width; x++)
        {
        //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
        all->maxReal = 1.5 * (x - all->image_width / 2) / (0.5 * all->zoom * all->image_width) + all->moveX;
        all->maxImagine = (y - all->image_height / 2) / (0.5 * all->zoom * all->image_height) + all->moveY;
        //i will represent the number of iterations
        int i;
        //start the iteration process
        for(i = 0; i < all->maxIterations; i++)
        {
            //remember value of previous iteration
            all->minReal = all->maxReal;
            all->minImagine = all->maxImagine;
            //the actual iteration, the real and imaginary part are calculated
            all->maxReal = all->minReal * all->minReal - all->minImagine * all->minImagine + all->cRe;
            all->maxImagine = 2 * all->minReal * all->minImagine + all->cIm;
            //if the point is outside the circle with radius 2: stop
            if((all->maxReal * all->maxReal + all->maxImagine * all->maxImagine) > 4) 
                break;
            if (i > 0 && i < all->maxIterations / 2)
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, (all->color1 * i));
            else if (i < all->maxIterations && i > all->maxIterations / 2)
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, (all->color2 * i));
            else
                mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, 0x000000);
        }
        }
    }
}