/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 08:02:03 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/30 09:52:41 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/_ft_printf.h"

char	*c(va_list lst, t_flag flag)
{
	char	*ret;
	char	arg;

	ret = calloc(2, sizeof (char));
	arg = va_arg(lst, int);
	ret[0] = arg % 256;
	return (ret);
	(void) flag;
}
