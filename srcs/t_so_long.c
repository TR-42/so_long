/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 06:44:01 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 07:16:36 by kfujita          ###   ########.fr       */
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
