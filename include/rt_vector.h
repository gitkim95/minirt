/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:35:02 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/04 21:09:03 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_VECTOR_H
# define RT_VECTOR_H

# include "rt_struct.h"

/* rt_vec_op_arithmetic */
t_vec	v_add(t_vec u, t_vec v);
t_vec	v_sub(t_vec u, t_vec v);
t_vec	v_mul(t_vec vec, double t);
t_vec	v_div(t_vec vec, double t);

/* rt_vec_op_product */
double	v_dot(t_vec u, t_vec v);
t_vec	v_cross(t_vec u, t_vec v);

/* rt_vec_utils */
double	v_length(t_vec vec);
double	v_length_squared(t_vec vec);
t_vec	v_unit(t_vec vec);

#endif