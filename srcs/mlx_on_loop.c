/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_on_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:44:31 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/12 01:28:38 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"

#include "ft_mem/ft_mem.h"
#include "ft_string/ft_string.h"
#include "ft_printf/ft_printf.h"

#define COUNT_INIT_STR "Count: 0"

static bool	_on_move_back_from_wall(t_so_long *d,
	const t_uxy *cr, const char *c_to)
{
	t_mov_cmd	*vect;

	vect = (t_mov_cmd *)d->cmds.p;
	if (*c_to != CHR_WALL)
		return (false);
	put_imgs(d, cr);
	if (3 <= d->cmds.len
		&& vect->direction == vect[1].direction
		&& vect[1].direction == vect[2].direction)
		ft_printf("... (Because you tried to move in the same direction"
			"not once or twice after reaching the wall..."
			"so, I omitted the move-logs)\n");
	while (2 <= d->cmds.len
		&& vect->direction == vect[1].direction
		&& vect[1].direction == vect[2].direction)
	{
		vect_remove(&(d->cmds), 1);
		d->mov_count++;
	}
	return (true);
}

static void	_on_move(t_so_long *d, t_mov_cmd *cmd, const t_uxy *cr, char *c_to)
{
	if ((cr->x == 0 && cr->y == 0) || cmd->count < 2)
		return ;
	if (!_on_move_back_from_wall(d, cr, c_to))
	{
		if (*c_to == CHR_COLLECTIVE)
			d->collectives--;
		if (*c_to == CHR_MAP_EXIT && d->collectives <= 0)
			dispose_so_long(d);
		if (d->player.x == d->exit.x && d->player.y == d->exit.y)
			*c_at(d, &(d->player)) = CHR_MAP_EXIT;
		else
			*c_at(d, &(d->player)) = CHR_VISITED;
		put_imgs(d, &(d->player));
		*c_to = CHR_START_POS;
		d->player = *cr;
	}
	vect_remove(&(d->cmds), 0);
	*cmd = (t_mov_cmd){0};
}

static bool	_put_print_mov_count(t_so_long *d, const t_mov_cmd *cmd)
{
	static char	numstr_buf[32] = {0};

	if (numstr_buf[0] == 0)
		ft_memcpy(numstr_buf, COUNT_INIT_STR, sizeof(COUNT_INIT_STR));
	else
	{
		if (cmd == NULL)
			return (false);
		if (cmd->count == 1)
		{
			d->mov_count++;
			ft_printf("Move! No.%06u from (%2d, %2d), direction: %c)\n",
				(unsigned)d->mov_count, (unsigned)d->player.x,
				(unsigned)d->player.y, cmd->direction);
			get_numstr_base(numstr_buf + 7, d->mov_count, 10, false);
		}
	}
	mlx_string_put(d->mlx, d->mlx_win, 2, 12, 0xFFFFFF, numstr_buf);
	return (true);
}

int	on_loop(t_so_long *d)
{
	t_mov_cmd	cmd;
	t_uxy		cr;
	size_t		i;

	if (d->mlx == NULL)
		return (0);
	cmd = (t_mov_cmd){0};
	_put_print_mov_count(d, NULL);
	if ((++(d->counter) & STEP) != 0)
		return (0);
	if (0 < d->cmds.len)
	{
		((t_mov_cmd *)(d->cmds.p))->count++;
		cmd = *(t_mov_cmd *)(d->cmds.p);
		cr = apply_cmd(&cmd, &(d->player));
		_on_move(d, &cmd, &cr, c_at(d, &cr));
		i = 0;
		while (i++ < d->col_count - 1)
			put_imgs(d, &(t_uxy){i, 0});
		update_canvas(d, &cmd);
		_put_print_mov_count(d, &cmd);
	}
	else
		update_canvas(d, &cmd);
	return (0);
}
