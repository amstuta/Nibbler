CC_E	= g++
CC_L	= gcc

CFLAGS	= -fPIC -Wall -Wextra -Werror
CXXFLAGS= -Wall -Wextra -Werror
LDLFLAGS= -ldl

RM	= rm -f

NAME_E	= nibbler
NAME_L	= libtest.so

SRCS_E	= main.cpp \
	  loader.cpp
SRCS_L	= test.c

OBJS_E	= $(SRCS_E:.cpp=.o)
OBJS_L	= $(SRCS_L:.c=.o)

all:	$(NAME_E) $(NAME_L)

$(NAME_E): $(OBJS_E)
	   $(CC_E) -o $(NAME_E) $(OBJS_E) $(LDLFLAGS)

$(NAME_L): $(OBJS_L)
	   $(CC_L) -shared -o $(NAME_L) $(OBJS_L)

clean:
	  $(RM) $(OBJS_E) $(OBJS_L)

fclean:	  clean
	  $(RM) $(NAME_E) $(NAME_L)

re:	  fclean all

.PHONY:	  all clean fclean re
