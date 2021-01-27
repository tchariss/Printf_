/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_type_persent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 02:09:15 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/27 01:54:36 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #define INT_MIN -2147483648
// #define INT_MAX 2147483647
int main(void)
{
 
	// printf("%%*i 42 == |%*i|\n", 2, 42);
	// ft_printf("%%*i 42 == |%*i|\n", 2, 42);

// |00034   |
// |   00034|
// |-00216    |
// |    -00216|
// |8375    |
// |    8375|
// |-8473   |
// |   -8473|

	printf("|%0-8.5i|\n", 34);
	ft_printf("|%0-8.5i|\n", 34);
	printf("|%0-10.5i|\n", -216);
	ft_printf("|%0-10.5i|\n", -216);
	printf("|%0-8.3d|\n", 8375);
	ft_printf("|%0-8.3d|\n", 8375);
	printf("|%0-8.3d|\n", -8473);
	ft_printf("|%0-8.3d|\n", -8473);
	
	// printf("Il fait au moins %u\n", -8000);
	// ft_printf("Il fait au moins %u\n", -8000);
	// printf("%u\n", INT_MIN);
	// ft_printf("%u\n", INT_MIN);
	// printf("%u\n", INT_MAX + 1);
	// ft_printf("%u\n", INT_MAX + 1);
	
	// printf("%i\n", INT_MIN);
	// ft_printf("%i\n", INT_MIN);
	// printf("%i\n", INT_MAX + 1);
	// ft_printf("%i\n", INT_MAX + 1);
	
	// printf("\n%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	// ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	// printf("%%-4d 42 == |%-4d|", 42);
	// ft_printf("%%-4d 42 == |%-4d|", 42);

//  	printf("\n--------------Check for %%-------------\n");
	
//     printf("|%5%|\n");
// 	ft_printf("|%5%|\n");
// 	printf("|%5.%|\n");
// 	ft_printf("|%5.%|\n");
// printf("\n--------------Check for %%-------------\n");
// 	printf("|%-5%|\n");
// 	ft_printf("|%-5%|\n");
// 	printf("|%-5.%|\n");
// 	ft_printf("|%-5.%|\n");
// printf("\n--------------Check for %%-------------\n");
// 	printf("|%*.*%|\n", 12, 15);
// 	ft_printf("|%*.*%|\n", 12, 15);
// 	printf("|%*.%|\n", 12);
// 	ft_printf("|%*.%|\n", 12);

// 	printf("|%0.*%|\n", 12);
// 	ft_printf("|%0.*%|\n", 12);

// 	printf("|%0*%|\n", 12);
// 	ft_printf("|%0*%|\n", 12);
//     printf("\n--------------Check for %%-------------\n");
// 	printf("|%0*.*%|\n", 12, 5);
// 	ft_printf("|%0*.*%|\n", 12, 15);
// 	printf("|%0*.*%|\n", 12, 1);
// 	ft_printf("|%0*.*%|\n", 12, 1);
// 	printf("|%0*.*%|\n", 1, 5);
// 	ft_printf("|%0*.*%|\n", 1, 5);
// 	printf("|%0*.*%|\n", 1, 1);
// 	ft_printf("|%0*.*%|\n", 1, 1);
// 	printf("|%0*.*%|\n", 12, 0);
// 	ft_printf("|%0*.*%|\n", 12, 0);

// 	ft_printf("|%0*.*%|\n", 0, 10);
// 	printf("|%0*.*%|\n", 0, 10);
// 	ft_printf("|%0*.*%|\n", 0, 0);
// 	printf("|%0*.*%|\n", 0, 0);
//  printf("\n--------------Check for %%-------------\n");
// 	ft_printf("|%*.*%|\n", -12, -15);
// 	printf("|%*.*%|\n", -12, -15);
// 	ft_printf("|%*.*%|\n", 12, -15);
// 	printf("|%*.*%|\n", 12, -15);
// 	ft_printf("|%*.%|\n", -12);
// 	printf("|%*.%|\n", -12);

// 	ft_printf("|%0.*%|\n", -12);
// 	printf("|%0.*%|\n", -12);

// 	ft_printf("|%0*%|\n", -12);
// 	printf("|%0*%|\n", -12);
// 	ft_printf("|%0*.*%|\n", -12, -5);
// 	printf("|%0*.*%|\n", -12, -5);
// 	ft_printf("|%0*.*%|\n", -12, -15);
// 	printf("|%0*.*%|\n", -12, -15);
// 	ft_printf("|%0*.*%|\n", -12, -1);
// 	printf("|%0*.*%|\n", -12, -1);
// 	ft_printf("|%0*.*%|\n", -1, -5);
// 	printf("|%0*.*%|\n", -1, -5);
// 	ft_printf("|%0*.*%|\n", -1, -1);
// 	printf("|%0*.*%|\n", -1, -1);
// 	ft_printf("|%0*.*%|\n", -12, 0);
// 	printf("|%0*.*%|\n", -12, 0);

// 	ft_printf("|%0*.*%|\n", 0, -10);
// 	printf("|%0*.*%|\n", 0, -10);
// 	ft_printf("|%0*.*%|\n", 0, 0);
// 	printf("|%0*.*%|\n", 0, 0);
// 	ft_printf("|%-05%|\n");
// 	printf("|%-05%|\n");
}