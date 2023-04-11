/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 20:19:43 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 23:36:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - free
#include <stdlib.h>

// - NULL
// - STDERR_FILENO
// - write
// (for debug)
// - getpid
// - system
#include <unistd.h>

// (for debug)
// - sprintf
#include <stdio.h>

#include "mlx.h"

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
	d->map = map_lines.p;
	d->row_count = map_lines.len;
	d->col_count = ft_strlen(d->map[0]);
	if (d->map[0][d->col_count - 1] == '\n')
		((char *)d->map[0])[--(d->col_count)] = '\0';
	if (!is_valid_map_style(d))
		return (print_error_msg(g_err_map_style));
	else if (!is_valid_map_data(d))
		return (print_error_msg(g_err_map_data));
	else if (!is_map_solvable(d))
		return (print_error_msg(g_err_map_not_solvable));
	d->cmds = vect_init(32, sizeof(t_mov_cmd));
	if (d->cmds.p != NULL)
		return (0);
	vect_dispose_each(&map_lines, free);
	return (print_error_msg(g_err_malloc_failed_mov_cmd));
}

int	main(int argc, char const *argv[])
{
	int			ret;
	t_so_long	d;

	d = (t_so_long){0};
	if (argc != 2)
		return (print_error_msg(g_err_inval_argc));
	ret = init_struct(argv[1], &d);
	if (ret == 0)
	{
		ret = init_window(argv[0], &d);
		if (ret == 0)
			mlx_loop(d.mlx);
	}
	dispose_so_long(&d);
	return (ret);
}

#if DEBUG

# define DEBUG_LEAKS_CMD_LEN (32)

__attribute__((destructor))
static void	destructor(void) {
	char	cmd[DEBUG_LEAKS_CMD_LEN];

	snprintf(cmd, DEBUG_LEAKS_CMD_LEN, "leaks %d", getpid());
	system(cmd);
}

#endif
