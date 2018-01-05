/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:24:01 by anazar            #+#    #+#             */
/*   Updated: 2018/01/04 16:52:33 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_find("julia mandelbrot bship", argv[1]) != -1)
			fractol(argv[1]);
		else
			ft_putendl("Please try again.\n");
	}
	else
	{
		ft_putendl("Please specify a fractol.");
		ft_putendl("usage:\t./fractol [fractal name]\n");
	}
	ft_putendl("These are the available fractals:");
	ft_putendl("\t>julia\n\t>mandelbrot\n\tbship");
	return (0);
}
