/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:42:27 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/01 08:05:43 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUFF_H
# define FT_BUFF_H

# include <stddef.h>
# include <stdlib.h>
# include "ft_memory.h"

# ifndef T_BUFF
#  define T_BUFF

typedef struct s_buffer
{
	char	*data;
	size_t	len;
}	t_buff;

# endif

#endif
