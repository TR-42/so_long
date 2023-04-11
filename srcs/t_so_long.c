/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:44:01 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/12 01:39:19 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mymlx.h"
#include "ft_mem/ft_mem.h"

#include <mlx.h>

// - NULL
#include <stddef.h>

// - free
#include <stdlib.h>

void	dispose_so_long(t_so_long *d)
{
	size_t	i;

	if (d == NULL || ft_memcmp(d, &(t_so_long){0}, sizeof(t_so_long)) == 0)
		return ;
	i = 0;
	while (i++ < d->row_count)
		free((void *)(d->map[i - 1]));
	free(d->map);
	vect_dispose(&(d->cmds));
	mymlx_img_destory(d, &(d->img_cat));
	mymlx_img_destory(d, &(d->img_collective1));
	mymlx_img_destory(d, &(d->img_collective2));
	mymlx_img_destory(d, &(d->img_empty_spc));
	mymlx_img_destory(d, &(d->img_exit));
	mymlx_img_destory(d, &(d->img_wall));
	if (d->mlx != NULL)
	{
		if (d->mlx_win != NULL)
			mlx_destroy_window(d->mlx, d->mlx_win);
		free(d->mlx);
	}
	*d = (t_so_long){0};
}

char	*c_at(const t_so_long *d, const t_uxy *cr)
{
	if (d == NULL || d->col_count <= cr->x || d->row_count <= cr->y)
		return (NULL);
	return (&(d->map[cr->y][cr->x]));
}

t_uxy	apply_cmd(const t_mov_cmd *cmd, const t_uxy *cr)
{
	if (cr == NULL)
		return ((t_uxy){0});
	if (cmd->direction == UP)
		return ((t_uxy){cr->x, cr->y - 1});
	else if (cmd->direction == DOWN)
		return ((t_uxy){cr->x, cr->y + 1});
	else if (cmd->direction == LEFT)
		return ((t_uxy){cr->x - 1, cr->y});
	else if (cmd->direction == RIGHT)
		return ((t_uxy){cr->x + 1, cr->y});
	return ((t_uxy){0});
}
