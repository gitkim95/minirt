/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_op_product.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:28 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 21:01:28 by hwilkim          ###   ########.fr       */
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
