/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:50:10 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 16:38:02 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

t_buff	*p(va_list lst, t_flag flag)
{
	t_buff	*ret;
	char	*number;
	void	*data;

	ret = ft_calloc(1, sizeof (t_buff));
	data = va_arg(lst, void *);
	number = ft_ultoa_base((unsigned long) data, "0123456789abcdef");
	ret->data = ft_strjoin("0x", number);
	free (number);
	ret->len = ft_strlen(ret->data);
	return (ret);
	(void) flag;
}
