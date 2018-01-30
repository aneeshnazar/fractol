/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:09:28 by anazar            #+#    #+#             */
/*   Updated: 2018/01/29 21:55:12 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

t_color		get_color(t_fractol *fract, int i)
{
	int		val;
	int		m_it;

	m_it = fract->max_it <= 0 ? 1 : fract->max_it;
	val = RANGE_CHANGE(i, 0, 256, 0, m_it);
	return ((256 - val) << 16 | val);
//	return (val << 8);
}
