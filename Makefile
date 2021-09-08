# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 18:37:43 by ensebast          #+#    #+#              #
#    Updated: 2021/09/08 17:45:08 by ensebast         ###   ########.br        #
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

RAW_FILE:= dec_to_hex.c dot_flag.c find.c flag_process.c format_c.c\
	 format_d.c format_null.c format_p.c format_percent.c format_s.c\
	 format_u.c format_x.c minus_flag.c octo_flag.c plus_flag.c\
	 space_flag.c zero_flag.c free_and_next.c

UTIL:= $(addprefix $(SRC), $(RAW_FILE))
PRINTF:=./printf.c

#tmp
UTIL_OBJ:=$(RAW_FILE:c=o)
PRINTF_OBJ:=$(PRINTF:c=o)

TMP:=$(UTIL_OBJ) $(PRINTF_OBJ)

#All obj
ALL_OBJ:=$(addprefix $(DST), $(TMP))

$(NAME): ft_printf.h $(UTIL) $(PRINTF)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(UTIL) $(PRINTF)
	mv $(UTIL_OBJ) $(PRINTF_OBJ) $(LIBFT_L) $(DST)
	$(LIB) $(NAME) $(ALL_OBJ)
	ranlib $(NAME)

all: $(NAME)

bonus: all

clean:
	make clean -C $(LIBFT)
	$(RM) $(ALL_OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(DST)libft.a

re: fclean all
