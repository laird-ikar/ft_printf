/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:39:48 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/09 12:01:08 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printf_chr(va_list args, int *count)
{
	char	c;

	c = (char) va_arg(args, int);
	ft_putchar_fd(c, 1);
	(*count)++;
}
