/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:43:56 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/04 21:45:08 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "rt_utils.h"
#include "rt_vector.h"
#include "libft.h"

#include "rt_figure.h"

static t_vec	get_surf_normal(t_coord coord, t_ray *ray, t_figure *fig);

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
	figure->get_surf_normal = get_surf_normal;
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
	if (c > 0)
		return ((b - sqrt(discrim)) / a);
	return ((b + sqrt(discrim)) / a);
}

static t_vec	get_surf_normal(t_coord coord, t_ray *ray, t_figure *fig)
{
	t_vec	n;

	n = v_unit(v_sub(coord, fig->center));
	if (v_dot(ray->direction, n) > 0)
		n = v_mul(n, -1);
	return (n);
}

void	resize_sphere(t_figure *figure, int x)
{
	if (x)
	{
		if (x < 0 && figure->diameter <= 1)
			return ;
		figure->diameter += x;
	}
}
