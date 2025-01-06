/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:21:13 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/06 19:26:46 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rt_utils.h"
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

void	draw_cylinder(t_figure *figure)
{
	(void) figure;
	return ;
}
