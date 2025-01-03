/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:08:21 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 17:51:05 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include "mlx.h"

#include "rt_mlx.h"

int	rt_mlx_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		mlx_loop_end(mlx->mlx);
	return (0);
}
