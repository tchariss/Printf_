/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01 /19 23:55:52 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/21 14:50:22 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

///// TYPE STRING TEST //////

int main()
{
	/// return value 6 - my 3
	printf("%5s\n", "goes over"); // |vikos|
	ft_printf("%5s\n", "goes over");
	// int i = ft_printf("%5s", "goes over");
	// printf("\nreturned - %d\n", i);

	printf("%3s\n", "hi low"); // |vikos|
	ft_printf("%3s", "hi low");	

	

	printf("4|%*s|\n", -6, "vikos");
	ft_printf("4|%*s|\n", -6, "vikos"); // |vikos|
	printf("6|%-*s|\n", -6, "vikos");
	ft_printf("6|%-*s|\n", -6, "vikos");

	

// 	printf("16|%-*.s|\n", -8, "vikos"); // |vikos|
// 	ft_printf("16|%-*.s|\n", -8, "vikos");
// 	printf("16|%-*.7s|\n", -8, "vikos"); // |vikos|
// 	ft_printf("16|%-*.7s|\n", -8, "vikos");
// 	printf("17|%*.6s|\n", -8, "vikos"); // |vikos|
// 	ft_printf("17|%*.6s|\n", -8, "vikos");
// 	printf("17|%*.0s|\n", 8, "vikos"); // |vikos|
// 	ft_printf("17|%*.0s|\n", 8, "vikos");
// 	printf("17|%*s|\n", 8, "vikos"); // |vikos|
// 	ft_printf("17|%*s|\n", 8, "vikos");
// 	printf("17|%*.0s|\n", 4, "vikos"); // |vikos|
// 	ft_printf("17|%*.0s|\n", 4, "vikos");
// 	printf("17|%*s|\n", 4, "vikos"); // |vikos|
// 	ft_printf("17|%*s|\n", 4, "vikos");
// // если ничего нет
// 	printf("1|%s|\n", "vikos"); // |vikos|
// 	ft_printf("1|%s|\n", "vikos");
// // если существует длина / ширина / флаг
// 	printf("2|%6s|\n", "vikos"); // |vikos|
// 	ft_printf("2|%6s|\n", "vikos");
// 	printf("3|%6.4s|\n", "vikos"); // |vikos|
// 	ft_printf("3|%6.4s|\n", "vikos");
// 	printf("4|%-6.4s|\n", "vikos"); // |vikos|
// 	ft_printf("4|%-6.4s|\n", "vikos");
// 	printf("4|%-6.44s|\n", "vikos"); // |vikos|
// 	ft_printf("4|%-6.44s|\n", "vikos");
// 	printf("5|%.s|\n", "vikos"); // |vikos|
// 	ft_printf("5|%.s|\n", "vikos");
// 	printf("6|%-4.s|\n", "vikos"); // |vikos|
// 	ft_printf("6|%-4.s|\n", "vikos");
// 	printf("7|%-s|\n", "vikos"); // |vikos|
// 	ft_printf("7|%-s|\n", "vikos");
// // // ширина
// 	printf("8|%6.4s|\n", "vikos"); // |vikos|
// 	ft_printf("8|%6.4s|\n", "vikos");
// 	printf("9|%4.3s|\n", "vikos"); // |vikos|
// 	ft_printf("9|%4.3s|\n", "vikos");
// 	printf("10|%6.8s|\n", "vikos"); // |vikos|
// 	ft_printf("10|%6.8s|\n", "vikos");
// 	printf("11|%4.8s|\n", "vikos"); // |vikos|
// 	ft_printf("11|%4.8s|\n", "vikos");
// // // точность
//  	printf("12|%4.6s|\n", "vikos"); // |vikos|
// 	ft_printf("12|%4.6s|\n", "vikos");
// 	printf("13|%8.6s|\n", "vikos"); // |vikos|
// 	ft_printf("13|%8.6s|\n", "vikos");
// 	printf("14|%2.4s|\n", "vikos"); // |vikos|
// 	ft_printf("14|%2.4s|\n", "vikos");
// 	printf("15|%6.4s|\n", "vikos"); // |vikos|
// 	ft_printf("15|%6.4s|\n", "vikos");
// 	printf("16|%-*.6s|\n", -8, "vikos"); // |vikos|
// 	ft_printf("16|%-*.6s|\n", -8, "vikos");
// 	printf("17|%*.6s|\n", -8, "vikos"); // |vikos|
// 	ft_printf("17|%*.6s|\n", -8, "vikos");
// 	printf("17|%*.*s|\n", -8, -6, "vikos"); // |vikos|
// 	ft_printf("17|%*.*s|\n", -8, -6, "vikos");
	
// 	////////----%-----%-----%----////////
// 	printf("17|%8.6s|\n", "%vikos"); // |vikos|
// 	ft_printf("17|%8.6s|\n", "%vikos");
// 	printf("17|%%|\n"); // |vikos|
// 	ft_printf("17|%%|\n");
// 	printf("17|%c|\n", '%'); // |vikos|
// 	ft_printf("17|%c|\n", '%');
// 	printf("17|%.*s|\n", 0, "vikos");
// 	ft_printf("17|%.*s|\n", 0, "vikos");
// 	printf("17|%.*s|\n", -3, "vikos");
// 	ft_printf("17|%.*s|\n", -3, "vikos");
// 	printf("17|%.*s|\n", 7, "vikos");
// 	ft_printf("17|%.*s|\n", 7, "vikos");
// 	printf("17|%.*s|\n", 3, "vikos");
// 	ft_printf("17|%.*s|\n", 3, "vikos");

// ////////-------------------------------////////

// //// type_s
// //// 1 условие 
// //// if ( minus || width < 0 )
// 	printf("1|%s|\n", "vikos"); // |vikos|
// 	ft_printf("1|%s|\n", "vikos");
// 	printf("1-2|%.s|\n", "vikos"); // |vikos|
// 	ft_printf("1-2|%.s|\n", "vikos");
// 	printf("1-3|%.0s|\n", "vikos"); // |vikos|
// 	ft_printf("1-3|%.0s|\n", "vikos");
// 	printf("2|%-s|\n", "vikos"); // |vikos|
// 	ft_printf("2|%-s|\n", "vikos"); 
// 	printf("3|%*s|\n", -4, "vikos");
// 	ft_printf("3|%*s|\n", -4, "vikos"); // |vikos|
// 	printf("4|%*s|\n", -6, "vikos");
// 	ft_printf("4|%*s|\n", -6, "vikos"); // |vikos|
// 	printf("5|%-*s|\n", -4, "vikos");
// 	ft_printf("5|%-*s|\n", -4, "vikos"); 
// 	printf("6|%-*s|\n", -6, "vikos");
// 	ft_printf("6|%-*s|\n", -6, "vikos");

// ////////-------------------------------////////
// ////////-------------------------------////////

// 	printf("|%-*.10s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%-*.10s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%-*.80s|\n", 20,  "12345678");
// 	ft_printf("|%-*.80s|\n", 20,  "12345678");
// 	printf("|%-*.080s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%-*.080s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");


// 	printf("|%-*.0s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%-*.0s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%-8s|\n", "abrafdefgbr");
// 	ft_printf("|%-8s|\n", "abrafdefgbr");
// 	printf("|%.101s|\n", "abra");
// 	ft_printf("|%.101s|\n", "abra");
// 	printf("|%.03s|\n", "abra");
// 	ft_printf("|%.03s|\n", "abra");
	
// 	printf("\n--------------Check for s-------------\n");
// 	printf("|%8s|\n", "abra");
// 	ft_printf("|%8s|\n", "abra");
// 	printf("|%-8s|\n", "abrafdefgbr");
// 	ft_printf("|%-8s|\n", "abrafdefgbr");
// 	printf("|%8s|\n", "abra");
// 	ft_printf("|%8s|\n", "abra");
// 	printf("|%8s|\n", "abrafdefgbr");
// 	ft_printf("|%8s|\n", "abrafdefgbr");
	
//     ft_printf("\n|%*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%*.*s|\n", 20, 5,  "1234567890123fsfbdfbdfvbbdvbvb");
//     printf("\n----------------------\n");
// 	ft_printf("\n|%-*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%-*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%.*s|\n",  5, "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%.*s|\n",  5, "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%*.s|\n", 20, "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%.s|\n",  "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%.s|\n",  "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("\n----------------------\n");

// 	printf("|%*s|\n",  40, "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%*s|\n",  40, "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%-*.0s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%-*.0s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%*.1s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%*.1s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%-*.*s|\n", 2, 20, "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%-*.*s|\n", 2, 20, "1234567890123fsfbdfbdfvbbdvbvb");
// 	printf("|%-*.*s|\n", 2, 20, "1234567890123fsfbdfbdfvbbdvbvb");
// 	ft_printf("|%-*.*s|\n", 2, 20, "1234567890123fsfbdfbdfvbbdvbvb");
}