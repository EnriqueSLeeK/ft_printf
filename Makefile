# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 18:37:43 by ensebast          #+#    #+#              #
#    Updated: 2021/09/12 12:03:44 by ensebast         ###   ########.br        #
#                                                                              #
# **************************************************************************** #

NAME:=libftprintf.a

CC:=gcc
CFLAGS:=-c -Wall -Werror -Wextra

LIBFT:=./libft/
LIBFT_L:=$(LIBFT)libft.a

LIB:=ar -rcs

RM:=rm -f

SRC:=./utils/
DST:=./dst/

RAW_FILE:=dot_flag.c find.c flag_process.c format_c.c\
	 format_d.c format_null.c format_p.c format_percent.c format_s.c\
	 format_u.c format_x.c minus_flag.c octo_flag.c plus_flag.c\
	 space_flag.c zero_flag.c free_and_next.c init.c width.c\
	 print_num.c check_diff.c count_digit.c printf.c

UTIL:= $(addprefix $(SRC), $(RAW_FILE))

#tmp
UTIL_OBJ:= $(UTIL:c=o)

$(SRC)%.o: $(SRC)%.c
	gcc -c $^ -o $@

%.o: %.c
	gcc -c $^ -o $@

$(NAME): ft_printf.h $(UTIL_OBJ)
	make -C $(LIBFT)
	cp $(LIBFT_L) $(NAME)
	$(LIB) $(NAME) $(UTIL_OBJ)

all: $(NAME)

bonus: all

clean:
	make clean -C $(LIBFT)
	$(RM) $(UTIL_OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

t: re
	gcc -g main.c libftprintf.a
	clear
	./a.out
	rm a.out
