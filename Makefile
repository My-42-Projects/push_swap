NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Wextra -Werror


LIBFT_DIR	= libft
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

SRC =		$(SRC_DIR)/main.c $(SRC_DIR)/ $(SRC_DIR)/ $(SRC_DIR)/


OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT		= $(LIBFT_DIR)/libft.a

HEADERS		= -I$(INC_DIR) -I$(LIBFT_DIR)
LIBFT_MAKE	= $(MAKE) -C $(LIBFT_DIR)

all:	$(NAME)

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