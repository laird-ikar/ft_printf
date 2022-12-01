/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:22 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 08:54:44 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	percent(va_list lst, t_flag flag)
{
	t_buff	ret;
	char	*data;

	data = va_arg(lst, char *);
	ret.data = ft_strdup(data);
	ret.len = ft_strlen(ret.data);
	return (ret);
	(void) flag;
}
