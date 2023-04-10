/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:02:55 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/11 01:15:35 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# define IMG_PATH_WHITE_CAT "./xpms/cat_tanmo_shiro.xpm"
# define IMG_PATH_EMPTY_SPC "./xpms/texture_sogen_01.xpm"
# define IMG_PATH_WALL "./xpms/texture_renga_brown_01.xpm"
# define IMG_PATH_COLLECTIVE "./xpms/coin_gold_02.xpm"
# define IMG_PATH_EXIT "./xpms/mark_mappin.xpm"

static const char	g_err[]
	= "Error\n";

static const char	g_err_inval_extension[]
	= "Invalid filename. It must end with `.ber`.";

static const char	g_err_inval_argc[]
	= "Invalid argc (usage: `so_long MAP_FILE_NAME`)";

static const char	g_err_map_style[]
	= "Invalid map style (maybe: map is not rect, or invalid char in the map)";

static const char	g_err_map_data[]
	= "Invalid map data (maybe: start/end pos, collectives, or no closed wall)";

static const char	g_err_map_not_solvable[]
	= "Invalid map data (unsolvable map)";

static const char	g_err_malloc_failed_mov_cmd[]
	= "Internal Error (cannot allocate memory for mov_cmd list)";

static const char	g_err_mlx_init_failed[]
	= "Internal Error (MiniLibX Initialization Failed)";

static const char	g_err_mlx_win_init_failed[]
	= "Internal Error (MiniLibX Window Creation Failed)";

static const char	g_err_mlx_load_img_failed_white_cat[]
	= "Cannot load asset file `" IMG_PATH_WHITE_CAT "` (maybe: file not found)";

static const char	g_err_mlx_load_img_failed_empty_spc[]
	= "Cannot load asset file `" IMG_PATH_EMPTY_SPC "` (maybe: file not found)";

static const char	g_err_mlx_load_img_failed_wall[]
	= "Cannot load asset file `" IMG_PATH_WALL "` (maybe: file not found)";

static const char	g_err_mlx_load_img_failed_collective[]
	= "Cannot load asset file `"
	IMG_PATH_COLLECTIVE "` (maybe: file not found)";

static const char	g_err_mlx_load_img_failed_exit[]
	= "Cannot load asset file `" IMG_PATH_EXIT "` (maybe: file not found)";

int	print_error_msg2(const char *str1, const char *str2);
int	print_error_msg(const char *str);
int	print_error_errno(int num);
int	print_error(void);

#endif
