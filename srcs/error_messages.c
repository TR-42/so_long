/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:00:58 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/09 11:13:35 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - errno
#include <errno.h>

// - strerror
#include <string.h>

// - STDERR_FILENO
// - write
#include <unistd.h>

#include "ft_put/ft_put.h"
#include "error_messages.h"

int	print_error_msg(const char *str)
{
	write(STDERR_FILENO, g_err, sizeof(g_err));
	ft_putendl_fd((char *)str, STDERR_FILENO);
	return (1);
}

int	print_error_errno(int num)
{
	return (print_error_msg(strerror(num)));
}

int	print_error(void)
{
	return (print_error_errno(errno));
}
