/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:02:03 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 08:47:01 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	c(va_list lst, t_flag flag)
{
	t_buff	ret;
	char	data;

	data = va_arg(lst, int);
	ret.len = 1;
	ret.data = ft_strndup(&data, 1);
	return (ret);
	(void) flag;
}
