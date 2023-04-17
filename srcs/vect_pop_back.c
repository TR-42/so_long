/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:05:49 by kfujita           #+#    #+#             */
/*   Updated: 2023/04/17 23:08:48 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vect2.h"

void	*vect_pop_back(t_vect *vect)
{
	void	*ret;

	if (vect == NULL || vect->p == NULL || vect->len <= 0)
		return (NULL);
	ret = vect_at(vect, vect->len - 1);
	if (ret != NULL)
		vect->len -= 1;
	return (ret);
}
