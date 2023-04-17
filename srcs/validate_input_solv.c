/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input_solv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:38:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/18 00:04:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_string/ft_string.h"

#include "validate_input.h"
#include "ft_vect2.h"

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
	v.collectives = d->collectives;
	v.col_count = d->col_count;
	v.start = d->start;
	if (v.row_count != d->row_count)
		dispose_so_long(&v);
	return (v);
}

static bool	update_map_and_stack(t_so_long *d, t_vect *to_chk, const t_xy *cr)
{
	char	c;

	if (d->map[cr->y][cr->x] == CHR_WALL || d->map[cr->y][cr->x] == CHR_VISITED)
		return (true);
	d->map[cr->y][cr->x] = CHR_VISITED;
	c = d->map[cr->y][cr->x - 1];
	if (c != CHR_WALL && c != CHR_VISITED
		&& !vect_push_back(to_chk, &(t_xy){cr->x - 1, cr->y}, NULL))
		return (false);
	c = d->map[cr->y][cr->x + 1];
	if (c != CHR_WALL && c != CHR_VISITED
		&& !vect_push_back(to_chk, &(t_xy){cr->x + 1, cr->y}, NULL))
		return (false);
	c = d->map[cr->y - 1][cr->x];
	if (c != CHR_WALL && c != CHR_VISITED
		&& !vect_push_back(to_chk, &(t_xy){cr->x, cr->y - 1}, NULL))
		return (false);
	c = d->map[cr->y + 1][cr->x];
	if (c != CHR_WALL && c != CHR_VISITED
		&& !vect_push_back(to_chk, &(t_xy){cr->x, cr->y + 1}, NULL))
		return (false);
	return (true);
}

// TODO: mallocエラーに対応する
// TODO: handle error after calling `update_map_and_stack`
static bool	go_to_goal(t_so_long *d, size_t row, size_t col, bool *is_goaled)
{
	t_xy	cr;
	t_vect	to_chk;

	to_chk = vect_init(256, sizeof(t_xy));
	vect_push_back(&to_chk, &(t_xy){col, row}, NULL);
	while (to_chk.p != NULL && 0 < to_chk.len)
	{
		cr = *(t_xy *)vect_pop_back(&to_chk);
		if (d->map[cr.y][cr.x] == CHR_MAP_EXIT)
			*is_goaled = true;
		else if (d->map[cr.y][cr.x] == CHR_COLLECTIVE)
			d->collectives--;
		if (!update_map_and_stack(d, &to_chk, &cr))
			break ;
	}
	vect_dispose(&to_chk);
	return (*is_goaled && d->collectives <= 0);
}

// checks...
// - is it solvable?
bool	is_map_solvable(t_so_long *d)
{
	t_so_long	v;
	bool		is_goaled;
	bool		is_solvable;
	size_t		row;
	size_t		col;

	row = 0;
	while (++row < d->row_count && d->start.y == 0)
	{
		col = 0;
		while (++col < d->col_count && d->start.x == 0)
			if (d->map[row][col] == CHR_START_POS)
				d->start = (t_uxy){col, row};
	}
	v = dup_so_long(d);
	if (v.map == NULL)
		return (false);
	is_goaled = false;
	is_solvable = go_to_goal(&v, v.start.y, v.start.x, &is_goaled);
	dispose_so_long(&v);
	return (is_solvable);
}
