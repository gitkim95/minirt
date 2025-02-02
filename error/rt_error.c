/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:53:25 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 17:57:36 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_utils.h"
#include "libft.h"

#include "rt_error.h"

int	rt_errno(int errno)
{
	static int	rt_errno;

	if (errno)
		rt_errno = errno;
	return (rt_errno);
}

char	*rt_err_str(int errno)
{
	static char	*rt_err_str[5];

	if (!rt_err_str[0])
	{
		rt_err_str[0] = "";
		rt_err_str[RT_ERR_FILE_DATA] = "Invalid file data";
		rt_err_str[RT_ERR_NUM_OF_ARG] = "Invalid number of arguments";
		rt_err_str[RT_ERR_FILE_EXTENSION] = "Invalid file extension";
		rt_err_str[RT_ERR_MEM] = "Cannot allocate memory";

	}
	return (rt_err_str[errno]);
}

void	free_data(t_mlx *mlx)
{
	if (mlx->scene.figures.size)
		rt_free_figure(&(mlx->scene.figures));
	if (mlx->mlx)
		free(mlx->mlx);
}

void	exit_on_error(t_mlx *mlx, int rt_errno)
{
	if (mlx)
		free_data(mlx);
	if (rt_errno > 0)
		print_error(rt_errno);
	exit(rt_errno);
}
