NAME    = libmalloc.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -fPIC
AR      = ar rcs

SRCS    = malloc.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

test : all
	gcc  test.c -o test -L. -lmalloc

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test

re: fclean all