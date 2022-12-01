/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:48:18 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 08:50:32 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	d(va_list lst, t_flag flag)
{
	t_buff	ret;
	int		data;

	data = va_arg(lst, int);
	ret.data = ft_itoa(data);
	ret.len = ft_strlen(ret.data);
	return (ret);
	(void) flag;
}
