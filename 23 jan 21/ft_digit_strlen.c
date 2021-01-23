/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_strlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:36:44 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/23 14:05:54 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_digit_strlen(int digit)
{
	int i;

	i = 0; // счетчик
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