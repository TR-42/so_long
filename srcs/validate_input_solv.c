/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_solv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:38:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 23:29:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_string/ft_string.h"

#include "validate_input.h"

static t_so_long	dup_so_long(const t_so_long *d)
{
	t_so_long	v;

	v = (t_so_long){0};
	v.map = malloc(sizeof(char *) * d->row_count);
	if (v.map == NULL)
		return (v);
	while (v.row_count < d->row_count)
	{
		v.map[v.row_count] = ft_strdup(d->map[v.row_count]);
		if (v.map[v.row_count] == NULL)
			break ;
		v.row_count++;
	}
	v.col_count = d->col_count;
	v.start_row = d->start_row;
	v.start_col = d->start_col;
	if (v.row_count != d->row_count)
		dispose_so_long(&v);
	return (v);
}

static bool	go_to_goal(const t_so_long *d, size_t row, size_t col)
{
	char	c;

	c = d->map[row][col];
	if (c == CHR_MAP_EXIT)
		return (true);
	else if (c == CHR_WALL || c == CHR_VISITED)
		return (false);
	((char *)d->map[row])[col] = CHR_VISITED;
	return (
		go_to_goal(d, row + 1, col)
		|| go_to_goal(d, row, col + 1)
		|| go_to_goal(d, row, col - 1)
		|| go_to_goal(d, row - 1, col)
	);
}

// checks...
// - is it solvable?
bool	is_map_solvable(t_so_long *d)
{
	t_so_long	v;
	bool		is_solvable;
	size_t		row;
	size_t		col;

	row = 0;
	while (++row < d->row_count && d->start_row == 0)
	{
		col = 0;
		while (++col < d->col_count && d->start_col == 0)
		{
			if (d->map[row][col] == CHR_START_POS)
			{
				d->start_row = row;
				d->start_col = col;
			}
		}
	}
	v = dup_so_long(d);
	if (v.map == NULL)
		return (false);
	is_solvable = go_to_goal(&v, v.start_row, v.start_col);
	dispose_so_long(&v);
	return (is_solvable);
}
