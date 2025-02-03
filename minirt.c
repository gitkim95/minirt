/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:20:44 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 17:55:42 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mlx.h"
#include "rt_error.h"
#include "rt_mlx.h"

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		exit_on_error(NULL, RT_ERR_NUM_OF_ARG);
	init_mlx_data(&mlx, argv[1]);
	mlx_loop(mlx.mlx);
	destroy_mlx_data(&mlx);
	return (0);
}
