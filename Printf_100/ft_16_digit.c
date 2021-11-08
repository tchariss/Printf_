/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 07:32:08 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 16:35:49 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_strlen_16(unsigned long long digit)
{
	int			i;

	i = 0;
	if (digit == 0)
		return (1);
	while (digit > 0)
	{
		digit = digit / 16;
		i++;
	}
	return (i);
}

void			ft_16_putnbr(unsigned long long digit, char c,
											t_flags *str_spec)
{
	char		p[17];
	const char	*str_x = "0123456789abcdef";
	const char	*str_big_x = "0123456789ABCDEF";
	int			i;
	int			len;

	len = ft_strlen_16(digit);
	i = len;
	while (digit >= 16)
	{
		if (c == 'x' || c == 'p')
			p[len - 1] = str_x[digit % 16];
		else
			p[len - 1] = str_big_x[digit % 16];
		digit = digit / 16;
		len--;
	}
	if (c == 'x' || c == 'p')
		p[len - 1] = str_x[digit % 16];
	else
		p[len - 1] = str_big_x[digit % 16];
	p[i] = '\0';
	str_spec->num += write(1, p, i);
}
