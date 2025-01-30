/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:52 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 04:22:27 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "rt_ray.h"
#include "rt_utils.h"
#include "rt_vector.h"

#include "rt_figure.h"

static int	check_shadow(t_coord hit_point, t_light *light, t_figure *figure, \
							t_fig_list *list);

t_figure	*make_figure(char **figure_attr)
{
	t_figure	*figure;

	if (!*figure_attr)
		return (NULL);
	else if (rt_strcmp(*figure_attr, (char *)RT_FIGURE + RT_CY) == 0)
		figure = parse_cylinder(figure_attr);
	else if (rt_strcmp(*figure_attr, (char *)RT_FIGURE + RT_PL) == 0)
		figure = parse_plane(figure_attr);
	else if (rt_strcmp(*figure_attr, (char *)RT_FIGURE + RT_SP) == 0)
		figure = parse_sphere(figure_attr);
	else
		figure = NULL;
	return (figure);
}

double	hit_figure(t_figure *figure, t_ray *ray)
{
	if (!figure)
		return (-1.0);
	else if (figure->identifier == RT_CY)
		draw_cylinder(figure);
	else if (figure->identifier == RT_PL)
		return (hit_plane(figure, ray));
	else if (figure->identifier == RT_SP)
		return (hit_sphere(figure, ray));
	return (-1.0);
}

t_color	color_figure(t_coord hit_point, t_light *light, t_figure *figure, \
						t_fig_list *list)
{
	if (check_shadow(hit_point, light, figure, list))
		return ((t_color){0, 0, 0});
	if (figure->identifier == RT_CY)
		draw_cylinder(figure);
	else if (figure->identifier == RT_PL)
		return (color_plane(cam, light, figure, hit));
	else if (figure->identifier == RT_SP)
		return (color_sphere(hit_point, light, figure));
	return (light->color);
}

static int	check_shadow(t_coord hit_point, t_light *light, t_figure *figure, \
							t_fig_list *list)
{
	t_figure	*node;
	t_ray		surf_ray;
	t_vec		light_dir;
	double		light_dist;
	double		hit_dist;

	light_dir = v_unit(v_sub(light->center, hit_point));
	light_dist = v_length(light_dir);
	surf_ray = (t_ray){hit_point, light_dir};
	node = list->head;
	while (node)
	{
		if (node != figure)
		{
			hit_dist = hit_figure(node, &surf_ray);
			if (hit_dist > 0 && hit_dist < light_dist)
				return (1);
		}
		node = node->next;
	}
	return (0);
}
