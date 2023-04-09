/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:28:33 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 07:18:48 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>

# define CHR_EMPTY_SPC '0'
# define CHR_WALL '1'
# define CHR_COLLECTIVE 'C'
# define CHR_MAP_EXIT 'E'
# define CHR_START_POS 'P'

# define CHR_VISITED '\a'

typedef struct s_so_long
{
	const char	**map;
	size_t		row_count;
	size_t		col_count;
	size_t		start_row;
	size_t		start_col;
}	t_so_long;

void	dispose_so_long(t_so_long *d);

#endif
