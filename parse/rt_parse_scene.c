/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:09:42 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/01 00:20:47 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "rt_component.h"
#include "rt_error.h"
#include "rt_figure.h"
#include "rt_struct.h"
#include "rt_utils.h"
#include "rt_vector.h"
#include "libft.h"

#include "rt_parse.h"

static void	set_ambient_lightning(t_amb_light *amb, char **data);
static void	set_camera(t_camera *camera, char **data);
static void	set_light(t_light *light, char **data);

void	set_scene_struct(t_scene *scene, char **data, t_scene_type type)
{
	if (type == RT_A)
		set_ambient_lightning(&(scene->amb_light), data);
	else if (type == RT_C)
		set_camera(&(scene->cam), data);
	else
		set_light(&(scene->light), data);
}

static void	set_ambient_lightning(t_amb_light *amb, char **data)
{
	double	bright;
	t_color	color;

	bright = rt_atof(data[1]);
	color = parse_to_color(data[2]);
	amb->bright = bright;
	amb->color = color;
}

static void	set_camera(t_camera *camera, char **data)
{
	t_vec	tmp;

	camera->focal_length = 1.0;
	camera->vp_height = 2.0;
	camera->vp_width = camera->vp_height * ((double)RT_WIDTH / RT_HEIGHT);
	camera->center = parse_to_coord(data[1]);
	camera->vp_u = (t_vec){camera->vp_width, 0, 0};
	camera->vp_v = (t_vec){0, -camera->vp_height, 0};
	camera->pixel_delta_u = v_div(camera->vp_u, RT_WIDTH);
	camera->pixel_delta_v = v_div(camera->vp_v, RT_HEIGHT);
	tmp = v_sub(camera->center, (t_vec){0, 0, camera->focal_length});
	tmp = v_sub(tmp, v_div(camera->vp_u, 2));
	tmp = v_sub(tmp, v_div(camera->vp_v, 2));
	camera->vp_upper_left = tmp;
	tmp = v_add(camera->pixel_delta_u, camera->pixel_delta_v);
	tmp = v_mul(tmp, 0.5);
	tmp = v_add(camera->vp_upper_left, tmp);
	camera->pixel_zero_loc = tmp;
}

static void	set_light(t_light *light, char **data)
{
	double	bright;
	t_color	color;
	t_coord	center;

	center = parse_to_coord(data[1]);
	bright = rt_atof(data[2]);
	color = parse_to_color(data[3]);
	light->center = center;
	light->bright = bright;
	light->color = color;
}
