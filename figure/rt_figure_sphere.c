/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:43:56 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/02 19:51:36 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "minirt.h"

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
	return (NULL);
}
