/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:28 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/05 01:03:21 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "rt_vector.h"

double	v_length(t_vec vec)
{
	return (sqrt(v_length_squared(vec)));
}

double	v_length_squared(t_vec vec)
{
	return (v_dot(vec, vec));
}

t_vec	v_unit(t_vec vec)
{
	return (v_div(vec, v_length(vec)));
}

t_axis	get_default_axis(void)
{
	t_axis	axis;

	axis.x = (t_vec){1, 0, 0};
	axis.y = (t_vec){0, 1, 0};
	axis.z = (t_vec){0, 0, 1};
	return (axis);
}
