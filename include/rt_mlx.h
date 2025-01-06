/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:07:57 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 18:18:42 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MLX_H
# define RT_MLX_H

# include "rt_struct.h"

/* rt_mlx_hook */
int		rt_key_hook(int keycode, t_mlx *mlx);
int		rt_loop_hook(t_mlx *mlx);

/* rt_mlx_utils */
void	init_mlx_data(t_mlx *mlx);
void	destroy_mlx_data(t_mlx *mlx);
void	draw_pixel_to_img(t_data *data, int x, int y, unsigned int color);

#endif