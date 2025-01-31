/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:43:56 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/31 08:48:09 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "rt_ray.h"
#include "rt_utils.h"
#include "rt_vector.h"
#include "libft.h"

#include "rt_figure.h"

/**
 * Sphere: sp	0.0,0.0,20.6	12.6	10,0,255
 * identifier: sp
 * x,y,z coordinates of the sphere center: 0.0,0.0,20.6
 * the sphere diameter: 12.6
 * R,G,B colors in range [0-255]: 10, 0, 255
 */

t_figure	*parse_sphere(char **figure_attr)
{
	t_figure	*figure;

	figure = (t_figure *)ft_calloc(1, sizeof(t_figure));
	figure->identifier = RT_SP;
	figure->center = parse_to_coord(figure_attr[1]);
	figure->diameter = rt_atof(figure_attr[2]);
	figure->color = parse_to_color(figure_attr[3]);
	return (figure);
}

double	hit_sphere(t_figure *figure, t_ray *ray)
{
	t_vec	offset;
	double	a;
	double	b;
	double	c;
	double	discrim;

	offset = v_sub(figure->center, ray->origin);
	a = v_length_squared(ray->direction);
	b = v_dot(ray->direction, offset);
	c = v_length_squared(offset) - pow(figure->diameter / 2, 2);
	discrim = (pow(b, 2) - a * c);
	if (discrim < 0)
		return (-1.0);
	return ((b - sqrt(discrim)) / a);
}

t_color	color_sphere(t_coord hit_point, t_light *light, t_figure *figure)
{
	t_color	color;
	t_vec	n;
	t_vec	d;
	double	t;

	n = v_unit(v_sub(hit_point, figure->center));
	d = v_unit(v_sub(light->center, hit_point));
	t = fmax(0, v_dot(n, d));
	color.x = light->color_bright.x * figure->color.x * t;
	color.y = light->color_bright.y * figure->color.y * t;
	color.z = light->color_bright.z * figure->color.z * t;
	return (color);
}
