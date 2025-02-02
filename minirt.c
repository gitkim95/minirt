/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:20:44 by hwilkim           #+#    #+#             */
/*   Updated: 2025/01/31 23:10:09 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "rt_error.h"
#include "rt_mlx.h"

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (0); // error msg
	init_mlx_data(&mlx, argv[1]);
	mlx_loop(mlx.mlx);
	destroy_mlx_data(&mlx);
	return (0);
}
