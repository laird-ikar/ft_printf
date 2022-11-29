/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_modules.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:41:42 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 07:42:51 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf_helpers.h"

/*
**	fill modules avec les morceaux
**	i.e. "bla bvla lda % 0 'fefiuf ejfiusr "
**	[bla bvla lda ]
**	[% 0x]
**	[ fefiuf ejfiusr]
*/
// %d%%
int	need_cut(const char *ft_format, int inside_flag)
{
	if (inside_flag)
	{
		if (ft_strchr(CONVERSIONS, *ft_format))
			return (1);
		else
			return (0);
	}
	else if (*(ft_format + 1) == '%')
		return (1);
	return (0);
}

t_list	*ft_split_modules(const char *ft_format)
{
	t_list		*ret;
	int			inside_flag;
	const char	*ptr;

	ret = NULL;
	inside_flag = 0;
	ptr = ft_format;
	while (*ft_format)
	{
		if (need_cut(ft_format, inside_flag))
		{
			ft_lstadd_back(
				&ret,
				ft_lstnew(ft_strndup(ft_format, ft_format - ptr)));
			ft_format++;
			ptr = ft_format;
		}
		ft_format++;
	}
	return (ret);
}
