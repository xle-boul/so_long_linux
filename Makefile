# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 09:58:10 by xle-boul          #+#    #+#              #
#    Updated: 2022/03/19 15:08:18 by xle-boul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN	= \033[1;36m
RESET	= \033[0m
END		= \e[0m

NAME = so_long

NAME_BONUS = so_long_bonus

SRC_DIR := sources
SRC_DIR_BONUS := bonus
GNL_DIR := gnl

OBJ_DIR := obj
OBJ_DIR_BONUS := obj_bonus

COMMON_FILES := $(wildcard $(GNL_DIR)/*.c) sources/map_init.c so_long.c
SRC_FILES := $(wildcard $(SRC_DIR)/*.c) so_long.c $(wildcard $(GNL_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
SRC_BONUS := $(wildcard $(SRC_DIR_BONUS)/*.c) $(COMMON_FILES)
OBJ_BONUS := $(patsubst $(SRC_DIR_BONUS)/%.c,$(OBJ_DIR_BONUS)/%.o,$(SRC_BONUS))

CC = gcc
FLAGS = -Werror -Wall -Wextra
EXTRA_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/local/lib -Imlx_linux -lXext -lX11 -lm -lz

INCLUDES = includes

HEADER = includes/so_long.h
HEADER_GNL = includes/get_next_line.h
HEADER_BONUS = includes/so_long_bonus.h

LIB_DIR = ft_printf/
LIB_OBJS_DIR = ft_printf/objs/
LIB = libftprintf.a

OBJ_MLX = mlx_linux/obj/*.o
MLX_DIR = mlx_linux/
LIB_MLX = libmlx_Linux.a

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER) $(HEADER_GNL)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<

$(OBJ_DIR_BONUS)/%.o : $(SRC_DIR_BONUS)/%.c $(HEADER_BONUS) $(HEADER_GNL)
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ_FILES) $(LIB) $(LIB_MLX)
	@printf "\n$(YELLOW)Compiling so_long...$(END)\n"
	@$(CC) $(FLAGS) $(OBJ_MLX) $(EXTRA_FLAGS) $(OBJ_FILES) $(LIB) $(LIB_MLX) -I $(INCLUDES) -o $@
	@printf "\n$(GREEN)so_long compiled!\n$(END)Run program: $(RED)./so_long <maps/'map-name'.ber>\n$(END)"

$(NAME_BONUS): $(OBJ_BONUS) $(LIB) $(LIB_MLX)
	@printf "\n$(YELLOW)Compiling so_long_bonus...$(END)\n"
	@$(CC) $(FLAGS) $(OBJ_MLX) $(EXTRA_FLAGS) $(OBJ_BONUS) $(LIB) $(LIB_MLX) -I $(INCLUDES) -o $(NAME_BONUS)
	@printf "\n$(GREEN)so_long_bonus compiled!\n$(END)Run program: $(RED)./so_long_bonus <bonus/maps/'map-name'.ber>\n$(END)"

$(LIB):
	@printf "\n$(YELLOW)Compiling $(LIB)...$(END)\n"
	@make bonus --no-print-directory $(LIB) -C $(LIB_DIR)
	@mv $(LIB_DIR)$(LIB) .

$(LIB_MLX):
	@printf "\n$(YELLOW)Compiling $(LIB_MLX)...$(END)\n"
	@make --no-print-directory -C $(MLX_DIR)
	@mv $(MLX_DIR)$(LIB_MLX) .

all: $(NAME)

clean:
	@printf "\n$(YELLOW)Cleaning objects and $(NAME)...$(END)\n"
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "\n$(YELLOW)Cleaning $(LIB) and $(LIB_MLX)...$(END)\n"
	@rm -f $(LIB)
	@rm -f $(LIB_MLX)
	@make --no-print-directory -C $(LIB_DIR) fclean
	@make --no-print-directory -C $(MLX_DIR) clean

re: fclean $(NAME)

bonus: $(NAME_BONUS)

bonus_clean:
	@printf "\n$(YELLOW)Cleaning objects and $(NAME_BONUS)...$(END)\n"
	@rm -f $(NAME_BONUS)
	@rm -rf $(OBJ_DIR_BONUS)

bonus_fclean: bonus_clean
	@printf "\n$(YELLOW)Cleaning $(LIB) and $(LIB_MLX)...$(END)\n"
	@rm -rf $(LIB)
	@rm -f $(LIB_MLX)
	@make --no-print-directory -C $(LIB_DIR) fclean
	@make --no-print-directory -C $(MLX_DIR) clean
	
bonus_re: bonus_fclean bonus

norm:
	@norminette *.c sources bonus ft_printf includes

clean_all: fclean bonus_fclean

help:
	@printf "$(RED)Makefile rules:$(END)\n\n"
	@printf "$(CYAN)'make'$(END): \t\tCompile mandatory part\n"
	@printf "$(CYAN)'make clean'$(END): \t\tGet rid of mandatory objects and program\n"
	@printf "$(CYAN)'make fclean'$(END): \t\tGet rid of mandatory objects, program and libraries\n"
	@printf "$(CYAN)'make re'$(END): \t\tGet rid of everything and recompile mandatory part\n\n"
	@printf "$(MAGENTA)'make bonus'$(END): \t\tCompile bonus part\n"
	@printf "$(MAGENTA)'make bonus_clean'$(END): \tGet rid of bonus objects and program\n"
	@printf "$(MAGENTA)'make bonus_fclean'$(END): \tGet rid of bonus objects, program and libraries\n"
	@printf "$(MAGENTA)'make bonus_re'$(END): \tGet rid of everything and recompile bonus part\n\n"
	@printf "$(YELLOW)'make norm'$(END): \t\tCheck norminette\n"
	@printf "$(YELLOW)'clean_all'$(END): \t\tReset folder\n"

.PHONY: clean fclean bonus_re bonus_clean bonus_fclean re clean-all norm help