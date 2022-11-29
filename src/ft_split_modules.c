/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_modules.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:42 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 08:49:11 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf_helpers.h"

/*
 *	ft_split_modules:
 *
 *	returns a pointer to a list of format tokens
 *
 *	format:
 *		the format string to tokenise
 *
 *	e.g.
 *		ft_format:		"bla bla bla %s %-3d bla bla%%%x%%"
 *		returned value:	["bla bla bla "]->["%s"]->[" "]->["%-3d"]->[" bla bla"]
 *							->["%%"]->["%x"]->["%%"]
 */
t_list	*ft_split_modules(const char *beg_str)
{
	const char	*end_str;
	t_list		*ret;
	int			in_flag;

	ret = NULL;
	end_str = beg_str;
	in_flag = *beg_str == '%';
	while (*end_str)
	{
		if (
			(in_flag && end_str != beg_str && is_conversion(*end_str))
			|| (!in_flag && *(end_str + 1) == '%')
		)
		{
			ft_lstadd_back(
				&ret,
				ft_lstnew(ft_strndup(beg_str, end_str - beg_str + 1))
				);
			in_flag = *(end_str + 1) == '%';
			beg_str = end_str + 1;
		}
		end_str++;
	}
	return (ret);
}

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
