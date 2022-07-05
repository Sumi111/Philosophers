# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:10:34 by sfathima          #+#    #+#              #
#    Updated: 2022/06/30 13:28:56 by sfathima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRC_DIR = srcs
OBJ_DIR	= obj
INC_DIR	= include

SRCS = main.c routine.c init.c start.c utlis.c death.c fork.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%c=%o))

CC 		= gcc
CFLAG	= -g -Wall -Werror -Wextra
AR		= ar crs
RM		= rm -rf

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAG) -I $(INC_DIR) -c $< -o $@ 

all: $(NAME)

$(NAME):  $(LIB) $(OBJS) 
		@$(CC) $(CFLAG) $(OBJS) -o $@ -pthread
		

clean:
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
	