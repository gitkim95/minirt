/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:18:50 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 21:09:14 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_vector.h"

#include "rt_env.h"

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
