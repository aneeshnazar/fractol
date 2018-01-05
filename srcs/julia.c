/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 22:33:45 by anazar            #+#    #+#             */
/*   Updated: 2018/01/05 13:45:00 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	julia(t_fractol *fract, int x, int y)
{
	int		i;
	double	scaled_x;
	double	scaled_y;
	double	x_tmp;

	scaled_x = RANGE_CHANGE(x, fract->mand.min_re, fract->mand.max_re,
			0, fract->win_width);
	scaled_y = RANGE_CHANGE(y, fract->mand.min_im, fract->mand.max_im,
			0, fract->win_height);
	i = 0;
	while (i < 40 && ((scaled_x * scaled_x + scaled_y * scaled_y) < 4))
	{
		x_tmp = scaled_x * scaled_x - scaled_y * scaled_y + scaled_x;
		scaled_y = 2 * scaled_x * scaled_y + scaled_y +
			RANGE_CHANGE(fract->midpoint.y, fract->mand.min_im,
					fract->mand.max_im, 0, fract->win_height);
		scaled_x = x_tmp +
			RANGE_CHANGE(fract->midpoint.x, fract->mand.min_im,
					fract->mand.max_im, 0, fract->win_width);
		++i;
	}
	place_at(fract, x, y, fract->mand.color[i / 4]);
}
