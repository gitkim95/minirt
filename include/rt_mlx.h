/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:07:57 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 17:52:46 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MLX_H
# define RT_MLX_H

# include "rt_struct.h"

/* rt_mlx_hook */
int		rt_mlx_key_hook(int keycode, t_mlx *mlx);

/* rt_mlx_utils */
void	init_mlx_data(t_mlx *mlx);
void	destroy_mlx_data(t_mlx *mlx);

#endif