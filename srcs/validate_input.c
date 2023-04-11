/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:41:07 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/12 08:53:00 by kfujita          ###   ########.fr       */
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

static bool	_is_valid_map_data(t_so_long *d, const t_uxy *cr,
	size_t *map_exit, size_t *start_pos)
{
	d->collectives += (*c_at(d, cr) == CHR_COLLECTIVE);
	if (*c_at(d, cr) == CHR_MAP_EXIT)
	{
		*map_exit += 1;
		d->exit = *cr;
	}
	if (*c_at(d, cr) == CHR_START_POS)
	{
		*start_pos += 1;
		d->player = *cr;
	}
	if (1 != *map_exit || 1 != *start_pos || ((cr->y == 0 || cr->x == 0
				|| cr->y == (d->row_count - 1) || cr->x == (d->col_count - 1))
			&& *c_at(d, cr) != CHR_WALL))
		return (false);
	return (true);
}

// checks...
// - is it closed/surrounded with wall?
// - start/exit/collectable count
bool	is_valid_map_data(t_so_long *d)
{
	t_uxy	cr;
	size_t	map_exit;
	size_t	start_pos;

	cr.y = 0;
	map_exit = 0;
	start_pos = 0;
	while (cr.y < d->row_count)
	{
		cr.x = 0;
		while (cr.x < d->col_count)
		{
			if (!_is_valid_map_data(d, &cr, &map_exit, &start_pos))
				return (false);
			cr.x++;
		}
		cr.y++;
	}
	return (0 < d->collectives);
}
