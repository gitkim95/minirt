/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:49:45 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/03 00:27:18 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_ERROR_H
# define RT_ERROR_H

# include "rt_struct.h"

# define RT_ERR_SIZE			10

# define RT_ERRNO_GET			0

# define RT_ERR_FILE_DATA		1
# define RT_ERR_NUM_OF_ARG		2
# define RT_ERR_FILE_EXTENSION	3
# define RT_ERR_MEM				4
# define RT_ERR_OPEN			5

/* rt_error.c */
void	exit_on_error(t_fig_list *list, int rt_errno);
void	free_gnl(int fd);
int		rt_errno(int errno);
char	*rt_err_str(int errno);

#endif