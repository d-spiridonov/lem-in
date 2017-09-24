NAME = libft.a
FLAGS = -Wall -Wextra -Werror
OBJS = \
	        ./ft_memset.o       \
            ./ft_bzero.o        \
            ./ft_memcpy.o       \
            ./ft_memccpy.o      \
            ./ft_memmove.o      \
            ./ft_memchr.o       \
            ./ft_memcmp.o       \
            ./ft_strlen.o       \
            ./ft_strdup.o       \
            ./ft_strcpy.o       \
            ./ft_strncpy.o      \
            ./ft_strcat.o       \
            ./ft_strncat.o      \
            ./ft_strlcat.o      \
            ./ft_strchr.o       \
            ./ft_strrchr.o      \
            ./ft_strstr.o       \
            ./ft_strnstr.o      \
            ./ft_strcmp.o       \
            ./ft_strncmp.o      \
            ./ft_atoi.o         \
            ./ft_isalpha.o      \
            ./ft_isdigit.o      \
            ./ft_isalnum.o      \
            ./ft_isascii.o      \
            ./ft_isprint.o      \
            ./ft_toupper.o      \
            ./ft_tolower.o      \
            ./ft_memalloc.o 	\
            ./ft_memdel.o 		\
            ./ft_strnew.o 		\
            ./ft_strdel.o 		\
            ./ft_strclr.o 		\
            ./ft_striter.o 		\
            ./ft_striteri.o 	\
            ./ft_strmap.o 		\
            ./ft_strmapi.o 		\
            ./ft_strequ.o 		\
            ./ft_strnequ.o 		\
            ./ft_strsub.o  		\
            ./ft_strjoin.o  	\
            ./ft_strtrim.o  	\
            ./ft_strsplit.o 	\
            ./ft_itoa.o  		\
            ./ft_putchar.o  	\
            ./ft_putstr.o 		\
            ./ft_putendl.o		\
            ./ft_putnbr.o  		\
            ./ft_putchar_fd.o 	\
            ./ft_putstr_fd.o 	\
            ./ft_putendl_fd.o 	\
            ./ft_putnbr_fd.o 	\
            ./ft_countwords.o 	\
            ./ft_countdigits.o 	\
            ./ft_lstnew.o 		\
            ./ft_lstdelone.o 	\
            ./ft_lstdel.o 		\
            ./ft_lstadd.o 		\
            ./ft_lstiter.o  	\
            ./ft_lstmap.o 		\
            pf_ft_printf.o 		\
			pf_flags_1.o 		\
			pf_ft_itoa_base.o 	\
			pf_flags_2.o 		\
			pf_functions_2.o 	\
			pf_functions_1.o 	\
			pf_modifiers.o 		\
			pf_types_1.o 		\
			pf_types_2.o 		\
			pf_functions_3.o 	\
			pf_functions_4.o 	\
			pf_functions_5.o    \
			pf_functions_p.o 	\
			pf_ft_putchar_pf.o  \
			pf_ft_putstr_pf.o   \
			pf_wchar_functions.o\
			get_next_line.o 	\

all : $(NAME)
$(NAME) : $(OBJS)
	ar rvs $(NAME) $(OBJS)
	ranlib $(NAME)
%.o : %.c
	gcc $(FLAGS) -o $@ -c $< $(INCLUDES)
clean:
	rm -f $(OBJS)
	rm -f *.c~
fclean: clean
	rm -rf $(NAME)
re: flcean all