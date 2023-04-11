/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_on_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:44:31 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 19:33:30 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"
#include <stdio.h>

#define STEP 0x7FFF

int	on_loop(t_so_long *d)
{
	t_mov_cmd	cmd;

	if ((++(d->counter) & STEP) != 0 || d->cmds.len <= 0)
		return (0);
	cmd = *(t_mov_cmd *)(d->cmds.p);
	update_canvas(d, &cmd);
	return (0);
}
