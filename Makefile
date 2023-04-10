NAME = push_swap

FLAGS = -Wall -Wextra -Werror

CC = gcc

SRC_DIR = srcs
ACTION_DIR = actions

SRC = $(SRC_DIR)/algorithm.c \
		$(SRC_DIR)/algorithm2.c \
		$(SRC_DIR)/build_stack.c \
		$(SRC_DIR)/ft_split.c \
		$(SRC_DIR)/parsing.c \
		$(SRC_DIR)/toolbox.c \
		$(SRC_DIR)/toolbox2.c \
		$(ACTION_DIR)/pa_pb.c \
		$(ACTION_DIR)/ra_rb_rr.c \
		$(ACTION_DIR)/rra_rrb_rrr.c \
		$(ACTION_DIR)/sa_sb_ss.c \
		push_swap.c

SRC_OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(SRC_OBJ)

$(SRC_OBJ): %.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
