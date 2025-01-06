/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vec_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:31:28 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 21:07:57 by hwilkim          ###   ########.fr       */
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
