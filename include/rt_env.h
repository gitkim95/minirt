/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:19:02 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/06 18:27:00 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ENV_H
# define RT_ENV_H

# include "rt_struct.h"

t_camera	make_camera(int width, int height, t_coord center);
t_light		make_light(t_coord center, double bright);
t_amb_light	make_amb_light(double bright, t_color color);

#endif