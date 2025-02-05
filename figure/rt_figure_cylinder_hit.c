/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_cylinder_hit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:32:37 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/06 04:13:18 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_utils.h"
#include "rt_vector.h"

#include "rt_figure.h"

static double	hit_body(t_figure *figure, t_ray *ray);
static double	hit_cap(t_vec cap_c, t_vec cap_n, double radius, t_ray *ray);

double	hit_cylinder(t_figure *fig, t_ray *ray)
{
	double	body_t;
	double	cap_t[3];
	t_vec	cap_center[2];

	body_t = hit_cylinder_body(fig, ray);
	cap_center[0] = v_add(fig->center, v_mul(fig->vector, fig->height / 2));
	cap_t[0] = hit_cylinder_cap(cap_center[0], \
								fig->vector, fig->diameter / 2, ray);
	cap_center[1] = v_sub(fig->center, v_mul(fig->vector, fig->height / 2));
	cap_t[1] = hit_cylinder_cap(cap_center[1], \
								v_mul(fig->vector, -1), fig->diameter / 2, ray);
	if (cap_t[0] < 0 && cap_t[1] < 0)
		cap_t[2] = -1.0;
	else if (cap_t[0] > 0 && cap_t[1] == -1.0)
		cap_t[2] = cap_t[0];
	else if (cap_t[1] > 0 && cap_t[0] == -1.0)
		cap_t[2] = cap_t[1];
	else
		cap_t[2] = fmin(cap_t[0], cap_t[1]);
	if (body_t > 0 && cap_t[2] > 0)
		return (fmin(body_t, cap_t[2]));
	if (body_t > 0 && cap_t[2] == -1.0)
		return (body_t);
	return (cap_t[2]);
}

static double	hit_cap(t_vec cap_c, t_vec cap_n, double radius, t_ray *ray)
{
	double	cap_t;
	t_vec	hit_point;

	cap_t = v_dot(v_sub(cap_c, ray->origin), cap_n) \
												/ v_dot(ray->direction, cap_n);
	hit_point = v_add(ray->origin, v_mul(ray->direction, cap_t));
	if (v_length(v_sub(hit_point, cap_c)) <= radius && cap_t > RT_EPSILON)
		return (cap_t);
	return (-1.0);
}

static double	hit_body(t_figure *fig, t_ray *ray)
{
	t_vec	oc;
	double	discrim[4];
	double	t[2];
	double	m[2];

	oc = v_sub(ray->origin, fig->center);
	discrim[0] = v_dot(ray->direction, ray->direction) \
								- pow(v_dot(ray->direction, fig->vector), 2);
	discrim[1] = 2 * (v_dot(ray->direction, oc) \
			- (v_dot(ray->direction, fig->vector) * v_dot(oc, fig->vector)));
	discrim[2] = v_dot(oc, oc) - pow(v_dot(oc, fig->vector), 2) \
								- pow(fig->diameter / 2, 2);
	discrim[3] = pow(discrim[1], 2) - 4 * discrim[0] * discrim[2];
	if (discrim[3] < 0)
		return (-1.0);
	t[0] = (-discrim[1] - sqrt(discrim[3])) / (2 * discrim[0]);
	t[1] = (-discrim[1] + sqrt(discrim[3])) / (2 * discrim[0]);
	m[0] = v_dot(ray->direction, fig->vector) * t[0] + v_dot(oc, fig->vector);
	m[1] = v_dot(ray->direction, fig->vector) * t[1] + v_dot(oc, fig->vector);
	if (fabs(m[0]) <= fig->height / 2 && t[0] > RT_EPSILON)
		return (t[0]);
	else if (fabs(m[1]) <= fig->height / 2 && t[1] > RT_EPSILON)
		return (t[1]);
	return (-1.0);
}
