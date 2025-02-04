NAME = pipex

# SOURCES AND OBJS
MAIN    =	pipex.c
SOURCES =	

SRCS_DIR = .
SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
MAIN_SRC = $(addprefix $(SRCS_DIR)/, $(MAIN))

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
OBJS_MAIN = $(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))

LIBFT = ./libft/libft.a

# BONUS STUFF
BONUS = 

SOURCES_BONUS =
SRCS_DIR_BONUS = bonus
SRCS_BONUS = $(addprefix $(SRCS_DIR_BONUS)/, $(SOURCES_BONUS))
OBJS_BONUS = $(addprefix $(OBJS_DIR)/, $(SOURCES_BONUS:.c=.o))

# COMPILATION STUFFS
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft -s

bonus: $(OBJS) $(LIBFT) $(OBJS_BONUS)
	@echo "Compiling $(NAME) bonus $(BONUS)..."
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR_BONUS)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing pipex OBJS"
	@rm -rf $(OBJS_DIR)
	@make clean -C ./libft -s

fclean: clean
	@echo "Removing $(NAME)"
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@echo "Removing libft.a"
	@rm -rf $(LIBFT)

re:	fclean all
	@echo "Re-Done!!"

.PHONY: all clean fclean re