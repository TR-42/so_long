/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:19:43 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 07:26:01 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - STDERR_FILENO
// - write
#include <unistd.h>

#include "ft_put/ft_put.h"
#include "ft_string/ft_string.h"

#include "ft_endwith.h"
#include "read_input.h"
#include "error_messages.h"
#include "validate_input.h"

static int	init_struct(const char *fname, t_so_long *d)
{
	t_vect	map_lines;

	*d = (t_so_long){0};
	if (!ft_endwith_str(fname, ".ber"))
		return (print_error_msg(g_err_inval_extension));
	map_lines = read_from_fname(fname);
	if (map_lines.p == NULL)
		return (1);
	d->map = (const char **)map_lines.p;
	d->row_count = map_lines.len;
	d->col_count = ft_strlen(d->map[0]);
	if (d->map[0][d->col_count - 1] == '\n')
	{
		((char *)d->map[0])[d->col_count - 1] = '\0';
		d->col_count--;
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	size_t		i;
	t_so_long	d;

	if (argc != 2)
		return (print_error_msg(g_err_inval_argc));
	i = init_struct(argv[1], &d);
	if (i != 0)
		return (i);
	if (!is_valid_map_style(&d))
		ft_putendl_fd("Invalid (Style)", STDOUT_FILENO);
	else if (!is_valid_map_data(&d))
		ft_putendl_fd("Invalid (Data)", STDOUT_FILENO);
	else if (!is_map_solvable(&d))
		ft_putendl_fd("Invalid (cannot solve)", STDOUT_FILENO);
	else
		ft_putendl_fd("Valid", STDOUT_FILENO);
	ft_putstr_fd("~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~\n", STDOUT_FILENO);
	while (i < d.row_count)
		ft_putendl_fd((char *)(d.map[i++]), STDOUT_FILENO);
	dispose_so_long(&d);
	return (0);
}
