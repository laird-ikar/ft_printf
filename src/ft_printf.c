/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:47:50 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 14:06:15 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../lib/libft/libft.h"

int	ft_printf(const char *ft_format, ...)
	__attribute__ ((format(printf(1, 2))))
{
	t_lst	**modules;
	char	*out_str;
	int		ret;
	va_list	args;

	va_start(args, ft_format);
	modules = ft_split_modules(ft_format);
	ft_parse(modules, args);
	out_str = ft_stringify(modules);
	ft_putstr_fd(out_str, 1);
	ret = ft_strlen(out_str);
	free(out_str);
	va_end(args);
	return(ret);
}

/*
	fill modules avec les morceaux
	i.e. "bla bvla lda % 0 'fefiuf ejfiusr "
	[bla bvla lda ]
	[% 0x]
	[ fefiuf ejfiusr]
*/
t_lst **ft_split_modules(const char *ft_format)
{
	int i;
	t_lst **ret;
	char *tmp;

	i = 0;
	while(ft_format[i] && ft_format[i] !== '&')
		i++;
	if (i++ == ft_strlen(ft_format))
	{
		*ret = ft_lstnew(ft_strdup(ft_format));
		return ret;
	}
	*ret->content = ft_strndup(ft_format, i);


}

/*
**	on transforme toutes les boites qui commencent par %
**	en le string que ca devrait etre (sachant qu'on peut pas check si va_args est content ou pas)
*/
void	ft_parse(t_list **modules, va_list args)
{
	t_list	*module;

	module = *modules;
	while (module)
	{

		module = module->next;
	}
}

/*
	on foure tout dans out_str
	on print out_str
	on return strlen(out_str)
*/
char	*ft_stringify()
{}
