/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_op_product.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:28 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 06:28:50 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_vector.h"

double	v_dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec	v_cross(t_vec u, t_vec v)
{
	t_vec	vec;

	vec.x = (u.y * v.z - u.z * v.y);
	vec.y = (u.z * v.x - u.x * v.z);
	vec.z = (u.x * v.y - u.y * v.x);
	return (vec);
}

t_vec	projection(t_vec u, t_vec v)
{
	double	dot_uv;
	double	dot_vv;
	double	scalar;
	t_vec	proj;

	dot_uv = v_dot(u, v);
	dot_vv = v_dot(v, v);
	scalar = dot_uv / dot_vv;
	proj.x = scalar * v.x;
	proj.y = scalar * v.y;
	proj.z = scalar * v.z;
	return (proj);
}