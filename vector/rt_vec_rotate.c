/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:18:06 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 04:34:16 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>

#include "rt_vector.h"

t_axis	rotate_axis_x(t_rotate *rotate, int positive_flag)
{
	t_axis	tmp;

	tmp.x = rotate->axis.x;
	tmp.y = rotate_vec(rotate->axis.y, rotate->axis.x, positive_flag);
	tmp.z = rotate_vec(rotate->axis.z, rotate->axis.x, positive_flag);
	return (tmp);
}

t_axis	rotate_axis_y(t_rotate *rotate, int positive_flag)
{
	t_axis	tmp;

	tmp.x = rotate_vec(rotate->axis.x, rotate->axis.y, positive_flag);
	tmp.y = rotate->axis.y;
	tmp.z = rotate_vec(rotate->axis.z, rotate->axis.y, positive_flag);
	return (tmp);
}

t_axis	rotate_axis_z(t_rotate *rotate, int positive_flag)
{
	t_axis	tmp;

	tmp.x = rotate_vec(rotate->axis.x, rotate->axis.z, positive_flag);
	tmp.y = rotate_vec(rotate->axis.y, rotate->axis.z, positive_flag);
	tmp.z = rotate->axis.z;
	return (tmp);
}

t_vec	rotate_vec(t_vec v, t_vec axis, int positive_flag)
{
	double	cos;
	double	sin;
	double	dot;
	t_vec	cross;
	t_vec	rotated_v;

	cos = sin_cos(RT_COS, positive_flag);
	sin = sin_cos(RT_SIN, positive_flag);
	cross = v_cross(axis, v);
	dot = v_dot(axis, v);
	rotated_v.x = v.x * cos + cross.x * sin + axis.x * dot * (1 - cos);
	rotated_v.y = v.y * cos + cross.y * sin + axis.y * dot * (1 - cos);
	rotated_v.z = v.z * cos + cross.z * sin + axis.z * dot * (1 - cos);
	return (rotated_v);
}

double	sin_cos(int sin_cos_flag, int positive_flag)
{
	static bool		init;
	static double	tri[4];
	int				idx;

	if (!init)
	{
		init = true;
		tri[0] = sin(-RT_RADIAN);
		tri[1] = sin(RT_RADIAN);
		tri[2] = cos(-RT_RADIAN);
		tri[3] = cos(RT_RADIAN);
	}
	idx = (sin_cos_flag * 2 + positive_flag);
	return (tri[idx]);
}
