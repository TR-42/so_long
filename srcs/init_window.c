/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:08:59 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 01:21:44 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "error_messages.h"

#include "so_long.h"
#include "mymlx.h"

static bool	load_set_img(const t_so_long *d, t_img *img,
	const char *path, const char *err_str)
{
	*img = mymlx_img_open(d, path);
	if (img->img != NULL)
		return (true);
	print_error_msg(err_str);
	return (false);
}

static int	load_imgs(t_so_long *d)
{
	return (
		load_set_img(d, &(d->img_cat), IMG_PATH_WHITE_CAT,
			g_err_mlx_load_img_failed_white_cat)
		&& load_set_img(d, &(d->img_empty_spc), IMG_PATH_EMPTY_SPC,
			g_err_mlx_load_img_failed_empty_spc)
		&& load_set_img(d, &(d->img_wall), IMG_PATH_WALL,
			g_err_mlx_load_img_failed_wall)
		&& load_set_img(d, &(d->img_collective), IMG_PATH_COLLECTIVE,
			g_err_mlx_load_img_failed_collective)
		&& load_set_img(d, &(d->img_exit), IMG_PATH_EXIT,
			g_err_mlx_load_img_failed_exit)
	);
}

int	init_window(const char *argv0, t_so_long *d)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		return (print_error_msg(g_err_mlx_init_failed));
	if (!load_imgs(d))
		return (1);
	d->mlx_win = mlx_new_window(d->mlx, d->col_count * IMG_WIDTH,
			d->row_count * IMG_HEIGHT, (char *)argv0);
	if (d->mlx_win == NULL)
		return (print_error_msg(g_err_mlx_win_init_failed));
	mlx_loop_hook(d->mlx, on_loop, d);
	mlx_hook(d->mlx_win, 2, (1L << 0), on_key_pressed, d);
	update_canvas(d);
	return (0);
}
