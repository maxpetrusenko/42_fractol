#include "fractol.h"

void draw_mandel(t_data *all)
{
    double MinRe = -2.0;
    double MaxRe = 1.0;
    double MinIm = -1.2;
    double MaxIm = MinIm+(MaxRe-MinRe)*all->image_height/all->image_width;
    double Re_factor = (MaxRe-MinRe)/(all->image_width-1);
    double Im_factor = (MaxIm-MinIm)/(all->image_height-1);
    unsigned int MaxIterations = 100;
    unsigned int n = 0;

    for(unsigned y=0; y<all->image_height; ++y)
    {
        double c_im = MaxIm - y*Im_factor;
        for(unsigned x=0; x<all->image_width; ++x)
        {
            double c_re = MinRe + x*Re_factor;
            double Z_re = c_re, Z_im = c_im;
            bool isInside = true;
            for(n=0; n<MaxIterations; ++n)
            {
                double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
                if(Z_re2 + Z_im2 > 4)
                {
                    isInside = false;
                    break;
                }
                if(isInside && n < MaxIterations/2-1) 
                    mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, (all->color1) * n / 100);
                else
                    mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, (all->color2) * n / 20);
                Z_im = 2*Z_re*Z_im + c_im;
                Z_re = Z_re2 - Z_im2 + c_re;
            }
        }
    }
}
