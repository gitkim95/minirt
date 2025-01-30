/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:52 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 04:23:27 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "rt_ray.h"
#include "rt_utils.h"
#include "rt_vector.h"

#include "rt_figure.h"

static int		check_shadow(t_coord hit_point, t_scene *scene, t_figure *fig);
static t_color	to_phong(t_color fig_color, t_color diffuse, t_color ambient);

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

t_color	color_figure(t_coord hit_point, t_scene *scene, t_figure *figure)
{
	t_color	diffuse;
	t_color	ambient;

	ambient = v_mul(scene->amb_light.color, scene->amb_light.bright);
	if (check_shadow(hit_point, scene, figure))
		return ((t_color){0, 0, 0});
	if (figure->identifier == RT_CY)
		draw_cylinder(figure);
	else if (figure->identifier == RT_PL)
		return (color_plane(cam, light, figure, hit));
	else if (figure->identifier == RT_SP)
		diffuse = color_sphere(hit_point, &scene->light, figure);
	return (to_phong(figure->color, diffuse, ambient));
}

static int	check_shadow(t_coord hit_point, t_scene *scene, t_figure *figure)
{
	t_figure	*node;
	t_ray		surf_ray;
	t_vec		light_dir;
	double		light_dist;
	double		hit_dist;

	light_dir = v_unit(v_sub(scene->light.center, hit_point));
	light_dist = v_length(light_dir);
	surf_ray = (t_ray){hit_point, light_dir};
	node = scene->figures.head;
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

static t_color	to_phong(t_color fig_color, t_color diffuse, t_color ambient)
{
	t_color	color;

	color = v_add(diffuse, ambient);
	color.x = fmin(fig_color.x * color.x, 1.0);
	color.y = fmin(fig_color.y * color.y, 1.0);
	color.z = fmin(fig_color.z * color.z, 1.0);
	return (color);
}
