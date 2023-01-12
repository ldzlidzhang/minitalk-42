# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lidanzhang <lidanzhang@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 16:03:48 by lidanzhang        #+#    #+#              #
#    Updated: 2022/12/15 17:19:10 by lidanzhang       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

OBJS		=	$(SRCS:.c=.o)

INCLUDE		=	libft.h get_next_line_bonus.h ft_printf.h

SRCS		=	ft_isdigit.c ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_strtrim.c \
				ft_atoi.c ft_isprint.c ft_memcpy.c ft_split.c ft_strlcpy.c ft_substr.c \
				ft_bzero.c ft_itoa.c ft_memmove.c ft_strchr.c ft_strlen.c ft_tolower.c \
				ft_calloc.c ft_memset.c ft_strcpy.c ft_strmapi.c ft_toupper.c \
				ft_isalnum.c ft_putchar_fd.c ft_strdup.c ft_strncmp.c \
				ft_isalpha.c ft_putendl_fd.c ft_striteri.c ft_strnstr.c	\
				ft_isascii.c ft_memchr.c ft_putnbr_fd.c ft_strjoin.c ft_strrchr.c \
				ft_lstadd_front.c ft_lstnew.c ft_lstadd_back.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstsize.c \
				get_next_line_bonus.c get_next_line_utils_bonus.c ft_printf.c \
				ft_print_unsigned.c ft_print_str.c ft_print_pointer.c ft_print_hex.c


CC			=	cc

RM			=	rm -fr

CFLAGES		=	-Wall -Wextra -Werror $(INCLUDE)

all:		$(NAME)

$(NAME):	$(OBJS)
					ar rcs $(NAME) $(OBJS)

clean:
					$(RM) $(OBJS)

fclean:		clean
					$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re 