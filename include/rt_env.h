/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:19:02 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 16:52:31 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ENV_H
# define RT_ENV_H

# include "rt_struct.h"

typedef struct s_camera
{
	double	focal_length;
	double	vp_height;
	double	vp_width;
	t_coord	center;
	t_vec	vp_u;
	t_vec	vp_v;
	t_vec	pixel_delta_u;
	t_vec	pixel_delta_v;
	t_vec	vp_upper_left;
	t_vec	pixel_zero_loc;
}	t_camera;

t_camera	make_camera(int width, int height, t_coord center);

#endif