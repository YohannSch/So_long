# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 08:19:55 by yscheupl          #+#    #+#              #
#    Updated: 2025/12/04 11:51:48 by yscheupl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g3
RM      := rm -rf

NAME    := so_long

SRCS    := so_long.c parsing/parsing.c parsing/parsing_utils.c parsing/parsing_utils2.c gnl/get_next_line.c gnl/get_next_line_utils.c game/game.c game/game2.c graphics/graphics.c

OBJS    := $(SRCS:.c=.o)

LIBFT_A := libft/libft.a
LIBFT_DIR := libft

all: $(LIBFT_A) $(NAME)
	make -C ./minilibx-linux
	
$(LIBFT_A) : $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -I./minilibx-linux/libmlx.a -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz $(LIBFT_A) -o $(NAME)


# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -I./minilibx-linux/libmlx.a -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $@ $(OBJS) $(LIBFT_A)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I./minilibx-linux/libmlx.a -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -c $< -o $@


clean:
	make -C libft/ fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re