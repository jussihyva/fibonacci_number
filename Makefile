# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/20 07:04:29 by ubuntu            #+#    #+#              #
#    Updated: 2020/05/26 01:07:54 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fib
CC				=	clang
C_FLAGS			=	-Wall -Werror -Wextra
INCLUDES		=	-I lib/lib_ft -I lib/lib_ftprintf
HEADERS			=	src/fib.h
LIB				=	-L lib/lib_ft -l ft -L lib/lib_ftprintf -l ftprintf

NAME_MAIN		=	src/fib.c
SRC_FOLDER		=	src
SRC				=	utils.c fib_iterative.c

OBJ_FOLDER		=	obj
OBJ				=	$(addprefix $(OBJ_FOLDER)/, $(patsubst %.c, %.o, $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(NAME_MAIN)
		@echo "$(NAME) created."
		@$(CC) $(C_FLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(NAME_MAIN) $(LIB)

$(OBJ): $(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c $(HEADERS) | $(OBJ_FOLDER)
		@echo "$(@) created."
		@$(CC) $(C_FLAGS) $(INCLUDES) -c -o $@ $<

$(OBJ_FOLDER):
		@mkdir $(OBJ_FOLDER)

.PHONY: all
