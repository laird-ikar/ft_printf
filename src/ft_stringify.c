/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:42:03 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 10:11:47 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/_ft_printf.h"

/*
 *	ft_stringify
 *
 *	puts back all the tokens in a string
 *
 *	token:
 *		token list to transform in string
 */
char	*ft_stringify(t_list *token)
{
	char	*ret;
	char	*tmp;

	ret = ft_calloc(1, sizeof(char));
	while (token)
	{
		tmp = ret;
		ret = ft_strjoin(tmp, token->content);
		free(tmp);
		token = token->next;
	}
	return (ret);
}
