RED=\033[1;31m
YELLOW = \033[1;33m
ORANGE = \033[1;38;5;214m
GREEN = \033[1;32m
CYAN = \033[1;36m
RESET = \033[0m

NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
OBJDIR = build
INCLUDES = include/
INCLUDES_FLAGS = -I$(INCLUDES)

SRC = src
MAIN = main
PROGRAM_NAME = run

# Tests
TEST_SRC =
TEST_OBJDIR = $(OBJDIR)/tests
TEST_FLAGS = -L. -lft -lcmocka -lbsd

SRC_CHECK =	ft_check/ft_isalnum.c ft_check/ft_isalpha.c ft_check/ft_isascii.c \
			ft_check/ft_isdigit.c ft_check/ft_isprint.c ft_check/ft_toupper.c  \
			ft_check/ft_tolower.c
SRC_FD =	ft_fds/ft_putchar_fd.c ft_fds/ft_putstr_fd.c ft_fds/ft_putnbr_fd.c \
			ft_fds/ft_putendl_fd.c
SRC_LISTS =	ft_list/ft_lstadd_back_bonus.c ft_list/ft_lstadd_front_bonus.c \
			ft_list/ft_lstclear_bonus.c ft_list/ft_lstdelone_bonus.c \
			ft_list/ft_lstlast_bonus.c ft_list/ft_lstmap_bonus.c ft_list/ft_lstnew_bonus.c \
			ft_list/ft_lstsize_bonus.c ft_list/ft_lstiter_bonus.c
SRC_MEM =	ft_memory/ft_memchr.c ft_memory/ft_memcmp.c ft_memory/ft_memcpy.c \
			ft_memory/ft_calloc.c ft_memory/ft_memmove.c ft_memory/ft_memset.c \
			ft_memory/ft_bzero.c
SRC_NUM =	ft_num/ft_atoi.c
SRC_STR =	ft_strings/ft_split.c ft_strings/ft_strchr.c \
			ft_strings/ft_strdup.c ft_strings/ft_striteri.c ft_strings/ft_strjoin.c \
			ft_strings/ft_strlcat.c ft_strings/ft_strlcpy.c ft_strings/ft_strlen.c  \
			ft_strings/ft_strmapi.c ft_strings/ft_strncmp.c ft_strings/ft_strnstr.c \
			ft_strings/ft_strrchr.c ft_strings/ft_strtrim.c ft_strings/ft_substr.c \

PRINTF =	ft_printf/ft_putchar.c ft_printf/ft_putstr.c ft_printf/ft_printnbr.c ft_printf/ft_itoh.c ft_printf/ft_printunbr.c ft_printf/ft_printptr.c \
			ft_printf/ft_printf.c

SRC_GNL =	gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS_DIR =	$(addprefix $(SRC)/, $(PRINTF)) \
			$(addprefix $(SRC)/, $(SRC_GNL)) \
			$(addprefix $(SRC)/, $(SRC_STR)) \
			$(addprefix $(SRC)/, $(SRC_CHECK)) \
			$(addprefix $(SRC)/, $(SRC_LISTS)) \
			$(addprefix $(SRC)/, $(SRC_MEM)) \
			$(addprefix $(SRC)/, $(SRC_NUM)) \
			$(addprefix $(SRC)/, $(SRC_FD)) \

OBJS_DIR =	$(addprefix $(OBJDIR)/, $(PRINTF:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_GNL:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_STR:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_CHECK:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_LISTS:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_MEM:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_NUM:.c=.o)) \
			$(addprefix $(OBJDIR)/, $(SRC_FD:.c=.o)) \

all: $(NAME)

$(NAME): $(OBJS_DIR)
	@echo "$(YELLOW)Building Libft$(RESET)"
	@ar rcs $(NAME) $(OBJS_DIR)
	@echo "$(GREEN)Done!$(RESET)"


$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_FLAGS)


clean:
	@rm -rf $(OBJDIR)

debug: CFLAGS += -g
debug: re

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug