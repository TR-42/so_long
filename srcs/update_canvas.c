/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_canvas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:09:52 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 21:23:00 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "mymlx.h"
#include "so_long.h"

void	update_canvas(t_so_long *d)
{
	size_t	row;
	size_t	col;

	mlx_clear_window(d->mlx, d->mlx_win);
	row = 0;
	while (row++ < d->row_count)
	{
		col = 0;
		while (col++ < d->col_count)
		{
			mymlx_img_put_cr(d, &(d->img_cat), col - 1, row - 1);
		}
	}
}
