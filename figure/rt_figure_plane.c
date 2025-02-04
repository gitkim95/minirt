/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:43:56 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/04 21:20:47 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "rt_vector.h"
#include "libft.h"

#include "rt_figure.h"

static t_vec	get_surf_normal(t_coord coord, t_ray *ray, t_figure *fig);

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
	figure->get_surf_normal = get_surf_normal;
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
	return (t);
}

static t_vec	get_surf_normal(t_coord coord, t_ray *ray, t_figure *fig)
{
	t_vec	n;

	(void) coord;
	n = v_unit(fig->vector);
	if (v_dot(ray->direction, n) > 0)
		n = v_mul(n, -1);
	return (n);
}
