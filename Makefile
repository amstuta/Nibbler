RM	= rm -f
CC	= g++

CFLAGS	= -fPIC -Wall -Wextra -Werror
CPPFLAGS= -rdynamic -fPIC -Wall -Wextra -Werror
LDLFLAGS= -ldl

NAME_E	= nibbler
NAME_L1	= libNDK.so
NAME_L2 = libQt.so
NAME_L3	= libSFML.so
NAME_L4 = libOpenGL.so

SRCS_E	= main.cpp \
	  loader.cpp \
	  snake.cpp \
	  board.cpp \
	  coord.cpp \
	  fruitgen.cpp \
	  fruit.cpp
SRCS_L1	= guiNDK.cpp
SRCS_L2 = guiQt.cpp
SRCS_L3	= guiSFML.cpp
SRCS_L4 = guiOpenGL.cpp

OBJS_E	= $(SRCS_E:.cpp=.o)
OBJS_L1	= $(SRCS_L1:.cpp=.o)
OBJS_L2	= $(SRCS_L2:.cpp=.o)
OBJS_L3	= $(SRCS_L3:.cpp=.o)
OBJS_L4 = $(SRCS_L4:.cpp=.o)

all:	$(NAME_E)  $(NAME_L3) $(NAME_L1) $(NAME_L4) #$(NAME_L2)

$(NAME_E): $(OBJS_E)
	   $(CC) -o $(NAME_E) $(OBJS_E) $(LDLFLAGS)

$(NAME_L1): $(OBJS_L1)
	    $(CC) -fPIC -c -o $(OBJS_L1) $(SRCS_L1)
	    $(CC) -shared -o $(NAME_L1) $(OBJS_L1) -lncurses

$(NAME_L2): $(OBJS_L2)
	    $(CC) -fPIC -c -o $(OBJS_L2) $(SRCS_L2)
	    $(CC) -shared -o $(NAME_L2) $(OBJS_L2)

$(NAME_L3): $(OBJS_L3)
	    $(CC) -shared $(OBJS_L3) -o $(NAME_L3) -lsfml-graphics -lsfml-window  -lsfml-system

$(NAME_L4): $(OBJS_L4)
	    $(CC) -fPIC -c -o $(OBJS_L4) $(SRCS_L4)
	    $(CC) -shared -o $(NAME_L4) $(OBJS_L4) -lSDL

clean:
	  $(RM) $(OBJS_E) $(OBJS_L1) $(OBJS_L2) $(OBJS_L3) $(OBJS_L4)

fclean:	  clean
	  $(RM) $(NAME_E) $(NAME_L1) $(NAME_L2) $(NAME_L3) $(NAME_L4)

re:	  fclean all

.PHONY:	  all clean fclean re
