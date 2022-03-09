/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:40:09 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/09 11:58:03 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_printf_percent(va_list args, int *count)
{
	(void) args;
	ft_putchar_fd('%', 1);
	(*count)++;
}
