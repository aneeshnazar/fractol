/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:57:05 by anazar            #+#    #+#             */
/*   Updated: 2018/01/05 19:29:06 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>
#include <stdio.h>

int		close_window(t_fractol *fract)
{
	mlx_destroy_window(fract->mlx, fract->win);
	exit(0);
	return (1);
}

void	init_hooks(t_fractol *fract)
{
	mlx_hook(fract->win, 2, 0, key_event, fract);
	mlx_hook(fract->win, 4, 0, mouse_event, fract);
	mlx_hook(fract->win, 5, 0, un_mouse_event, fract);
	mlx_hook(fract->win, 6, 0, motion_event, fract);
	mlx_hook(fract->win, 12, 0, expose_event, fract);
	mlx_hook(fract->win, 17, 0, close_window, fract);
}

int		hook(t_fractol *fract)
{
	if (!fract->draw)
		return (0);
	draw_fractol(fract);
	fract->draw = 0;
	return (0);
}

void	fractol(char *str)
{
	t_fractol	fract;

	fract = init_fractol(str);
	fract.zoom = 1;
	fract.offset = init_coord(0, 0);
	fract.mand.mid_re = 0.0;
	fract.mand.mid_im = 0.0;
	set_bounds(&fract);
	expose_event(&fract);
	init_hooks(&fract);
	mlx_loop_hook(fract.mlx, hook, &fract);
	mlx_loop(fract.mlx);
}
