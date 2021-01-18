/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:44:15 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/17 15:29:18 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_char(t_flags *struct_pars, char c)
{
	/*
		if (width)
			пробелы и сам символ
		if (flags -)
			равняем слева
		if (flags 0)
			заполняем ширину оставшуюся 0
	*/
	int	num;

	num = 0;
	while (struct_pars->minus || struct_pars->zero)
		write (1, &c, 1);
	// num = num + write (1, &c, 1);
	return (num);
}

if (str[i] == 'c')



int			main()
{
	char a;
	a = 'c';
	printf ("|%531684c|\n", a); // c
	printf ("|%5c|\n", a); // - - - - c
	printf ("|%-5c|\n", a); // c - - - -
	printf ("|%05c|\n", a); // 0 0 0 0 c // неопределенное поведение
}