/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:42:02 by anazar            #+#    #+#             */
/*   Updated: 2018/01/05 19:38:38 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_event(int keycode, t_fractol *fract)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 27)
		--fract->max_it;
	if (keycode == 24)
		++fract->max_it;
	if (keycode == 123)
		fract->mand.mid_re += fract->zoom / 10;
	if (keycode == 124)
		fract->mand.mid_re -= fract->zoom / 10;
	if (keycode == 126)
		fract->mand.mid_im += fract->zoom / 10;
	if (keycode == 125)
		fract->mand.mid_im -= fract->zoom / 10;
	set_bounds(fract);
	fract->draw = 1;
	return (0);
}

int		mouse_event(int button, int x, int y, t_fractol *fract)
{
	if (button == 1)
	{
		fract->lclicked = 1;
		fract->offset = init_coord(fract->midpoint.x - x,
				fract->midpoint.y - y);
	}
	if (button == 2)
		fract->rclicked = 1;
	if (button == 4)
		fract->zoom += 0.1;
	if (button == 5)
		fract->zoom -= 0.1;
	set_bounds(fract);
	fract->draw = 1;
	return (0);
}

int		un_mouse_event(int button, int x, int y, t_fractol *fract)
{
	if (button == 1)
		fract->lclicked = 0;
	if (button == 2)
		fract->rclicked = 0;
	fract->offset = init_coord(x, y);
	fract->draw = 1;
	return (0);
}

int		motion_event(int x, int y, t_fractol *fract)
{
	if (x < fract->win_width && y < fract->win_height)
	{
		fract->midpoint = init_coord(x + fract->offset.x, y +
					fract->offset.y);
		fract->draw = 1;
	}
	return (0);
}

int		expose_event(t_fractol *fract)
{
	fract->draw = 1;
	return (0);
}
