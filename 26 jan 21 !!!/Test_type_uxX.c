/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_type_uxX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:15:19 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/26 14:24:08 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

///// TYPE UNSIGNED TEST //////

int main()
{
	// int a;
	// a = 40563;
// "00034   "    - - - 3
// "00034      " - - - - - - 6
	printf("%5x", 52625);
	ft_printf("%5x", 52625);
	
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