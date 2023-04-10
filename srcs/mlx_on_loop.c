/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_on_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:44:31 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 22:03:06 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long.h"
#include <stdio.h>

#define STEP 0x7FFF

int	on_loop(t_so_long *d)
{
	if ((++(d->counter) & STEP) != 0 || d->cmds.len <= 0)
		return (0);
	update_canvas(d);
	return (0);
}
