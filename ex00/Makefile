# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 21:22:03 by vkhrabro          #+#    #+#              #
#    Updated: 2024/09/11 18:27:17 by vkhrabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
DEPFLAGS = -MMD -MP

NAME = Bureaucrat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re