NAME    = libmalloc.so
CC      = cc
CFLAGS  = -fPIC -shared
SRCS    = malloc.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -g -o $@ $^

test : all
	export LD_LIBRARY_PATH="$PWD"
	gcc  test.c -o test -L. -lmalloc -g 
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test

re: fclean all

.PHONY: all clean fclean re test
