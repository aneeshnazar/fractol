/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:36:48 by anazar            #+#    #+#             */
/*   Updated: 2018/01/29 21:33:54 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		init_color(t_fractol *fract)
{
	fract->mand.color[0] = 0x000000;
	fract->mand.color[1] = 0x002200;
	fract->mand.color[2] = 0x004400;
	fract->mand.color[3] = 0x006600;
	fract->mand.color[4] = 0x007700;
	fract->mand.color[5] = 0x008800;
	fract->mand.color[6] = 0x009900;
	fract->mand.color[7] = 0x00AA00;
	fract->mand.color[8] = 0x00BB00;
	fract->mand.color[9] = 0x00DD00;
	fract->mand.color[10] = 0x00FF00;
}

t_fractol	init_fractol(char *str)
{
	t_fractol	fract;

	fract.win_width = 1000;
	fract.win_height = 1000;
	fract.mlx = mlx_init();
	fract.win = mlx_new_window(fract.mlx, fract.win_width,
			fract.win_height, "fractol");
	fract.zoom = init_img(&fract);
	fract.midpoint = init_coord(fract.win_width / 2, fract.win_height / 2);
	fract.radius = 200;
	if (!ft_strcmp(str, "julia"))
		fract.type = 1;
	else if (!ft_strcmp(str, "mandelbrot"))
		fract.type = 2;
	else if (!ft_strcmp(str, "bship"))
		fract.type = 3;
	else
	{
		ft_putendl("Invalid fractol entered.");
		exit(0);
	}
	init_color(&fract);
	fract.max_it = 40;
	return (fract);
}
