/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:08:59 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 20:50:23 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "error_messages.h"

#include "so_long.h"
#include "mymlx.h"

int	init_window(const char *argv0, t_so_long *d)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		return (print_error_msg(g_err_mlx_init_failed));
	d->img_cat = mymlx_img_open(d, IMG_PATH_WHITE_CAT);
	if (d->img_cat.img == NULL)
		print_error_msg(g_err_mlx_load_img_failed_white_cat);
	d->mlx_win = mlx_new_window(d->mlx, d->col_count * IMG_WIDTH,
			d->row_count * IMG_HEIGHT, (char *)argv0);
	if (d->mlx_win == NULL)
		return (print_error_msg(g_err_mlx_win_init_failed));
	mlx_hook(d->mlx_win, 2, (1L << 0), on_key_pressed, d);
	mlx_put_image_to_window(d->mlx, d->mlx_win, d->img_cat.img, 32, 32);
	return (0);
}
