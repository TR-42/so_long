/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:09:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/12 01:44:31 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mymlx.h"
#include "so_long.h"

static void	apply_half_move(const t_so_long *d, const t_mov_cmd *cmd,
	t_uxy *player)
{
	put_imgs(d, &(d->player));
	if (cmd->direction == UP)
		player->y -= IMG_HEIGHT * 0.5;
	else if (cmd->direction == DOWN)
		player->y += IMG_HEIGHT * 0.5;
	else if (cmd->direction == LEFT)
		player->x -= IMG_WIDTH * 0.5;
	else if (cmd->direction == RIGHT)
		player->x += IMG_WIDTH * 0.5;
}

void	put_collective(const t_so_long *d, const t_uxy *cl,
	bool put_only_collective)
{
	char	c;

	c = *c_at(d, cl);
	if (c == CHR_COLLECTIVE)
	{
		if (((d->counter / (STEP + 1)) & 0b100) == 0)
			mymlx_img_put_cr(d, &(d->img_collective1), cl->x, cl->y);
		else
			mymlx_img_put_cr(d, &(d->img_collective2), cl->x, cl->y);
	}
	else if (!put_only_collective)
		put_imgs(d, cl);
}

void	put_imgs(const t_so_long *d, const t_uxy *cl)
{
	char	c;

	c = *c_at(d, cl);
	if (c == CHR_MAP_EXIT || (cl->x == d->exit.x && cl->y == d->exit.y))
		mymlx_img_put_cr(d, &(d->img_exit), cl->x, cl->y);
	else if (c == CHR_START_POS)
		mymlx_img_put_cr(d, &(d->img_empty_spc), cl->x, cl->y);
	else if (c == CHR_COLLECTIVE)
		put_collective(d, cl, true);
	else if (c == CHR_EMPTY_SPC)
		mymlx_img_put_cr(d, &(d->img_empty_spc), cl->x, cl->y);
	else if (c == CHR_VISITED)
		mymlx_img_put_cr(d, &(d->img_empty_spc), cl->x, cl->y);
	else if (c == CHR_WALL)
		mymlx_img_put_cr(d, &(d->img_wall), cl->x, cl->y);
}

void	update_canvas(t_so_long *d, const t_mov_cmd *cmd)
{
	t_uxy		cl;
	t_uxy		player;

	if (d->mlx == NULL)
		return ;
	player = d->player;
	player.x *= IMG_WIDTH;
	player.y *= IMG_HEIGHT;
	if (cmd == NULL)
		mlx_clear_window(d->mlx, d->mlx_win);
	cl.y = 0;
	while (cl.y < d->row_count)
	{
		cl.x = 0;
		while (cl.x < d->col_count)
		{
			put_collective(d, &cl, (cmd != NULL
					&& (cmd->direction == 0 || cmd->direction == UNKNOWN)));
			cl.x++;
		}
		cl.y++;
	}
	if (cmd != NULL && cmd->direction != 0 && cmd->direction != UNKNOWN)
		apply_half_move(d, cmd, &player);
	mymlx_img_put(d, &(d->img_cat), player.x, player.y);
}
