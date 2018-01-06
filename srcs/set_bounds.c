/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_bounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 19:26:13 by anazar            #+#    #+#             */
/*   Updated: 2018/01/05 19:27:56 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	set_bounds(t_fractol *fract)
{
	fract->mand.min_re = fract->mand.mid_re - fract->zoom;
	fract->mand.max_re = fract->mand.mid_re + fract->zoom;
	fract->mand.min_im = fract->mand.mid_im - fract->zoom;
	fract->mand.max_im = fract->mand.mid_im + fract->zoom;
}
