/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_component.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:18:50 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/26 16:51:44 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_vector.h"

#include "rt_component.h"

/**
 * Camera:	C    -50.0,0,20    0,0,1    70
 * identifier: C
 * x,y,z coordinates of the view point: -50.0,0,20
 * 3d normalized orientation vector. 
 * 		In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
 * FOV : Horizontal field of view in degrees in range [0,180]: 70
 */

t_camera	make_camera(int width, int height, t_coord center)
{
	t_camera	camera;
	t_vec		tmp;

	camera.focal_length = 1.0;
	camera.vp_height = 2.0;
	camera.vp_width = camera.vp_height * ((double)width / height);
	camera.center = center;
	camera.vp_u = (t_vec){camera.vp_width, 0, 0};
	camera.vp_v = (t_vec){0, -camera.vp_height, 0};
	camera.pixel_delta_u = v_div(camera.vp_u, width);
	camera.pixel_delta_v = v_div(camera.vp_v, height);
	tmp = v_sub(camera.center, (t_vec){0, 0, camera.focal_length});
	tmp = v_sub(tmp, v_div(camera.vp_u, 2));
	tmp = v_sub(tmp, v_div(camera.vp_v, 2));
	camera.vp_upper_left = tmp;
	tmp = v_add(camera.pixel_delta_u, camera.pixel_delta_v);
	tmp = v_mul(tmp, 0.5);
	tmp = v_add(camera.vp_upper_left, tmp);
	camera.pixel_zero_loc = tmp;
	return (camera);
}

/**
 * Light:	L    -40.0,50.0,0.0    0.6    10,0,255
 * identifier: L
 * x,y,z coordinates of the light point: -40.0,50.0,0.0
 * the light brightness ratio in range [0.0,1.0]: 0.6
 * (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255
 */

t_light	make_light(t_coord center, double bright)
{
	t_light	light;

	light.center = center;
	light.bright = bright;
	light.color = (t_color){1, 1, 1};
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
	return (amb_light);
}
