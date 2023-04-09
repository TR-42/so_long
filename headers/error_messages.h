/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:02:55 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/09 11:09:16 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

static const char	g_err[]
	= "Error\n";

static const char	g_err_inval[]
	= "Invalid argc (usage: `so_long MAP_FILE_NAME`)\n";

int	print_error_msg(const char *str);
int	print_error_errno(int num);
int	print_error(void);

#endif
