CC	= g++

CFLAGS	= -fPIC -Wall -Wextra -Werror
CPPFLAGS= -Wall -Wextra -Werror
LDLFLAGS= -ldl

RM	= rm -f

NAME_E	= nibbler
NAME_L1	= libGTK.so
NAME_L2 = libQt.so

SRCS_E	= main.cpp \
	  loader.cpp
SRCS_L1	= guiGTK.cpp
SRCS_L2 = guiQt.cpp

OBJS_E	= $(SRCS_E:.cpp=.o)
OBJS_L1	= $(SRCS_L1:.cpp=.o)
OBJS_L2	= $(SRCS_L2:.cpp=.o)

all:	$(NAME_E) $(NAME_L1) $(NAME_L2)

$(NAME_E): $(OBJS_E)
	   $(CC) -o $(NAME_E) $(OBJS_E) $(LDLFLAGS)

$(NAME_L1): $(OBJS_L1)
	    $(CC) -fPIC -c -o $(OBJS_L1) $(SRCS_L1)
	    $(CC) -shared -o $(NAME_L1) $(OBJS_L1)

$(NAME_L2): $(OBJS_L2)
	    $(CC) -fPIC -c -o $(OBJS_L2) $(SRCS_L2)
	    $(CC) -shared -o $(NAME_L2) $(OBJS_L2)

clean:
	  $(RM) $(OBJS_E) $(OBJS_L1) $(OBJS_L2)

fclean:	  clean
	  $(RM) $(NAME_E) $(NAME_L1) $(NAME_L2)

re:	  fclean all

.PHONY:	  all clean fclean re
