/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_on_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:44:31 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 22:32:49 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"
#include <stdio.h>

#define STEP 0x7FFF

static void	_on_move(t_so_long *d, t_mov_cmd *cmd, const t_uxy *cr)
{
	char		*c_to;

	if ((cr->x == 0 && cr->y == 0) || cmd->count < 2)
		return ;
	c_to = c_at(d, cr);
	if (*c_to == CHR_WALL)
		put_imgs(d, cr);
	else
	{
		if (*c_to == CHR_COLLECTIVE)
			d->collectives--;
		if (*c_to == CHR_MAP_EXIT && d->collectives <= 0)
			mlx_loop_end(d->mlx);
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

int	on_loop(t_so_long *d)
{
	t_mov_cmd	cmd;
	t_uxy		cr;

	if ((++(d->counter) & STEP) != 0 || d->cmds.len <= 0)
		return (0);
	((t_mov_cmd *)(d->cmds.p))->count++;
	cmd = *(t_mov_cmd *)(d->cmds.p);
	cr = apply_cmd(&cmd, &(d->player));
	_on_move(d, &cmd, &cr);
	update_canvas(d, &cmd);
	return (0);
}
