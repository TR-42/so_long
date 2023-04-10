/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_pressed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 08:24:10 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 09:49:27 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - XK_Escape
#include <X11/keysym.h>

#include "mlx.h"

#include "so_long.h"

int	on_key_pressed(int keycode, t_so_long *d)
{
	if (keycode == XK_Escape)
		mlx_loop_end(d->mlx);
	return (0);
}
