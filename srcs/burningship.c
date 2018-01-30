/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:02:41 by anazar            #+#    #+#             */
/*   Updated: 2018/01/29 21:48:55 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <math.h>

static int	iterate(int max_it, double scaled_x, double scaled_y)
{
	double	x0;
	double	y0;
	double	x_tmp;
	int		i;

	x0 = 0.0;
	y0 = 0.0;
	i = 0;
	while (i < max_it && ((x0 * x0 + y0 * y0) < 4.0))
	{
		x_tmp = x0 * x0 - y0 * y0 + scaled_x;
		y0 = fabs(2 * x0 * y0 + scaled_y);
		x0 = fabs(x_tmp);
		++i;
	}
	return (i);
}

void		burningship(t_fractol *fract, int x, int y)
{
	int		i;
	double	scaled_x;
	double	scaled_y;

	scaled_x = RANGE_CHANGE(x, fract->mand.min_re, fract->mand.max_re,
			0, fract->win_width);
	scaled_y = RANGE_CHANGE(y, fract->mand.min_im, fract->mand.max_im,
			0, fract->win_height);
	i = iterate(fract->max_it, scaled_x, scaled_y);
	place_at(fract, x, y, get_color(fract, i));
}
