RED=\033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[1;38;5;214m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

NAME = pipex

# SOURCES AND OBJS
MAIN    =	pipex.c
SOURCES =	utils.c cleaners.c

# Includes
INCLUDE = include
INCLUDE_FLAGS = -I$(INCLUDE)
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(SOURCES))
MAIN_SRC = $(addprefix ./, $(MAIN))

OBJS_DIR = build
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
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS_MAIN) $(OBJS) $(LIBFT)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS_MAIN) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_FLAGS)

$(OBJS_MAIN): $(MAIN_SRC) | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_FLAGS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@make -C ./libft -s

bonus: $(OBJS) $(LIBFT) $(OBJS_BONUS)
	@echo "Compiling $(NAME) bonus $(BONUS)..."
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT)

$(OBJS_DIR)/%.o: $(SRCS_DIR_BONUS)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing objects$(RESET)"
	@rm -rf $(OBJS_DIR)
	@make clean -C ./libft -s

fclean: clean
	@echo "$(RED)Removing $(NAME)$(RESET)"
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@echo "$(RED)Removing Libft$(RESET)"
	@rm -rf $(LIBFT)

re:	fclean all
	@echo "$(ORANGE)Re-Done!!$(RESET)"

.PHONY: all clean fclean re