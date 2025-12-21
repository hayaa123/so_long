NAME = so_long
CC= cc
CFLAGS= -Wall -Werror -Wextra -I libft -I includes -Imlx
DEBUGFLAG= -g

LIBFT_DIR= ./libft
LIBFT= ./libft/libft.a

MLX_DIR= ./mlx_linux
MLX=./mlx_linux/libmlx_Linux.a

SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
BIN_DIR=bin
LIB =$(LIB_DIR)/so_long.a

SRC = \
map_validation.c main.c map_initialization.c read_as_line.c check_valid_path.c\
game.c player_move.c rendering.c exit_game.c map_initialization_utils.c check_valid_path_utils.c\
positions.c safe_free.c game_utils.c\

LIBFT_SRC = \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_toupper.c ft_tolower.c \
ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
print_string.c print_pointer.c print_number.c print_unsigned.c print_hexa.c ft_printf.c\

LIBFT_OBJ := $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC:.c=.o))
OBJ         = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

debug: $(LIB) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(DEBUGFLAG) -L. $(LIB) -I./libft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(NAME): $(LIB) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -L. $(LIB) -I./libft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MLX): 
	make -C $(MLX_DIR)

$(LIB): $(OBJ) $(LIBFT)
	mkdir -p $(LIB_DIR)
	cp $(LIBFT) $(LIB)
	ar rcs $(LIB) $(LIBFT_OBJ) $(OBJ)

$(LIBFT): $(LIBFT_OBJ)
	make -C $(LIBFT_DIR)

clean:
	rm -f $(LIBFT_OBJ) $(OBJ) $(LIB)
	rm -rf $(OBJ_DIR)
	rm -rf $(LIB_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean all debug