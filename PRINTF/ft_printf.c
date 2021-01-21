/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:25:18 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/21 14:44:10 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// SYNOPSIS
// va_list: список переменных аргументов. Указатель для хранения адреса памяти аргумента переменной
// #include <stdarg.h>
// - Тип va_list служит для описания переменной, которая будет по очереди указывать на каждый из аргументов
// 	type   va_arg(va_list ap, type); -> ap (от «argument pointer» — указатель на аргумент)
// - Макрос va_arg используется для получения доступа к очередному аргументу и при каждом вызове предвигает 
// указатель ap на следующий аргумент
// - va_arg возвращает текущий аргумент
// va_arg: получает значение, равное размеру определенного типа данных, из указателя аргумента переменной.
// 	void   va_start(va_list ap, last);
// va_start: установить указатель для получения переменных аргументов
// - Макрос va_start служит для инициализации списка переменных аргументов и должен иметь соответствующий вызов va_end
// 	void   va_end(va_list ap);
// va_end: после обработки аргумента переменной инициализировать указатель значением NULL
// - После получения всех аргументов va_end сбрасывает указатель на NULL
// 	void   va_copy(va_list dest, va_list src);
// -va_copy - для копирования объектов типа va_list

// va_list - тип данных, указатель на аргументы
size_t		ft_strlen(const char *str)
{
    size_t	a;

	a = 0;
	while (str[a] != '\0')
		a++;
    return(a);
}

int			ft_printf(const char *str, ...)
{
	t_flags	*str_spec;
	va_list	v1;
	char 	*s;
	int		num; // количество выведенных символов
	
	num = 0;
	str_spec = (t_flags *)ft_calloc(sizeof(t_flags), 1); // зануляю элементы структуры
	if (str_spec == NULL)
		return (-1); //ошибка
	str_spec->str = (char *)str;
	// s = (char *)str;
    va_start(v1, str);
	// str_spec->tochnost = -1;
	while (*str_spec->str)
	{
		if (*str_spec->str == '%')
		{
			str_spec->str++;
			parser(str_spec, v1);
		}
		else
		{
			// str_spec->num = str_spec->num + write(1, str_spec->str, 1);
			write(1, str_spec->str, 1);
			str_spec->str++;
		}
	}
	free(str_spec);
	va_end(v1);
	return (str_spec->num);
}
