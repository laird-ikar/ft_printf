/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:50 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 08:58:17 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/_ft_printf.h"

int	ft_printf(const char *ft_format, ...)
{
	t_list	*module;
	char	*out_str;
	int		ret;
	va_list	args;

	if (ft_strlen(ft_format) == 0)
		return (0);
	va_start(args, ft_format);
	module = ft_split_module(ft_format);
	ft_parse(module, args);
	out_str = ft_stringify(module);
	ft_putstr_fd(out_str, 1);
	ret = ft_strlen(out_str);
	free(out_str);
	va_end(args);
	return (ret);
}
