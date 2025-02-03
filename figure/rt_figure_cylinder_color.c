/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_cylinder_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:38:03 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/04 00:17:50 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_vector.h"

#include "rt_figure.h"

static t_color	color_cylinder_cap(t_coord h_p, t_light *light, t_figure *fig);
static t_color	color_cylinder_body(t_coord h_p, t_light *light, t_figure *fig);
static t_vec	get_cylinder_normal(t_figure *cylinder, t_vec hit_point);

t_color	color_cylinder(t_coord hit_point, t_light *light, t_figure *figure)
{
	if (figure->hit_type == HIT_BODY)
		return (color_cylinder_body(hit_point, light, figure));
	else
		return (color_cylinder_cap(hit_point, light, figure));
}

static t_color	color_cylinder_body(t_coord h_p, t_light *light, t_figure *fig)
{
	t_color	color;
	t_vec	hit_normal;
	t_vec	d;
	double	t;

	hit_normal = get_cylinder_normal(fig, h_p);
	d = v_unit(v_sub(light->center, h_p));
	t = fmax(0, v_dot(hit_normal, d));
	color.x = light->color_bright.x * fig->color.x * t;
	color.y = light->color_bright.y * fig->color.y * t;
	color.z = light->color_bright.z * fig->color.z * t;
	return (color);
}

static t_color	color_cylinder_cap(t_coord h_p, t_light *light, t_figure *fig)
{
	t_color	color;
	t_vec	hit_normal;
	t_vec	d;
	double	t;

	hit_normal = get_cylinder_normal(fig, h_p);
	d = v_unit(v_sub(light->center, h_p));
	t = fmax(0, v_dot(hit_normal, d));
	color.x = light->color_bright.x * fig->color.x * t;
	color.y = light->color_bright.y * fig->color.y * t;
	color.z = light->color_bright.z * fig->color.z * t;
	return (color);
}

static t_vec	get_cylinder_normal(t_figure *cylinder, t_vec hit_point)
{
	t_vec	normal;
	t_vec	fig_dir;

	fig_dir = v_unit(cylinder->vector);
	if (cylinder->hit_type == HIT_BODY)
	{
		normal = v_sub(hit_point, cylinder->center);
		normal = v_sub(normal, v_mul(fig_dir, v_dot(normal, fig_dir)));
		normal = v_unit(normal);
	}
	else if (cylinder->hit_type == HIT_CAP)
	{
		normal = fig_dir;
		if (v_dot(v_sub(hit_point, cylinder->center), fig_dir) < 0)
			normal = v_mul(normal, -1);
	}
	return (normal);
}
