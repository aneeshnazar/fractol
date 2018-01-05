/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:26:41 by anazar            #+#    #+#             */
/*   Updated: 2018/01/05 13:55:40 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		init_img(t_fractol *fract)
{
	int	x;
	int	y;

	y = 0;
	fract->img = mlx_new_image(fract->mlx, fract->win_width, fract->win_height);
	fract->pic = (int *)mlx_get_data_addr(fract->img,
			&fract->bits, &fract->s_line, &fract->endian);
	while (y < fract->win_height)
	{
		x = 0;
		while (x < fract->win_width)
		{
			if (fract->type == 1)
				julia(fract, x, y);
			if (fract->type == 2)
				mandelbrot(fract, x, y);
			if (fract->type == 3)
				burningship(fract, x, y);
			++x;
		}
		++y;
	}
	return (fract->win_width);
}
