# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 17:23:32 by mlegendr          #+#    #+#              #
#    Updated: 2023/12/18 17:10:54 by mlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
LIBRARY		=	fractol.a

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g
AR			=	ar rcs
RM			=	rm -rf

SRCS		=	utils.c mlx_functions.c drawing_utils.c \
				fractol.c mandelbrot.c julia.c

OBJ_DIR		=	obj
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH	=	./libft
LIBFT		=	$(LIBFT_PATH)/libft.a

MLX_PATH	=	minilibx-linux/
MLX_NAME	=	libmlx_Linux.a
MLX			=	$(MLX_PATH)$(MLX_NAME)

#RAND		=	$(shell shuf -i 100-231 -n 1)
#RAND2		=	$(shell shuf -i 100-105 -n 1)

#GREEN		=	\e[$(call RAND2)m\e[K\e[1;4;6;38:5:$(call RAND)m
#YELLOW		=	\e[$(call RAND2)m\e[K\e[1;4;6;38:5:$(call RAND)m
#RESET		=	\033[0m

GREEN		=	\e[0;32m
YELLOW		=	\e[0;33m
RESET		=	\033[0m

$(OBJ_DIR)/%.o:	%.c
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "$(YELLOW)Compiling $<...$(RESET)"

all:		$(NAME)

$(MLX):		
			@echo "$(YELLOW)Compiling minilibx...$(RESET)"
			@make -C $(MLX_PATH) all  >/dev/null 2>&1
			@echo "$(GREEN)Minilibx is ready.$(RESET)"

$(NAME):	$(LIBFT) $(MLX) $(OBJ_DIR) $(OBJS)
			@echo "$(YELLOW)Creating $(LIBRARY) archive...$(RESET)"
			@cp $(LIBFT) ./ >/dev/null 2>&1
			@cp $(MLX) ./ >/dev/null 2>&1
			@$(AR) $(LIBRARY) $(OBJS) >/dev/null 2>&1
			@echo "$(YELLOW)Linking $(NAME) executable...$(RESET)"
			@$(CC) -o $(NAME) $(LIBRARY) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
			@echo "$(GREEN)$(NAME) is ready.$(RESET)"

$(LIBFT):
			@make -sC $(LIBFT_PATH) all
			@echo "$(YELLOW)Building libft...$(RESET)"

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)
			@echo "$(YELLOW)Creating the objects directory...$(RESET)"

clean:
			@make -C $(LIBFT_PATH) clean >/dev/null 2>&1
			@make -C $(MLX_PATH) clean >/dev/null 2>&1
			@$(RM) $(OBJ_DIR) >/dev/null 2>&1
			@$(RM) *.0 >/dev/null 2>&1
			@echo "$(YELLOW)Cleaning all .o files.$(RESET)"

fclean:		clean
			@make -C $(LIBFT_PATH) fclean >/dev/null 2>&1
			@$(RM) $(LIBRARY) >/dev/null 2>&1
			@$(RM) $(NAME) >/dev/null 2>&1
			@$(RM) *.a >/dev/null 2>&1
			@echo "$(YELLOW)Cleaning all .a files.$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re
