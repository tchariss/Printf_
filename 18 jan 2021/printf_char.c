/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:44:15 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/16 13:15:50 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_char(t_flags *struct_pars, char c)
{
	int	num;

	num = 0;
	while (struct_pars->minus || struct_pars->zero)
		num = num + write (1, &c, 1);
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