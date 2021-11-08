/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_type_uxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:15:19 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/26 22:11:06 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

///// TYPE UNSIGNED TEST //////
// char i[500];

int main()
{
	// int a;
	// a = 40563;
// "00034   "    - - - 3
// "00034      " - - - - - - 6
	// char i[500];
	
	//i = (unsigned long long *)malloc(sizeof(unsigned long long) * 200); // +1 для '\0'
	// i = 18446744073709551615;
	// printf("%p\n", &i);
	// ft_printf("%p\n", &i);

	// printf("%u\n", 4294967295u);
	// printf("%d", printf("%u\n", 4294967295u));
	// ft_printf("%u\n", 4294967295u);
	// printf("%d", ft_printf("%u\n", 4294967295u));
	int a01;
	int a02;
	int a03;
	printf("|%70p%70p%70p|\n",&a01,&a02,&a03);
	ft_printf("|%70p%70p%70p|\n",&a01,&a02,&a03);

	// printf("|%2.9p|\n", 1234);
	// ft_printf("|%2.9p|\n", 1234);
	// printf("|%.0p|\n", 0);
	// ft_printf("|%.0p|\n", 0);
// 8 -- my 6
// 	printf("|%02.7X|\n", 3267);
// 	ft_printf("|%02.7X|\n", 3267);

// 	printf("|%.4X|\n", 5263);
// 	ft_printf("|%.4X|\n", 5263);
// // 8 -- my 7
// 	printf("|08.5x|\n", 0);
// 	ft_printf("|08.5x|\n", 0);
// printf("-------------------");
// // 8 -- my 6
// 	printf("|%08.5x|\n", 34);
// 	ft_printf("|%08.5x|\n", 34);
// // 8 -- my 7
// 	printf("|08.5x|\n", 0);
// 	ft_printf("|08.5x|\n", 0);
	// printf("|%X|\n", a);
	// ft_printf("|%X|\n", a);
//"0  " 3 - - -
// "0"  7
	// printf("|%-8.5u|\n", 0);
	// ft_printf("|%-8.5u|\n", 0);
    //printf("|%u|\n", 4294967295);
	// ft_printf("|%u|\n", 4294967295);
//"0  " 0 - -
// "0"
	//printf("|%-8.5u|\n", 0);
	//ft_printf("|%-8.5u|\n", 0);
// 	 printf ("\n2.13 Вывод целого числа в шестнадцатеричном формате:\n");
//  { unsigned int d1=123;
//    printf ("%x\n",d1);
//  }
//  printf ("\n2.14 Вывод целого числа в шестнадцатеричном формате:\n");
//  { unsigned int d1=123;
//    printf ("%#x\n",d1);
// }
}