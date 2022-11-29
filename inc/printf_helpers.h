/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helpers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:34:46 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 07:44:48 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_HELPERS_H
# define PRINTF_HELPERS_H

# include "ft_printf.h"

/*
**	FT_PARSE
*/
void	ft_parse(t_list **modules, va_list args);
void	decompose_numbered_flags(t_list *module, t_flags *flags, int *i);
t_flags	decompose_pur_flags(t_list module);

/*
**	FT_SPLIT_MODULE
*/
t_list	*ft_split_modules(const char *ft_format);
int		ft_is_flag(char c);

/*
**	FT_STRINGIFY
*/
char	*ft_stringify(t_list **modules);

#endif
