/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:41:07 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 06:39:37 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string/ft_string.h"

#include "so_long.h"

#include "validate_input.h"

static bool	is_valid_char(char target)
{
	return (
		target == CHR_EMPTY_SPC
		|| target == CHR_WALL
		|| target == CHR_COLLECTIVE
		|| target == CHR_MAP_EXIT
		|| target == CHR_START_POS
	);
}

// checks...
// - col count
// - invalid chars
bool	is_valid_map_style(const t_so_long *d)
{
	size_t	i;
	size_t	tmp;

	if (d->map == NULL || d->row_count < 3 || d->col_count < 3)
		return (false);
	i = 0;
	while (++i < d->row_count)
	{
		tmp = ft_strlen(d->map[i]);
		if (d->map[i][tmp - 1] == '\n')
		{
			if (tmp != (d->col_count + 1))
				return (false);
			((char *)d->map[i])[--tmp] = '\0';
		}
		else if (tmp != d->col_count)
			return (false);
		while (0 < --tmp)
			if (!is_valid_char(d->map[i][tmp]))
				return (false);
	}
	return (true);
}

// checks...
// - is it closed/surrounded with wall?
// - start/exit/collectable count
bool	is_valid_map_data(const t_so_long *d)
{
	size_t	r;
	size_t	c;
	size_t	collective;
	size_t	map_exit;
	size_t	start_pos;

	r = 0;
	collective = 0;
	map_exit = 0;
	start_pos = 0;
	while (r++ < d->row_count)
	{
		c = 0;
		while (c++ < d->col_count)
		{
			collective += (d->map[r - 1][c - 1] == CHR_COLLECTIVE);
			map_exit += (d->map[r - 1][c - 1] == CHR_MAP_EXIT);
			start_pos += (d->map[r - 1][c - 1] == CHR_START_POS);
			if (1 < map_exit || 1 < start_pos || ((r == 1 || c == 1
						|| r == d->row_count || c == d->col_count)
					&& d->map[r - 1][c - 1] != CHR_WALL))
				return (false);
		}
	}
	return (0 < collective);
}
