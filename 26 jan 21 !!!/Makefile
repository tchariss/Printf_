# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchariss <tchariss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 11:15:02 by tchariss          #+#    #+#              #
#    Updated: 2021/01/26 13:10:56 by tchariss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =  ft_printf.c ft_calloc.c parser.c parser_specifier.c \
			ft_strchr.c ft_putchar_len.c type_s.c type_c.c type_persent.c \
			ft_digit_strlen.c type_di.c ft_putnbr.c type_u.c type_xX.c \
			type_p.c ft_16_digit.c \

SRCO = $(SRC:.c=.o)

HEADER = ft_printf.h 

FLAGS = -Wall -Wextra -Werror

%.o: %.c 
	gcc $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCO)
	ar rcs $(NAME) $(SRCO)
	
clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re