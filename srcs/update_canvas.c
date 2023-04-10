/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:09:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 01:19:35 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mymlx.h"
#include "so_long.h"

static void	put_imgs(t_so_long *d, t_xy *cl, t_xy *player)
{
	char	c;

	c = d->map[cl->y][cl->x];
	if (c == CHR_START_POS)
		*player = *cl;
	else if (c == CHR_COLLECTIVE)
		mymlx_img_put(d, &(d->img_cat), cl->x, cl->y);
	else if (c == CHR_EMPTY_SPC)
		mymlx_img_put(d, &(d->img_cat), cl->x, cl->y);
	else if (c == CHR_MAP_EXIT)
		mymlx_img_put(d, &(d->img_cat), cl->x, cl->y);
	else if (c == CHR_VISITED)
		mymlx_img_put(d, &(d->img_cat), cl->x, cl->y);
	else if (c == CHR_WALL)
		mymlx_img_put(d, &(d->img_cat), cl->x, cl->y);
	cl->x++;
}

void	update_canvas(t_so_long *d)
{
	t_xy		cl;
	t_xy		player;

	mlx_clear_window(d->mlx, d->mlx_win);
	cl.y = 0;
	while (cl.y < (int)d->row_count)
	{
		cl.x = 0;
		while (cl.x < (int)d->col_count)
			put_imgs(d, &cl, &player);
		cl.y++;
	}
	mymlx_img_put(d, &(d->img_cat), player.x, player.y);
}
