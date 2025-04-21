NAME = push_swap

INCLUDES = inc/
LIBFTPATH = $(INCLUDES)libft/
LIBFTA = $(LIBFTPATH)libft.a
PRINTFPATH = $(INCLUDES)ft_printf/
PRINTFA = $(PRINTFPATH)ft_printf.a

CFLAGS = -I$(INCLUDES) -Wall -Werror -Wextra -g
CC = cc

SRC_DIR = src/
SRC_NAME =	main.c \
			parsing_args.c \
			parsing_stack.c \
			utils.c \
			operations.c \
			sort.c \

OBJ_DIR = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(patsubst %, $(OBJ_DIR)%, $(OBJ_NAME))

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $< -c -o $@
	@echo "\033[1;36m Compiled" $(*F)


$(NAME): $(OBJ)
	@make --no-print-directory -C $(PRINTFPATH)
	@make --no-print-directory -C $(LIBFTPATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PRINTFA) $(LIBFTA)
	@echo "\033[1;32m Executable" $(NAME) "created"

clean:
	@make --no-print-directory -C $(PRINTFPATH)
	@make --no-print-directory -C $(LIBFTPATH)
	@rm -rf $(OBJ_DIR) $(PRINTFA) $(LIBFTA)
	@echo "\033[1;31m Deleted all object files"

fclean: clean
	@make --no-print-directory -C $(PRINTFPATH)
	@make --no-print-directory -C $(LIBFTPATH)
	@rm -f $(NAME)
	@echo "\033[1;31m Deleted $(NAME)"

all: $(NAME)

re: fclean all