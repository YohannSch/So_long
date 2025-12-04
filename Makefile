# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 08:19:55 by yscheupl          #+#    #+#              #
#    Updated: 2025/12/04 08:22:25 by yscheupl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g3
RM      := rm -rf

NAME    := so_long

SRCS    := 

OBJS    := $(SRCS:.c=.o)

LIBFT_A := libft/libft.a
LIBFT_DIR := libft

all: $(LIBFT_A) $(NAME)
	make -C ./minilibx-linux
$(LIBFT_A) : $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT_A)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	make -C libft/ fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re