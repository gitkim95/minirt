/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_op_arithmetic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:28 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 21:01:21 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"

t_vec	v_add(t_vec u, t_vec v)
{
	t_vec	result;

	result.x = u.x + v.x;
	result.y = u.y + v.y;
	result.z = u.z + v.z;
	return (result);
}

t_vec	v_sub(t_vec u, t_vec v)
{
	t_vec	result;

	result.x = u.x - v.x;
	result.y = u.y - v.y;
	result.z = u.z - v.z;
	return (result);
}

t_vec	v_mul(t_vec vec, double t)
{
	t_vec	result;

	result.x = vec.x * t;
	result.y = vec.y * t;
	result.z = vec.z * t;
	return (result);
}

t_vec	v_div(t_vec vec, double t)
{
	t_vec	result;

	result.x = vec.x / t;
	result.y = vec.y / t;
	result.z = vec.z / t;
	return (result);
}
