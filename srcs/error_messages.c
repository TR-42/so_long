/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:00:58 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/09 11:35:51 by kfujita          ###   ########.fr       */
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

int	print_error_msg2(const char *str1, const char *str2)
{
	write(STDERR_FILENO, g_err, sizeof(g_err) - 1);
	ft_putstr_fd((char *)str1, STDERR_FILENO);
	if (str1 != NULL && str2 != NULL)
		write(STDERR_FILENO, ": ", 2);
	ft_putendl_fd((char *)str2, STDERR_FILENO);
	return (1);
}

int	print_error_msg(const char *str)
{
	return (print_error_msg2(NULL, str));
}

int	print_error_errno(int num)
{
	return (print_error_msg(strerror(num)));
}

int	print_error(void)
{
	return (print_error_errno(errno));
}
