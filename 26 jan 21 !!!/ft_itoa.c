/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:20:35 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/23 12:27:50 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Itoa создает строковое представление целого числа
// Функция itoa () всегда возвращает строку значения

/* Функция ft_itoa распределяет (с помощью malloc) и возвращает «свежую» строку, 
заканчивающуюся на \0, представляющую целое число n, заданное в качестве аргумента. 
Подерживаются отрицательные числа. Если распределение завершается неудачно, функция возвращает NULL */

#include "ft_printf.h"

int		nbr(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while(n != 0)
	{
		n = n / 10;
		i++; 
	}
	return(i);
}

char	*ft_itoa(int n)
{
	char *res;
	int len;

	len = nbr(n); 
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	res[len--] = '\0';
	while(n > 9)
	{
		res[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	res[len] = n % 10 + '0'; // + '0' - или 48 по таблице ascii
    free (res);
	return (res); 
}