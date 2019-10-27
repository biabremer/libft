# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bbremer <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/20 14:55:57 by bbremer        #+#    #+#                 #
#    Updated: 2019/10/27 13:55:55 by bbremer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ==== Editable ====
NAME:= libft.a

FILES:= ft_memdup ft_sqrt ft_print_params ft_lstpushback\
	  ft_countwords ft_memset ft_bzero ft_memcpy ft_memccpy\
	  ft_memmove ft_memchr ft_memcmp ft_strlen ft_strdup\
	  ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat\
	  ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp\
	  ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum\
	  ft_isascii ft_isprint ft_toupper ft_tolower ft_memalloc\
	  ft_memdel ft_strnew ft_strdel ft_strclr ft_striter\
	  ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ\
	  ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_itoa\
	  ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd\
	  ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew\
	  ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap\
	  ft_isspace ft_intlen get_next_line

# ==================

# ==== Standard ====
CC:=clang
CCHPATH:=obj/
SRCPATH:=src/
HDRPATH:=include/
CFLAGS:=-Wall -Wextra -Werror -I $(HDRPATH)
# ==================

# ===== Colors =====
END:="\033[0;0m"
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
# ==================

# ====== Auto ======
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(END)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) " - Done" $(END)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo ".\c"
	@$(CC) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED) "Missing file : $@"

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

.PHONY: all clean fclean re
