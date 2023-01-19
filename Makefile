# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lidzhang <lidzhang@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 12:28:45 by lidanzhang        #+#    #+#              #
#    Updated: 2023/01/19 09:56:00 by lidzhang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc

CFLAGS := -Wall -Wextra -Werror

RM := /bin/rm -f

NAME_SERVER := server
NAME_CLIENT := client

# =============================================================================
#	Processing files
# =============================================================================

SRC_SERVER := server.c minitalk.c
SRC_CLIENT := client.c minitalk.c

SRC_SERVER_BONUS := server_bonus.c minitalk_bonus.c
SRC_CLIENT_BONUS := client_bonus.c minitalk_bonus.c

INCLUDES := -I. -Ilibft

LIBFT := ./libft/libft.a
LIBFT_PATH := ./libft

# =============================================================================
#	RULES
# =============================================================================

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(LIBFT): $(shell make -C $(LIBFT_PATH) -q libft.a)
	make -C $(LIBFT_PATH)

clean:
	$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(LIBFT_PATH)/*.o

fclean: clean
	$(RM) $(LIBFT) 

re: fclean all

bonus: $(LIBFT) clean
	$(CC) $(CFLAGS) $(SRC_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) $(SRC_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT)

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus