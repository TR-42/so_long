/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:20:49 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 17:38:29 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "mymlx.h"
#include "so_long.h"

t_img	mymlx_img_open(const t_so_long *d, const char *fname)
{
	t_img	info;

	if (d == NULL || d->mlx == NULL || fname == NULL || *fname == '\0')
		return ((t_img){0});
	info.img = mlx_xpm_file_to_image(d->mlx, (char *)fname,
			&(info.width), &(info.height));
	return (info);
}

bool	mymlx_img_put(const t_so_long *d, const t_img *info, int x, int y)
{
	if (!d || !(d->mlx) || !(d->mlx_win) || !info || !(info->img))
		return (false);
	mlx_put_image_to_window(d->mlx, d->mlx_win, info->img, x, y);
	return (true);
}

bool	mymlx_img_destory(const t_so_long *d, t_img *info)
{
	if (d == NULL || d->mlx == NULL || info == NULL)
		return (false);
	if (info->img != NULL)
		mlx_destroy_image(d->mlx, info->img);
	*info = (t_img){0};
	return (true);
}
