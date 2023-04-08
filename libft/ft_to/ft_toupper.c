/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:44:19 by kfujita           #+#    #+#             */
/*   Updated: 2022/04/26 00:30:01 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_to.h"
#include "../ft_is/ft_is.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c + ('A' - 'a'));
	else
		return (c);
}