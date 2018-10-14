#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhovnir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 18:44:23 by mzhovnir          #+#    #+#              #
#    Updated: 2018/05/04 14:07:32 by lmatvien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SOURCES = validation.c main.c matrix_maker.c define_memory_area.c cleaner_memory.c \
cordinate_correction.c indexation_tools.c add_up_tools.c algorithm.c algorithm_tpart.c \
print_table.c


INCLUDES = fillit.h

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS)
	make re -C libft
	gcc -o $(NAME) $(OBJECTS) libft/libft.a

clean:
	make clean -C libft
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re