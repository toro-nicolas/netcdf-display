##
## SEAGNAL PROJECT, 2024
## netcdf-display
## File description:
## The main Makefile of our project
##

NAME		=	netcdf-display

CC		=	gcc

BUILDDIR 	=	./build
SRCDIR		=	./src

SRCS		=	$(shell find $(SRCDIR) -path ./tests -prune -o -type f -name "*.c" -print)

OBJS     	=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

CFLAGS		=	-Werror -Wextra -I./include/
DEBUGFLAGS	=	-g3 -DDEBUG_MODE
OPTIMIZEFLAGS	=	-O3

LDFLAGS 	=	-lnetcdf

.PHONY: all create-build debug clean fclean re color

all: create-build $(BUILDDIR) $(NAME)
	@echo -e "\033[1;33m$(NAME) compiled.\033[0m"

create-build:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS) -DCOLOR
debug: OPTIMIZEFLAGS =
debug: all

color: CFLAGS += -DCOLOR
color: all

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -rf $(BUILDDIR)
	@echo -e "\033[1;31mAll .o deleted.\033[0m"

fclean: clean
	@rm -rf vgcore*
	@rm -rf *.log
	@rm -rf $(NAME)
	@echo -e "\033[1;31mProject cleaned.\033[0m"

re:	fclean all

re_debug: fclean debug

re_color: fclean color

# Documentation
doc:
	@mkdir -p docs/html
	@doxygen Doxyfile
	@echo -e "\033[1;33mDocumentation generated.\033[0m"
	@google-chrome docs/html/index.html
