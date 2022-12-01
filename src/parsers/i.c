/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:04 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 08:51:20 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	i(va_list lst, t_flag flag)
{
	t_buff	ret;
	int		data;

	data = va_arg(lst, int);
	ret.data = ft_itoa(data);
	ret.len = ft_strlen(ret.data);
	return (ret);
	(void) flag;
}
