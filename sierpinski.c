#include "fractol.h"

/*
** Surprise - sierpinki pemntagin! As the number of sides increases, the number of 
Iterations must increase dramatically for a well pronounced fractal ( 30000 for a pentagon!)
*/

void	init_sierpinski(t_data *all)
{
	all->color1 = 0xffff00;
	all->color2= 0x0000ff;
	all->maxIterations = 6000;
}

void sierpinski(t_data *all)
{
	init_sierpinski(all);
	time_t t;
	double side, **vertices,seedX,seedY,windowSide = 500,sumX=0,sumY=0;
	int i,choice,numSides;
 
	numSides = 200;
 	side = 460;
	vertices = (double**)malloc(numSides*sizeof(double*));
	
	for(i=0;i<numSides;i++){
		vertices[i] = (double*)malloc(2 * sizeof(double));
 
		vertices[i][0] = all->image_height/2 + side*cos(i*2*pi/numSides);
		vertices[i][1] = all->image_width/2 + side*sin(i*2*pi/numSides);
		sumX+= vertices[i][0];
		sumY+= vertices[i][1];
		mlx_pixel_put(all->mlx_ptr, all->win_ptr, vertices[i][0], vertices[i][1], (all->color1 * i));
	}
	srand((unsigned)time(&t));
	seedX = sumX/numSides;
	seedY = sumY/numSides;
	mlx_pixel_put(all->mlx_ptr, all->win_ptr, seedX, seedY, all->color2);
	for(i=0;i<all->maxIterations;i++){
		choice = rand()%numSides;
 
		seedX = (seedX + (numSides-2)*vertices[choice][0])/(numSides-1);
		seedY = (seedY + (numSides-2)*vertices[choice][1])/(numSides-1);
		mlx_pixel_put(all->mlx_ptr, all->win_ptr, seedX, seedY, (all->color2 * i));
	}
	
	free(vertices);
}
 
 