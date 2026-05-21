NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes
SRCS = src/main.c \
       src/load_file.c \
       src/dict.c \
       src/normalize.c \
       src/convert.c \
       src/convert_group.c \
       src/dict_utils.c \
       src/dict_line.c \
       src/words_buffer.c \
       src/words_helpers.c \
       src/str_utils.c \
       src/output.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
