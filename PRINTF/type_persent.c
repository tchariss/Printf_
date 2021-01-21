/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_persent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:47:53 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/20 13:16:16 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		type_persent(t_flags *str_spec, va_list v1)
{
	char	*s;

	s = va_arg(v1, char*);
	if (ft_strchr(s, '%'))
	{
		str_spec->num += write(1, s, 1);	
	}
}