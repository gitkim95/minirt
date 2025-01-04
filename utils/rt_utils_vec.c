/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils_vec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:28 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 16:46:23 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_utils.h"

t_vec	rt_vec_add(t_vec u, t_vec v)
{
	t_vec	result;

	result.x = u.x + v.x;
	result.y = u.y + v.y;
	result.z = u.z + v.z;
	return (result);
}

t_vec	rt_vec_subtract(t_vec u, t_vec v)
{
	t_vec	result;

	result.x = u.x - v.x;
	result.y = u.y - v.y;
	result.z = u.z - v.z;
	return (result);
}

t_vec	rt_vec_multiply(t_vec vec, double t)
{
	t_vec	result;

	result.x = vec.x * t;
	result.y = vec.y * t;
	result.z = vec.z * t;
	return (result);
}

t_vec	rt_vec_divide(t_vec vec, double t)
{
	t_vec	result;

	result.x = vec.x / t;
	result.y = vec.y / t;
	result.z = vec.z / t;
	return (result);
}
