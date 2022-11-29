/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:34:46 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 08:59:09 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "ft_printf.h"

# ifndef T_FLAG
#  define T_FLAG

typedef struct s_flag
{
	int	to_parse;
}	t_flag;

# endif

/*
**	FT_PARSE
*/
void	ft_parse(t_list *module, va_list args);
t_flag	get_flag(char *token);
char	*parse_arg(va_list args, t_flag flag);

/*
**	FT_SPLIT_MODULE
*/
t_list	*ft_split_module(const char *ft_format);
int		is_conversion(char to_check);

/*
**	FT_STRINGIFY
*/
char	*ft_stringify(t_list *module);

#endif
