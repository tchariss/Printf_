/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:39:56 by tchariss          #+#    #+#             */
/*   Updated: 2021/01/18 14:04:54 by tchariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int     main()
{
    int i = 1;
    int j = 2;
    
    printf("Hello World!\n");
    ft_printf("H\n%-s", "vik");
    printf("%d\n", 1);
    printf("---------------------\n");
	printf("1. |%*d|\n", 3, i);
    printf("2. |%-*d|\n", 3, i);
	printf("3. |%.*d|\n", 5, i); 
    printf("4. |%*.*d|\n", 3, 5, i); 
    printf("5. |%*.*d|\n", 5, 3, i); 
    printf("6. |%*d|\n", 3, 1234);
	printf("7. |%.*d|\n", 3, 1234);
    printf("8. |%-*d|\n", 6, 3);   
    printf("9. |%0*d|\n", 6, 3);  
    printf("10.|%-.*d|\n", 5, 6);  
    printf("---------------------\n");
    // check : 
    // if len > precis
    //  return (precis) // 4 // Niko
	// : return (len) // 7 // Nikolas
    printf("%.4s\n", "Nikolas"); // Niko
    printf("%.4d\n", 1234567);   // 1234567
    printf("%7.4s\n", "Nikolas"); // Niko
    printf("%7.4d\n", 1234567);   // 1234567
    // check : 
    // if ( width - precis > 0 ) // 10 и 4
    //  putchar (' ')
    //  width = width - 1;
    // if ( width == precis )
    //  write (1, &c, 1);
    printf("%8s\n", "Nikolas");
    printf("%4.4s\n", "Nikolas"); // Niko

    printf("\n|%4.10s|\n", "Nikolas"); // Niko
    
    printf("\n%10.4s\n", "Nikolas"); // - - - - - - Niko
    printf("%10.4d\n", 1234567);   // - - - 1234567
	ft_printf("\nft_printf\n");
    ft_printf("Hello World!\n");
    ft_printf("test: %d %d\n", i, j);
}