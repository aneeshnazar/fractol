/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:44:57 by anazar            #+#    #+#             */
/*   Updated: 2018/01/05 13:48:49 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	place_at(t_fractol *fract, int x, int y, unsigned int color)
{
	int		pos;

	pos = x + (y * fract->s_line / 4);
	if (pos >= 0 && pos < fract->win_height * fract->win_width)
		if ((x >= 0 && x < fract->win_width) &&
				(y >= 0 && y < fract->win_height))
			fract->pic[pos] = color;
}
