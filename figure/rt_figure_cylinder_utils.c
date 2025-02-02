/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_cylinder_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 02:50:57 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/03 03:29:33 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_utils.h"
#include "rt_vector.h"

#include "rt_figure.h"

void	check_hit_cap(t_figure *fig, t_ray *ray, double *t, double height)
{
	t_vec	hit_point;
	t_vec	fig_dir;
	t_vec	ray_dir;
	double	cap;

	fig_dir = v_unit(fig->vector);
	ray_dir = ray->direction;
	cap = v_dot(v_sub(v_add(fig->center, v_mul(fig_dir, -height / 2.0)), \
							ray->origin), fig_dir) / v_dot(ray_dir, fig_dir);
	hit_point = v_add(ray->origin, v_mul(ray_dir, cap));
	if (v_length_squared(v_sub(hit_point, v_add(fig->center, v_mul(fig_dir, \
				-height / 2.0)))) <= pow(fig->diameter / 2.0, 2) && cap > 0)
	{
		if (*t < 0 || cap < *t)
			*t = cap;
	}
}

void	check_hit_body(t_figure *fig, t_ray *ray, double *t, double *disc)
{
	t_vec	hit_point;
	double	hit_height;
	double	body[2];

	body[0] = (-disc[1] - sqrt(disc[3])) / (2 * disc[0]);
	body[1] = (-disc[1] + sqrt(disc[3])) / (2 * disc[0]);
	if (body[0] > body[1])
		rt_swap(&body[0], &body[1]);
	hit_point = v_add(ray->origin, v_mul(ray->direction, body[0]));
	hit_height = v_dot(v_sub(hit_point, fig->center), v_unit(fig->vector));
	if (hit_height >= -fig->height / 2.0 && hit_height <= fig->height / 2.0)
		*t = body[0];
	else
	{
		hit_point = v_add(ray->origin, v_mul(ray->direction, body[1]));
		hit_height = v_dot(v_sub(hit_point, fig->center), v_unit(fig->vector));
		if (hit_height >= -fig->height / 2.0 && hit_height <= fig->height / 2.0)
			*t = body[1];
	}
}
