/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:07:57 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/06 04:19:42 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MLX_H
# define RT_MLX_H

# include "rt_struct.h"

# define RT_WHITE		0xFFFFFF

typedef int		(*t_handler)(int keycode, t_mlx *mlx);
typedef void	(*t_trans)(void *arg, int x, int y, int z);

/* rt_mlx_handler_key */
t_handler	get_handler(int keycode);

/* rt_mlx_handler_trans */
t_trans		get_transform_handler(t_mlx *mlx);

/* rt_mlx_handler_utils */
void		*get_handler_arg(t_mlx *mlx);

/* rt_mlx_hook */
int			rt_key_hook(int keycode, t_mlx *mlx);
int			rt_loop_hook(t_mlx *mlx);

/* rt_mlx_utils */
void		init_mlx_data(t_mlx *mlx, char *file_path);
void		destroy_mlx_data(t_mlx *mlx);
void		draw_pixel_to_img(t_data *data, int x, int y, unsigned int color);
void		print_status(t_mlx *mlx);

#endif