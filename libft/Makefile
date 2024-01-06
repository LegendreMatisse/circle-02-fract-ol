NAME = libft.a

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	  ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	  ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	  ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	  ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_hexconvert.c \
	  ft_printf.c ft_printnbr.c ft_printptr.c \
	  ft_printstr.c get_next_line_bonus.c \
	  get_next_line_utils_bonus.c ft_uitoa.c

BONUSSOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	       ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	       ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SOURCES:.c=.o}

BONUSOBJS = ${BONUSSOURCES:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

ARFLAGS = -c -r -s

RMF = rm -rf

RAND		=	$(shell shuf -i 100-231 -n 1)
RAND2		=	$(shell shuf -i 100-105 -n 1)

GREEN		=	\e[$(call RAND2)m\e[K\e[1;4;6;38:5:$(call RAND)m
YELLOW		=	\e[$(call RAND2)m\e[K\e[1;4;6;38:5:$(call RAND)m
RESET		=	\033[0m

#GREEN		=	\e[0;32m
#YELLOW		=	\e[0;33m
#RESET		=	\033[0m

.c.o:
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} >/dev/null 2>&1

${NAME}: ${OBJS}
	@echo "$(YELLOW)Creating libft archive...$(RESET)"
	@ar ${ARFLAGS} ${NAME} ${OBJS} >/dev/null 2>&1
	@echo "$(GREEN)libft.a is ready for use.$(RESET)"

all:	${NAME}

bonus: ${OBJS} ${BONUSOBJS}
	@echo "$(YELLOW)Creating archive with bonus...$(RESET)"
	@ar ${ARFLAGS} ${NAME} ${OBJS} ${BONUSOBJS} >/dev/null 2>&1
	@echo "$(GREEN)libft.a with bonus is ready for use.$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning all .o files in libft...$(RESET)"
	@${RMF} ${OBJS} ${BONUSOBJS} >/dev/null 2>&1
	@echo "$(GREEN)No more .o files in libft.$(RESET)"

fclean: clean
	@echo "$(YELLOW)Cleaning all .a files in libft...$(RESET)"
	@${RMF} ${NAME} >/dev/null 2>&1
	@echo "$(GREEN)No more .a files in libft$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
