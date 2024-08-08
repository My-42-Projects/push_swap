NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = libft
SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= inc

SRC = 	$(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/free.c $(SRC_DIR)/checks.c \
		$(SRC_DIR)/push.c $(SRC_DIR)/rotate.c $(SRC_DIR)/swap.c $(SRC_DIR)/error.c \
		$(SRC_DIR)/ps_utils.c $(SRC_DIR)/push_swap.c $(SRC_DIR)/quicksort.c \
		$(SRC_DIR)/sorting.c $(SRC_DIR)/sorting_utils.c $(SRC_DIR)/get_links.c


OBJ	= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_DIR)/libft.a

HEADERS	= -I$(INC_DIR) -I$(LIBFT_DIR)
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIBFT_MAKE)
	$(CC) $(CFLAGS) $(OBJ) $(HEADERS) $(LIBFT_DIR)/libft.a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re