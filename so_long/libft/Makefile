# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esimsek <esimsek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 20:43:29 by esimsek           #+#    #+#              #
#    Updated: 2022/10/18 14:31:30 by esimsek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =	libft.a

SRCS        =	ft_atoi.c \
            	ft_bzero.c \
            	ft_isalpha.c \
            	ft_isdigit.c \
            	ft_isalnum.c \
            	ft_isascii.c \
            	ft_isprint.c \
            	ft_toupper.c \
            	ft_tolower.c \
            	ft_strncmp.c \
            	ft_memcmp.c \
            	ft_strlen.c \
            	ft_strlcpy.c \
            	ft_strlcat.c \
            	ft_strchr.c \
            	ft_strrchr.c \
            	ft_strnstr.c \
            	ft_memset.c \
            	ft_memcpy.c \
            	ft_memmove.c \
            	ft_memchr.c \
            	ft_strdup.c \
            	ft_calloc.c \
            	ft_substr.c \
            	ft_strjoin.c \
            	ft_strtrim.c \
            	ft_split.c \
            	ft_itoa.c \
            	ft_strmapi.c \
            	ft_striteri.c \
            	ft_putchar_fd.c \
            	ft_putstr_fd.c \
            	ft_putendl_fd.c \
            	ft_putnbr_fd.c \
				ft_lstnew.c \
              	ft_lstadd_front.c \
            	ft_lstsize.c \
            	ft_lstlast.c \
            	ft_lstadd_back.c \
            	ft_lstdelone.c \
            	ft_lstclear.c \
            	ft_lstiter.c \
            	ft_lstmap.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_printf.c \
				ft_printf_utils.c

CC          =	gcc

CFLAGS      =	-Wall -Wextra -Werror

INCLUDES = -I./headers

OBJS        =	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf *.o

fclean:	clean
	rm -rf $(NAME)
	
re:	fclean all

.PHONY: all clean fclean re
