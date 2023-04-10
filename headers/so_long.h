/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 05:28:33 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 20:50:42 by kfujita          ###   ########.fr       */
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

# define IMG_WIDTH 32
# define IMG_HEIGHT (IMG_WIDTH)

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
}	t_img;

typedef struct s_so_long
{
	void		*mlx;
	void		*mlx_win;
	const char	**map;
	size_t		row_count;
	size_t		col_count;
	size_t		start_row;
	size_t		start_col;
	t_img		img_cat;
}	t_so_long;

int		init_window(const char *argv0, t_so_long *d);
void	dispose_so_long(t_so_long *d);

int		on_key_pressed(int keycode, t_so_long *d);
#endif
