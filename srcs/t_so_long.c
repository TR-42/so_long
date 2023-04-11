/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:44:01 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 21:42:54 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stddef.h>
#include <stdlib.h>

void	dispose_so_long(t_so_long *d)
{
	size_t	i;

	if (d == NULL)
		return ;
	i = 0;
	while (i++ < d->row_count)
		free((void *)(d->map[i - 1]));
	free(d->map);
	*d = (t_so_long){0};
}

char	*c_at(const t_so_long *d, const t_uxy *cr)
{
	if (d == NULL || d->col_count <= cr->x || d->row_count <= cr->y)
		return (NULL);
	return (&(d->map[cr->y][cr->x]));
}
