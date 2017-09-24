# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dspyrydo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 17:57:29 by dspyrydo          #+#    #+#              #
#    Updated: 2017/09/11 20:59:36 by dspyrydo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT =     ./libft/libft.a 
OBJECTS =   ./main.o            \
            ./tools.o           \
			./validation.o		\
            ./validation2.o     \
            ./validation3.o     \
            ./algorithm.o       \
            ./ants.o 			\

.PHONY: libft

all: $(NAME)
$(NAME) : $(OBJECTS) libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
libft:
	make -C ./libft
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf $(OBJECTS)
	make clean -C ./libft
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
re: fclean all
