/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:02:55 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/10 07:43:35 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

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

int	print_error_msg2(const char *str1, const char *str2);
int	print_error_msg(const char *str);
int	print_error_errno(int num);
int	print_error(void);

#endif
