/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:19:43 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/09 11:11:39 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - STDERR_FILENO
// - write
#include <unistd.h>

#include "ft_put/ft_put.h"

#include "read_input.h"
#include "error_messages.h"

int	main(int argc, char const *argv[])
{
	t_vect	map_lines;
	size_t	i;

	if (argc != 2)
		return (print_error_msg(g_err_inval_argc));
	map_lines = read_from_fname(argv[1]);
	if (map_lines.p == NULL)
		return (1);
	i = 0;
	while (i < map_lines.len)
		ft_putstr_fd(((char **)map_lines.p)[i++], STDOUT_FILENO);
	return (0);
}
