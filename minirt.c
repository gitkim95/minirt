/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilkim <hwilkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:20:44 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/03 17:49:40 by hwilkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rt_error.h"
#include "rt_mlx.h"

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	(void)argv;
	init_mlx_data(&mlx);
	mlx_loop(mlx.mlx);
	destroy_mlx_data(&mlx);
	return (0);
}
