/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:02:41 by anazar            #+#    #+#             */
/*   Updated: 2018/01/05 13:48:05 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	iterate(double scaled_x, double scaled_y)
{
	double	x0;
	double	y0;
	double	x_tmp;
	int		i;

	x0 = 0.0;
	y0 = 0.0;
	i = 0;
	while (i < 40 && ((x0 * x0 + y0 * y0) < 4))
	{
		x_tmp = x0 * x0 - y0 * y0 + scaled_x;
		y0 = ABS(2 * x0 * y0 + scaled_y);
		x0 = ABS(x_tmp);
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
	i = iterate(scaled_x, scaled_y);
	place_at(fract, x, y, fract->mand.color[i / 4]);
}
