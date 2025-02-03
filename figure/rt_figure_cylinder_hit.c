/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_cylinder_hit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:32:37 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/03 23:56:49 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_utils.h"
#include "rt_vector.h"

#include "rt_figure.h"

static void	check_hit_cap(t_figure *fig, t_ray *ray, double *t, double height);
static void	check_hit_body(t_figure *fig, t_ray *ray, double *t, double *disc);

double	hit_cylinder(t_figure *figure, t_ray *ray)
{
	t_vec	offset;
	t_vec	fig_dir;
	t_vec	ray_dir;
	double	discrim[4];
	double	t;

	t = -1.0;
	fig_dir = v_unit(figure->vector);
	ray_dir = ray->direction;
	offset = v_sub(ray->origin, figure->center);
	discrim[0] = v_length_squared(ray_dir) - pow(v_dot(ray_dir, fig_dir), 2);
	discrim[1] = 2 * (v_dot(ray_dir, offset) \
			- v_dot(ray_dir, fig_dir) * v_dot(offset, fig_dir));
	discrim[2] = v_length_squared(offset) \
			- pow(v_dot(offset, fig_dir), 2) - pow(figure->diameter / 2.0, 2);
	discrim[3] = discrim[1] * discrim[1] - 4 * discrim[0] * discrim[2];
	if (discrim[3] >= 0)
		check_hit_body(figure, ray, &t, discrim);
	check_hit_cap(figure, ray, &t, -figure->height / 2);
	check_hit_cap(figure, ray, &t, figure->height / 2);
	return (t);
}

static void	check_hit_cap(t_figure *fig, t_ray *ray, double *t, double height)
{
	t_vec	hit_point;
	t_vec	fig_dir;
	t_vec	ray_dir;
	double	cap;

	fig_dir = v_unit(fig->vector);
	ray_dir = ray->direction;
	if (fabs(v_dot(ray_dir, fig_dir)) < RT_EPSILON)
		return ;
	cap = v_dot(v_sub(v_add(fig->center, v_mul(fig_dir, height)), ray->origin) \
					, fig_dir) / v_dot(ray_dir, fig_dir);
	if (cap < RT_EPSILON)
		return ;
	hit_point = v_add(ray->origin, v_mul(ray_dir, cap));
	if (v_length_squared(v_sub(hit_point, v_add(fig->center, \
		v_mul(fig_dir, height)))) <= pow(fig->diameter / 2.0, 2))
	{
		if (*t < 0 || cap < *t)
		{
			*t = cap;
			fig->hit_type = HIT_CAP;
		}
	}
}

static void	check_hit_body(t_figure *fig, t_ray *ray, double *t, double *disc)
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
	{
		*t = body[0];
		fig->hit_type = HIT_BODY;
	}
	else
	{
		hit_point = v_add(ray->origin, v_mul(ray->direction, body[1]));
		hit_height = v_dot(v_sub(hit_point, fig->center), v_unit(fig->vector));
		if (hit_height >= -fig->height / 2.0 && hit_height <= fig->height / 2.0)
		{
			*t = body[1];
			fig->hit_type = HIT_BODY;
		}
	}
}
