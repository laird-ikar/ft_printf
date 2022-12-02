/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:22 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/02 09:40:02 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	*s(va_list lst, t_flag flag)
{
	t_buff	*ret;
	char	*data;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, char *);
	if (data == NULL)
		ret->data = ft_strdup("(null)");
	else
		ret->data = ft_strdup(data);
	ret->len = ft_strlen(ret->data);
	apply_width(ret, flag.min_width, flag.padding_type);
	return (ret);
}
