/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:09:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 01:43:34 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mymlx.h"
#include "so_long.h"

static void	apply_half_move(t_mov_cmd *cmd, t_xy *player)
{
	player->x *= IMG_WIDTH;
	player->y *= IMG_HEIGHT;
	if (cmd->direction == UP)
		player->y -= IMG_HEIGHT * 0.5;
	else if (cmd->direction == DOWN)
		player->y += IMG_HEIGHT * 0.5;
	else if (cmd->direction == LEFT)
		player->x -= IMG_WIDTH * 0.5;
	else if (cmd->direction == RIGHT)
		player->x += IMG_WIDTH * 0.5;
}

static void	put_imgs(t_so_long *d, t_xy *cl, t_xy *player)
{
	char	c;

	c = d->map[cl->y][cl->x];
	if (c == CHR_START_POS)
		*player = *cl;
	else if (c == CHR_COLLECTIVE)
		mymlx_img_put_cr(d, &(d->img_collective), cl->x, cl->y);
	else if (c == CHR_EMPTY_SPC)
		mymlx_img_put_cr(d, &(d->img_empty_spc), cl->x, cl->y);
	else if (c == CHR_MAP_EXIT)
		mymlx_img_put_cr(d, &(d->img_exit), cl->x, cl->y);
	else if (c == CHR_VISITED)
		mymlx_img_put_cr(d, &(d->img_empty_spc), cl->x, cl->y);
	else if (c == CHR_WALL)
		mymlx_img_put_cr(d, &(d->img_wall), cl->x, cl->y);
	cl->x++;
}

void	update_canvas(t_so_long *d)
{
	t_xy		cl;
	t_xy		player;
	t_mov_cmd	cmd;

	mlx_clear_window(d->mlx, d->mlx_win);
	cmd = (t_mov_cmd){0};
	if (0 < d->cmds.len)
		cmd = *(t_mov_cmd *)(d->cmds.p);
	cl.y = 0;
	while (cl.y < (int)d->row_count)
	{
		cl.x = 0;
		while (cl.x < (int)d->col_count)
			put_imgs(d, &cl, &player);
		cl.y++;
	}
	apply_half_move(&cmd, &player);
	mymlx_img_put(d, &(d->img_cat), player.x, player.y);
	vect_remove(&(d->cmds), 0);
}
