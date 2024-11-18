NAME	= libft.a
FLAGS	= -Wall -Wextra -Werror
SRCS	= 	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcpy.c \
			ft_strlen.c ft_strncmp.c ft_strnstr.c ft_tolower.c \
			ft_toupper.c ft_atoi.c ft_strchr.c ft_strrchr.c \
			ft_strlcat.c ft_strdup.c ft_strjoin.c \
			ft_substr.c ft_calloc.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c \
			GNL/get_next_line_bonus.c GNL/get_next_line_utils_bonus.c \
			ft_printf/ft_printf.c ft_printf/pf_putchar.c ft_printf/pf_putstr.c \
			ft_printf/pf_puthex.c ft_printf/pf_putint.c ft_printf/pf_putuint.c \
			ft_printf/pf_putmem.c \
			ft_printf/debug.c

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
