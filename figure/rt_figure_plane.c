/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:43:56 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/04 05:00:59 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "rt_vector.h"
#include "libft.h"

#include "rt_figure.h"

/**
 * Plane: pl	0.0,0.0,-10.0	0.0,1.0,0.0		0,0,225
 * identifier: pl
 * x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
 * 3d normalized normal vector.
 * 		In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
 * R,G,B colors in range [0-255]: 0,0,225
 */

t_figure	*parse_plane(char **figure_attr)
{
	t_figure	*figure;

	figure = (t_figure *)ft_calloc(1, sizeof(t_figure));
	figure->identifier = RT_PL;
	figure->center = parse_to_coord(figure_attr[1]);
	figure->vector = parse_to_coord(figure_attr[2]);
	figure->color = parse_to_color(figure_attr[3]);
	return (figure);
}

double	hit_plane(t_figure *figure, t_ray *ray)
{
	double	t;
	double	denom;
	t_vec	p0_to_origin;

	denom = v_dot(figure->vector, ray->direction);
	if (fabs(denom) < RT_EPSILON)
		return (-1.0);
	p0_to_origin = v_sub(figure->center, ray->origin);
	t = v_dot(p0_to_origin, figure->vector) / denom;
	if (denom < 0)
		figure->hit_side = HIT_OUTSIDE;
	else
		figure->hit_side = HIT_INSIDE;
	return (t);
}

t_color	color_plane(t_coord hit_point, t_light *light, t_figure *figure)
{
	t_color	color;
	t_vec	n;
	t_vec	d;
	double	t;

	n = v_unit(figure->vector);
	if (figure->hit_side == HIT_INSIDE)
		n = v_mul(n, -1);
	d = v_unit(v_sub(light->center, hit_point));
	t = fmax(0, v_dot(n, d));
	color.x = light->color_bright.x * figure->color.x * t;
	color.y = light->color_bright.y * figure->color.y * t;
	color.z = light->color_bright.z * figure->color.z * t;
	return (color);
}
