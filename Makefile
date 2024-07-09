CFLAGS = -Wall -Wextra -Werror
NAME = bsq
HEADER_DIR = includes
HEADER_FILES = bsq.h
SRC_DIR = srcs
SRC_FILES = srcs/main.c srcs/reader.c

all: $(NAME)

$(NAME): $(SRC_FILES)
	cc $(CFLAGS) $(SRC_FILES) -o $(NAME)

fclean: 
	rm $(NAME)
