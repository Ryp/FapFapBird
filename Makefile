NAME		=	FapFapBird

CXX		=	g++

CXXFLAGS	+=	-Wall -Wextra -pedantic -ansi -O

LDFLAGS		+=	$(LIBS) $(LPATH)

LIBS		=	-lsfml-graphics -lsfml-system -lsfml-window

LPATH		=

IPATH		=	-I./src

RM		=	rm -f

SRC		=	src/main.cpp					\
			src/Player.cpp					\
			src/PBox.cpp					\
			src/Joystick/AController.cpp			\
			src/Joystick/SfmlController.cpp			\

OBJ		=	$(SRC:.cpp=.o)

$(NAME):		$(OBJ)
			$(CXX) $(LDFLAGS) $(OBJ) -o $(NAME)

all:			$(NAME)

%.o:			%.cpp
			$(CXX) $(CXXFLAGS) $(IPATH) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:			clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
