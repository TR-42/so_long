/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_pressed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:24:10 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 00:22:31 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - XK_*
#include <X11/keysym.h>

#include "mlx.h"

#include "so_long.h"

int	on_key_pressed(int keycode, t_so_long *d)
{
	t_mov_cmd	cmd;

	cmd = (t_mov_cmd){0};
	if (keycode == XK_Escape)
		mlx_loop_end(d->mlx);
	else if (keycode == XK_w || keycode == XK_Up)
		cmd.direction = UP;
	else if (keycode == XK_a || keycode == XK_Left)
		cmd.direction = LEFT;
	else if (keycode == XK_s || keycode == XK_Down)
		cmd.direction = DOWN;
	else if (keycode == XK_d || keycode == XK_Right)
		cmd.direction = RIGHT;
	if (cmd.direction != UNKNOWN)
		vect_push_back(&(d->cmds), &cmd, NULL);
	return (0);
}
