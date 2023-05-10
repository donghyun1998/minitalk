# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghyk2 <donghyk2@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 14:43:35 by donghyk2          #+#    #+#              #
#    Updated: 2023/02/27 21:00:39 by donghyk2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_NAME			= server
C_NAME			= client

CC				= @cc
CFLAGS			= -Wall -Werror -Wextra
LIBFT			= -Lsrc/libft -lft
MAN_DIR			= mandatory/
BONUS_DIR		= bonus/

S_SRC			= server.c
C_SRC			= client.c
BONUS_S_SRC		= server_bonus.c
BONUS_C_SRC		= client_bonus.c

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

S_OBJS			= $(addprefix $(MAN_DIR), $(S_SRC:.c=.o))
C_OBJS			= $(addprefix $(MAN_DIR), $(C_SRC:.c=.o))
BONUS_S_OBJS	= $(addprefix $(BONUS_DIR), $(BONUS_S_SRC:.c=.o))
BONUS_C_OBJS	= $(addprefix $(BONUS_DIR), $(BONUS_C_SRC:.c=.o))


ifdef BONUS_ON
    REAL_S_OBJS = $(BONUS_S_OBJS)
	REAL_C_OBJS = $(BONUS_C_OBJS)
else
    REAL_S_OBJS = $(S_OBJS)
	REAL_C_OBJS = $(C_OBJS)
endif

all: $(S_NAME) $(C_NAME)

bonus:
	@make BONUS_ON=1

$(C_NAME): $(REAL_C_OBJS)
	@make -sC src/libft all
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

$(S_NAME): $(REAL_S_OBJS)
	@make -sC src/libft all
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

clean:
	@make -C src/libft clean
	@rm -f $(S_OBJS) $(C_OBJS)
	@rm -f $(BONUS_S_OBJS) $(BONUS_C_OBJS)

fclean:
	@make -C src/libft fclean
	@make clean
	@rm -f $(S_NAME) $(C_NAME)

re:
	@make fclean
	@make all

.PHONY: all clean fclean re bonus
