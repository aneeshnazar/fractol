/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:26:05 by anazar            #+#    #+#             */
/*   Updated: 2018/01/05 19:28:13 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <libft.h>
# include <math.h>
# include <mlx.h>
# define RANGE_CHANGE(x, a, b, min, max) (((b - a) * (x - min)/(max - min)) + a)

typedef struct			s_coord
{
	double		x;
	double		y;
}						t_coord;

typedef struct			s_mand
{
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		re_factor;
	double		im_factor;
	unsigned	iterations;
	double		c_im;
	double		c_re;
	double		z_re;
	double		z_im;
	double		z_re2;
	double		z_im2;
	double		mid_re;
	double		mid_im;
	int			is_inside;
	unsigned	color[11];
}						t_mand;

typedef struct			s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bits;
	int			s_line;
	int			endian;
	int			*pic;
	int			win_height;
	int			win_width;
	double		zoom;
	int			type;
	t_coord		midpoint;
	int			radius;
	int			lclicked;
	int			rclicked;
	t_coord		last_mouse_pos;
	t_coord		offset;
	int			draw;
	t_mand		mand;
	int			max_it;
}						t_fractol;

typedef unsigned int	t_color;

t_coord					init_coord(double x, double y);

int						init_img(t_fractol *fract);

void					draw_fractol(t_fractol *fract);

t_fractol				init_fractol(char *fract);

int						expose_event(t_fractol *fract);

int						motion_event(int x, int y, t_fractol *fract);

int						un_mouse_event(int b, int x, int y, t_fractol *fract);

int						mouse_event(int button, int x, int y, t_fractol *fract);

int						key_event(int keycode, t_fractol *fract);

void					fractol(char *str);

void					place_at(t_fractol *fract, int x, int y, t_color color);

void					julia(t_fractol *fract, int x, int y);

void					mandelbrot(t_fractol *fract, int x, int y);

void					burningship(t_fractol *fract, int x, int y);

t_color					get_color(t_fractol *fract, int i);

void					set_bounds(t_fractol *fract);

#endif
