# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 11:21:04 by kfujita           #+#    #+#              #
#    Updated: 2023/04/09 11:26:31 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC_DIR	=	./srcs

SRCS	=\
	error_messages.c \
	ft_endwith.c \
	main.c \
	read_input.c \

OBJ_DIR	=	./obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

DEPS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.d))

LIBFT_DIR	=	./libft
LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	make -C $(LIBFT_DIR)

MLX_DIR	=	minilibx-linux
MLX_FNAME	=	libmlx.a
MLX	=	$(MLX_DIR)/$(MLX_FNAME)
MLX_MAKE	=	make -C $(MLX_DIR)

override CFLAGS	+=	-Wall -Wextra -Werror -MMD -MP
INCLUDES	=	 -I ./headers -I $(LIBFT_DIR) -I $(MLX_DIR)

CC		=	cc

all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) -lm $(INCLUDES) -o $@ $^

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	$(LIBFT_MAKE)

$(MLX):
	$(MLX_MAKE)

bonus:
	@make

debug: fclean_local
	make CFLAGS=-DDEBUG

clean_local:
	rm -f $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS)
	rm -d $(OBJ_DIR) || exit 0

fclean_local: clean_local
	rm -f $(NAME)

clean: clean_local
	$(LIBFT_MAKE) clean
	$(MLX_MAKE) clean

fclean:	fclean_local
	$(LIBFT_MAKE) fclean
	$(MLX_MAKE) clean

re:	fclean all

-include $(DEPS) $(DEPS_BONUS)

.PHONY:	clean_local MAKE_BEFORE bonus debug
