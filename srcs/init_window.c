/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:08:59 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/16 11:58:39 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/ft_math.h"

#include "mlx.h"
#include "X11/X.h"

#include "error_messages.h"

#include "so_long.h"
#include "mymlx.h"

static bool	load_set_img(t_so_long *d, t_img *img,
	const char *path, const char *err_str)
{
	*img = mymlx_img_open(d, path);
	if (img->img != NULL)
	{
		d->imgsize.x = ft_max(d->imgsize.x, img->width);
		d->imgsize.y = ft_max(d->imgsize.y, img->height);
		return (true);
	}
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
		&& load_set_img(d, &(d->img_collective1), IMG_PATH_COLLECTIVE1,
			g_err_mlx_load_img_failed_collective1)
		&& load_set_img(d, &(d->img_collective2), IMG_PATH_COLLECTIVE2,
			g_err_mlx_load_img_failed_collective2)
		&& load_set_img(d, &(d->img_exit), IMG_PATH_EXIT,
			g_err_mlx_load_img_failed_exit)
	);
}

static int	_on_exposed(t_so_long *d)
{
	update_canvas(d, NULL);
	return (0);
}

static int	_on_destroyed(t_so_long *d)
{
	mlx_loop_end(d->mlx);
	return (0);
}

int	init_window(const char *argv0, t_so_long *d)
{
	d->mlx = mlx_init();
	if (d->mlx == NULL)
		return (print_error_msg(g_err_mlx_init_failed));
	if (!load_imgs(d))
		return (1);
	if (!can_mul(d->col_count, d->imgsize.x)
		|| !can_mul(d->row_count, d->imgsize.y))
		return (print_error_msg(g_err_map_size));
	d->mlx_win = mlx_new_window(d->mlx, d->col_count * d->imgsize.x,
			d->row_count * d->imgsize.y, (char *)argv0);
	if (d->mlx_win == NULL)
		return (print_error_msg(g_err_mlx_win_init_failed));
	mlx_loop_hook(d->mlx, on_loop, d);
	mlx_expose_hook(d->mlx_win, _on_exposed, d);
	mlx_key_hook(d->mlx_win, on_key_pressed, d);
	mlx_hook(d->mlx_win, DestroyNotify, StructureNotifyMask, _on_destroyed, d);
	update_canvas(d, NULL);
	return (0);
}
