/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitkim <gitkim@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:11:19 by gitkim            #+#    #+#             */
/*   Updated: 2025/02/02 17:50:51 by gitkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

#include "rt_error.h"

void	print_error(int rt_errno)
{
	ft_putendl_fd(rt_err_str(rt_errno), STDERR_FILENO);
}
