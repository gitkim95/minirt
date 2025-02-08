/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_component_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:30:53 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 19:17:22 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "rt_vector.h"

#include "rt_component.h"

double	hit_light(t_light *light, t_ray *ray)
{
	t_coord	oc;
	double	a;
	double	b;
	double	c;
	double	discrim;

	oc = v_sub(ray->origin, light->center);
	a = v_dot(ray->direction, ray->direction);
	b = 2.0 * v_dot(oc, ray->direction);
	c = v_dot(oc, oc) - 400;
	discrim = b * b - 4 * a * c;
	if (discrim < 0)
		return (-1.0);
	return (-b / (2 * a));
}

t_color	color_light(t_color color, t_coord hit_point, t_light *light)
{
	t_vec	vector;
	double	dist;
	double	t;

	vector = v_sub(light->center, hit_point);
	dist = v_length(vector);
	t = 1.0 / (1.0 + dist * dist);
	if (color.x < 0)
		color.x = 0;
	color.x = fmin(1.0, color.x + light->color.x * t);
	color.y = fmin(1.0, color.y + light->color.y * t);
	color.z = fmin(1.0, color.z + light->color.z * t);
	return (color);
}
