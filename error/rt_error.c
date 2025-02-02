/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:53:25 by hwilkim           #+#    #+#             */
/*   Updated: 2025/02/03 00:32:04 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt_utils.h"
#include "libft.h"

#include "rt_error.h"

static void	print_error(int rt_errno);

int	rt_errno(int errno)
{
	static int	rt_errno;

	if (errno)
		rt_errno = errno;
	return (rt_errno);
}

char	*rt_err_str(int errno)
{
	static char	*rt_err_str[RT_ERR_SIZE];

	if (!rt_err_str[0])
	{
		rt_err_str[0] = "";
		rt_err_str[RT_ERR_FILE_DATA] = "Invalid file data";
		rt_err_str[RT_ERR_NUM_OF_ARG] = "Invalid number of arguments";
		rt_err_str[RT_ERR_FILE_EXTENSION] = "Invalid file extension";
		rt_err_str[RT_ERR_MEM] = "Cannot allocate memory";
		rt_err_str[RT_ERR_OPEN] = "Failed to open the file";
	}
	return (rt_err_str[errno]);
}

void	free_gnl(int fd)
{
	char	*temp;

	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		free(temp);
	}
	close(fd);	
}

void	exit_on_error(t_fig_list *list, int rt_errno)
{
	if (list && list->size)
		rt_free_figure(list);
	if (rt_errno > 0)
		print_error(rt_errno);
	exit(rt_errno);
}

static void	print_error(int rt_errno)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(rt_err_str(rt_errno), STDERR_FILENO);
}
