/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 07:32:08 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/26 14:52:41 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int		ft_strlen_16(unsigned long long digit)
{
	int i;

	i = 0; // счетчик
	if (digit == 0)
		return (1);
	while (digit > 0)
	{
		digit = digit / 16;
		i++;
	}
	return (i);
}

void		ft_16_putnbr(unsigned long long digit, char c, t_flags *str_spec)
{
	char 		*p; // массив , с памятью 21 -> 
	const char 	*str_x = "0123456789abcdef"; // число / 16 в диапазоне этого массива
	const char 	*str_X = "0123456789ABCDEF";
	int			i;
	int			len;

	len = ft_strlen_16(digit);
	i = len;
	p = malloc(sizeof(char) * (len));
	while (digit >= 16)
	{
		if (c == 'x' || c == 'p')
			p[len - 1] = str_x[digit % 16]; // остаток
		else // c == X
			p[len - 1] = str_X[digit % 16]; // остаток		
		digit = digit / 16; // тут снова делю
		len--; // назад по длине на шаг
	}
	if (c == 'x' || c == 'p')
		p[len - 1] = str_x[digit % 16]; // остаток
	else // c == X
		p[len - 1] = str_X[digit % 16]; // пречатаю последнюю(первую) букву (цифру)
	str_spec->num += write(1, p, i);
	free(p);
	p = NULL;
}

// int main()
// {
//     int str_i;

//     str_i = 7586;
// 	ft_16_putnbr(str_i, 'X');
// 	printf("\n%s\n", "_________________");
// 	ft_16_putnbr(256, 'x');
// 	printf("\n%s\n", "_________________");
// 	ft_16_putnbr(40563, 'X');
// 	printf("\n%s\n", "_________________");
// 	ft_16_putnbr(40563, 'x');
// }

// int main()
// {
// 	int x = 0xF;
// }

// void  ft_sis(int num)
// {
// 	int count;
// 	int copy_num = num;
// 	while (copy_num > 15)
// 	{
// 		count++;
// 		copy_num /= 16;
// 	}


// }