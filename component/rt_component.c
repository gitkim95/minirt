/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_component.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:18:50 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 03:40:22 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_vector.h"

#include "rt_component.h"

static t_vec	calculate_vp_upper_left(t_camera *camera);
static t_vec	calculate_pixel_zero_loc(t_camera *camera);

/**
 * Camera:	C    -50.0,0,20    0,0,1    70
 * identifier: C
 * x,y,z coordinates of the view point: -50.0,0,20
 * 3d normalized orientation vector. 
 * 		In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
 * FOV : Horizontal field of view in degrees in range [0,180]: 70
 */

t_camera	make_camera(t_coord center, t_rotate rotate, int fov)
{
	t_camera	camera;
	double		fov_radians;

	camera.fov = fov;
	fov_radians = camera.fov * RT_RADIAN;
	camera.rotate = rotate;
	camera.vp_width = 2 * tan(fov_radians / 2);
	camera.vp_height = camera.vp_width / ((double)RT_WIDTH / RT_HEIGHT);
	camera.vp_w = v_mul(camera.rotate.vector, -1);
	camera.vp_u = v_cross(camera.rotate.axis.y, camera.vp_w);
	if (v_length(camera.vp_u) < RT_EPSILON)
		camera.vp_u = (t_vec){1, 0, 0};
	camera.vp_u = v_unit(camera.vp_u);
	camera.vp_v = v_unit(v_cross(camera.vp_w, camera.vp_u));
	camera.vp_u = v_mul(camera.vp_u, camera.vp_width);
	camera.vp_v = v_mul(camera.vp_v, -camera.vp_height);
	camera.pixel_delta_u = v_div(camera.vp_u, RT_WIDTH);
	camera.pixel_delta_v = v_div(camera.vp_v, RT_HEIGHT);
	camera.center = center;
	camera.focal_length = camera.vp_width / (2 * tan(fov_radians / 2));
	camera.vp_upper_left = calculate_vp_upper_left(&camera);
	camera.pixel_zero_loc = calculate_pixel_zero_loc(&camera);
	return (camera);
}

/**
 * Light:	L    -40.0,50.0,0.0    0.6    10,0,255
 * identifier: L
 * x,y,z coordinates of the light point: -40.0,50.0,0.0
 * the light brightness ratio in range [0.0,1.0]: 0.6
 * (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
 */

t_light	make_light(t_coord center, double bright, t_color color)
{
	t_light	light;

	light.center = center;
	light.bright = bright;
	light.color = color;
	light.color_bright = v_mul(light.color, light.bright);
	return (light);
}

/**
 * Ambient lightning:	A    0.2    255,255,255
 * identifier: A
 * ambient lighting ratio in range [0.0,1.0]: 0.2
 * R,G,B colors in range [0-255]: 255, 255, 255
 */

t_amb_light	make_amb_light(double bright, t_color color)
{
	t_light	amb_light;

	amb_light.bright = bright;
	amb_light.color = color;
	amb_light.color_bright = v_mul(amb_light.color, amb_light.bright);
	return (amb_light);
}

static t_vec	calculate_vp_upper_left(t_camera *camera)
{
	t_vec	vp_upper_left;

	vp_upper_left = v_mul(camera->vp_w, camera->focal_length);
	vp_upper_left = v_sub(camera->center, vp_upper_left);
	vp_upper_left = v_sub(vp_upper_left, v_div(camera->vp_u, 2));
	vp_upper_left = v_sub(vp_upper_left, v_div(camera->vp_v, 2));
	return (vp_upper_left);
}

static t_vec	calculate_pixel_zero_loc(t_camera *camera)
{
	t_vec	pixel_zero_loc;

	pixel_zero_loc = v_add(camera->pixel_delta_u, camera->pixel_delta_v);
	pixel_zero_loc = v_mul(pixel_zero_loc, 0.5);
	pixel_zero_loc = v_add(camera->vp_upper_left, pixel_zero_loc);
	return (pixel_zero_loc);
}
