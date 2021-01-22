/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:03:36 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/19 18:00:29 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//выводим строку
int		ft_putstr(char *s, int len)
{
	if (len == 0)
		return (0);
	write(1, s, len);
	return (len);
}
