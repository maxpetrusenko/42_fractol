#include "fractol.h"

void init_mandel(t_data *all)
{
    all->color1 = 0x800080;
	all->color2 = 0xffff1a;
    all->minReal = -2.0;
    all->maxReal = 1.0;
    all->minImagine = -1.2;
    all->maxImagine = all->minImagine+(all->maxReal-all->minReal)*all->image_height/all->image_width;
    all->cRe = (all->maxReal-all->minReal)/(all->image_width-1);
    all->cIm = (all->maxImagine-all->minImagine)/(all->image_height-1);
    all->maxIterations = 150;
    all->n = 0;
    all->cRe = (all->maxReal - all->minReal)/(all->image_width-1);
    all->cIm = (all->maxImagine - all->minImagine)/(all->image_height-1);
    draw_mandel(all);
}

void draw_mandel(t_data *all)
{
    mlx_string_put(all->mlx_ptr, all->win_ptr, 500, 40, 0xffffff,
		"Fractal 1: Mandelbrot Set");
    
    all->maxReal = 1.0;
    all->maxImagine = all->minImagine+(all->maxReal-all->minReal)*all->image_height/all->image_width;
    all->cRe = (all->maxReal - all->minReal)/(all->image_width-1);
    all->cIm = (all->maxImagine - all->minImagine)/(all->image_height-1);
    all->maxIterations = 150;

    for(unsigned y=0; y<all->image_height; ++y)
    {
        double c_im = all->maxImagine - y*all->cIm;
        for(unsigned x=0; x<all->image_width; ++x)
        {
            double c_re = all->minReal + x*all->cRe;
            double Z_re = c_re, Z_im = c_im;
            bool isInside = true;
            for(all->n=0; all->n<all->maxIterations; ++all->n)
            {
                double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
                if(Z_re2 + Z_im2 > 4)
                {
                    isInside = false;
                    break;
                }
                if(isInside && all->n < all->maxIterations/2-1) 
                    mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, (all->color1) * all->n / 100);
                else
                    mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, (all->color2) * all->n / 20);
                Z_im = 2*Z_re*Z_im + c_im;
                Z_re = Z_re2 - Z_im2 + c_re;
            }
        }
    }
}
