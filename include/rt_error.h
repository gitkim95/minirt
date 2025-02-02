/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:49:45 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/02 20:09:11 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_H
# define RT_ERROR_H

# include "rt_struct.h"

# define RT_ERRNO_GET			0

# define RT_ERR_FILE_DATA		1
# define RT_ERR_NUM_OF_ARG		2
# define RT_ERR_FILE_EXTENSION	3
# define RT_ERR_MEM				4
# define RT_ERR_OPEN			5

/* rt_error.c */
void	exit_on_error(t_mlx *mlx, int rt_errno);
int		rt_errno(int errno);
char	*rt_err_str(int errno);

/* rt_print_error.c */
void	print_error(int	rt_errno);

#endif