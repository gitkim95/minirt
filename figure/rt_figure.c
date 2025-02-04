/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:28:52 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/04 21:38:05 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>
#include "rt_ray.h"
#include "rt_utils.h"
#include "rt_vector.h"

#include "rt_figure.h"

static int		check_shadow(t_coord coord, t_scene *scene);
static t_color	to_phong(t_color fig_color, t_color diffuse, t_color ambient);

t_figure	*make_figure(char **figure_attr)
{
	char		*identifier;
	t_figure	*figure;

	identifier = *figure_attr;
	if (!identifier)
		return (NULL);
	else if (rt_str_equals(identifier, RT_FIGURE + RT_CY))
		figure = parse_cylinder(figure_attr);
	else if (rt_str_equals(identifier, RT_FIGURE + RT_PL))
		figure = parse_plane(figure_attr);
	else if (rt_str_equals(identifier, RT_FIGURE + RT_SP))
		figure = parse_sphere(figure_attr);
	else
		figure = NULL;
	return (figure);
}

t_color	color_figure(t_coord coord, t_ray *ray, t_scene *scene, t_figure *fig)
{
	t_color	diffuse;
	t_vec	n;
	t_vec	d;
	double	t;

	if (check_shadow(coord, scene))
		diffuse = (t_color){0, 0, 0};
	else
	{
		n = fig->get_surf_normal(coord, ray, fig);
		d = v_unit(v_sub(scene->light.center, coord));
		t = fmax(0, v_dot(n, d));
		diffuse.x = scene->light.color_bright.x * fig->color.x * t;
		diffuse.y = scene->light.color_bright.y * fig->color.y * t;
		diffuse.z = scene->light.color_bright.z * fig->color.z * t;
	}
	return (to_phong(fig->color, diffuse, scene->amb_light.color_bright));
}

static int	check_shadow(t_coord coord, t_scene *scene)
{
	t_figure	*figure;
	t_ray		surf_ray;
	t_vec		light_dir;
	double		light_dist;
	double		hit_dist;

	light_dir = v_sub(scene->light.center, coord);
	light_dist = v_length(light_dir);
	surf_ray = (t_ray){coord, v_unit(light_dir)};
	figure = scene->figures.head;
	while (figure)
	{
		hit_dist = figure->calculate_hit(figure, &surf_ray);
		if (hit_dist > 0 && hit_dist < light_dist)
			return (1);
		figure = figure->next;
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
