/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:44:59 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 21:09:26 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_vector.h"

#include "rt_ray.h"

t_coord	ray_at(t_ray *ray, double t)
{
	return (v_add(ray->origin, v_mul(ray->direction, t)));
}
