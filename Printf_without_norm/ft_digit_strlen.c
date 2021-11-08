/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_strlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:36:44 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/26 22:04:14 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_digit_unsigned_strlen(unsigned int digit)
{
	unsigned int i;

	i = 0; // счетчик
	if (digit == 0)
		return (1);
	while (digit > 0)
	{
		digit = digit / 10;
		i++;
	}
	return (i);
}

int		ft_digit_strlen(int digit)
{
	int i;

	i = 0; // счетчик
	if (digit < 0)
		digit = digit * (-1);
	if (digit == 0)
		return (1);
	while (digit > 0)
	{
		digit = digit / 10;
		i++;
	}
	return (i);
}

// int main()
// {
//     int str_i;

//     str_i = 12;
//     printf("%d", ft_digit_strlen(str_i));
// }




