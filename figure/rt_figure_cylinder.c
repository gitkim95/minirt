/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:21:13 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/03 03:45:47 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "rt_utils.h"
#include "rt_vector.h"
#include "libft.h"

#include "rt_figure.h"

/**
 * Cylinder: cy	50.0,0.0,20.6	0.0,0.0,1.0		14.2	21.42	10,0,255
 * identifier: cy
 * x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
 * 3d normalized vector of axis of cylinder. 
 * 		In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
 * the cylinder diameter: 14.2
 * the cylinder height: 21.42
 * R,G,B colors in range [0,255]: 10, 0, 255
 */

t_figure	*parse_cylinder(char **figure_attr)
{
	t_figure	*figure;

	figure = (t_figure *)ft_calloc(1, sizeof(t_figure));
	figure->identifier = RT_CY;
	figure->center = parse_to_coord(figure_attr[1]);
	figure->vector = parse_to_coord(figure_attr[2]);
	figure->diameter = rt_atof(figure_attr[3]);
	figure->height = rt_atof(figure_attr[4]);
	figure->color = parse_to_color(figure_attr[5]);
	return (figure);
}

double	hit_cylinder(t_figure *figure, t_ray *ray)
{
	t_vec	offset;
	t_vec	fig_dir;
	t_vec	ray_dir;
	double	discrim[4];
	double	t;

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
	else
		t = -1.0;
	check_hit_cap(figure, ray, &t, -figure->height);
	check_hit_cap(figure, ray, &t, figure->height);
	return (t);
}

t_color	color_cylinder(t_coord hit_point, t_light *light, t_figure *figure)
{
	t_color	color;
	t_vec	n;
	t_vec	d;
	double	t;
	t_vec	proj;

	proj = v_mul(figure->vector, \
		v_dot(v_sub(hit_point, figure->center), figure->vector));
	n = v_unit(v_sub(v_sub(hit_point, figure->center), proj));
	d = v_unit(v_sub(light->center, hit_point));
	t = fmax(0, v_dot(n, d));
	color.x = light->color_bright.x * figure->color.x * t;
	color.y = light->color_bright.y * figure->color.y * t;
	color.z = light->color_bright.z * figure->color.z * t;
	return (color);
}
