/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:33:28 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 09:47:09 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/_ft_printf.h"

/*
 *	is_conversion
 *
 *	check if a char is a conversion token or not
 *
 *	to_check:
 *		the char to check
 */
int	is_conversion(char to_check)
{
	return ((int) ft_strchr(CONVERSIONS, to_check));
}

/*
 *	is_flag
 *
 *	check if a char is a conversion flag or not
 *
 *	to_check:
 *		the char to check
 */
int	is_flag(char to_check)
{
	return ((int) ft_strchr(FLAGS, to_check));
}
