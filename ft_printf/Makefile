# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rishiyam <rishiyam@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/03 19:39:42 by rishiyam          #+#    #+#              #
#    Updated: 2026/08/03 19:57:24 by rishiyam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

LIBFT_DIR   = ../libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDES    = -I./include -I$(LIBFT_DIR)

SRCS        = ft_printf.c print_char.c print_ptr.c print_str.c print_nbr.c \
              print_unbr.c print_hex.c
OBJS        = $(SRCS:.c=.o)

AR          = ar
ARFLAGS     = rcs

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
