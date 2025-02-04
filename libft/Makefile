NAME = libft.a

C_SOURCE = ft_bzero.c ft_atoi.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memset.c ft_strlen.c ft_strncmp.c ft_tolower.c ft_toupper.c \
ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strdup.c \
ft_memmove.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c ft_putchar.c ft_putstr.c ft_printnbr.c ft_itoh.c ft_printunbr.c ft_printptr.c \
ft_printf.c

BONUS_SOURCE = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

H_SOURCE = ./

OBJ = $(C_SOURCE:.c=.o)

OBJ_BONUS = $(BONUS_SOURCE:.c=.o)

CC = cc

CC_FLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

%.o: %.c
	@$(CC) $(CC_FLAGS) -I $(H_SOURCE) -c $< -o $@

bonus: $(OBJ_BONUS)
	@ar rcs $(NAME) $^
	@touch bonus

clean:
	$(RM) $(OBJ) $(OBJ_BONUS) bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

