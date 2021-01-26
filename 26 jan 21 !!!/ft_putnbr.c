/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 08:55:56 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/26 10:37:58 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(int nb, t_flags *str_spec)
{
	if (nb == -2147483648)
	{
		str_spec->num += ft_putchar_len('-', 1);
		str_spec->num += ft_putchar_len('2', 1);
		str_spec->num += ft_putnbr(147483648, str_spec);
	}
	else if (nb < 0)
	{
		str_spec->num += ft_putchar_len('-', 1);
		str_spec->num += ft_putnbr(nb * (-1), str_spec);
	}
	else
	{
		if (nb >= 10)
			str_spec->num += ft_putnbr(nb / 10, str_spec);
		str_spec->num += ft_putchar_len(nb % 10 + '0', 1);
	}
	return (0);
}