/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:42:45 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/18 15:23:46 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_atoi(const char *str)
{
	size_t			i;
	unsigned long	res;
	int				sym;

	i = 0;
	res = 0;
	sym = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\r' || str[i] == '\f' || str[i] == '\v') // ft_isspace(str[i]) -> i++ 
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sym = ((str[i] == '-') ? -1 : 1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') // ft_isdigit(str[i])
	{
		res = 10 * res + (str[i++] - '0');
	}
	if (res > 9223372036854775807)
	{
		if (sym == 1)
			return (-1);
		return (0);
	}
	return (res * sym); 
}

// int main (void)
// {   
//    char *str = "-652556%66.23brrt"; //Строка для преобразования
//    int num = 0;                //Переменная для записи результата
   
//    //Преобразование строки в число типа int
//    num = ft_atoi (str);
   
//    printf ("%d\n", num);
//    printf ("%d\n", ft_atoi("-21345654"));
//    printf ("%d\n", ft_atoi("870"));
//    return 0; 
// }
