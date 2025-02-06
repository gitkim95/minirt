/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:21:13 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 20:28:39 by hwilkim          ###   ########.fr       */
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
	figure->vector = v_unit(parse_to_coord(figure_attr[2]));
	figure->rotate.vector = figure->vector;
	figure->rotate.axis = get_default_axis();
	figure->diameter = rt_atof(figure_attr[3]);
	figure->height = rt_atof(figure_attr[4]);
	figure->color = parse_to_color(figure_attr[5]);
	figure->calculate_hit = hit_cylinder;
	figure->get_surf_normal = get_surf_normal;
	return (figure);
}

void	resize_cylinder(t_figure *figure, int x, int y)
{
	if (x)
	{
		if (x < 0 && figure->diameter <= 1)
			return ;
		figure->diameter += x;
	}
	else if (y)
	{
		if (y < 0 && figure->height <= 1)
			return ;
		figure->height += y;
	}
	else
		return ;
}

static t_vec	get_surf_normal(t_coord coord, t_ray *ray, t_figure *fig)
{
	t_vec	n;
	t_vec	cp;
	double	m;

	cp = v_sub(coord, fig->center);
	m = v_dot(cp, fig->vector);
	if (fabs(m + fig->height / 2) < RT_TOLERANCE_EPSILON)
		n = v_mul(fig->vector, -1);
	else if (fabs(m - fig->height / 2) < RT_TOLERANCE_EPSILON)
		n = fig->vector;
	else
		n = v_unit(v_sub(cp, v_mul(fig->vector, m)));
	if (v_dot(ray->direction, n) > 0)
		n = v_mul(n, -1);
	return (n);
}
