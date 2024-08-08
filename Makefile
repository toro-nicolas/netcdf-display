##
## SEAGNAL PROJECT, 2024
## netcdf-display
## File description:
## The main Makefile of our project
##

NAME		=	netcdf-display

CC		=	g++
DEBUG_MODE	=

BUILDDIR 	=	./build
SRCDIR		=	./src

SRCS		=	$(shell find . -path ./tests -prune -o -type f -name "*.c" -print)

OBJS     	=	$(addprefix $(BUILDDIR)/, $(notdir $(SRCS:.c=.o)))

CFLAGS		=	-Werror -Wextra -I./include/
DEBUGFLAGS	=	-g3
OPTIMIZEFLAGS	=	-O3

LDFLAGS 	=	-lnetcdf #-lhdf5

.PHONY: all create-build debug clean fclean re

all: create-build $(BUILDDIR) $(NAME)
	@echo -e "\033[1;33m$(NAME) compiled.\033[0m"

create-build:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -c $< -o $@

debug: CFLAGS += $(DEBUGFLAGS)
debug: OPTIMIZEFLAGS =
debug: DEBUG_MODE = debug
debug: all

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(OPTIMIZEFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -rf $(BUILDDIR)
	@echo -e "\033[1;31mAll .o deleted.\033[0m"

fclean:
	@rm -rf vgcore*
	@rm -rf *.log
	@rm -rf $(NAME)
	@echo -e "\033[1;31mProject cleaned.\033[0m"

re:	fclean all

re_debug: fclean debug

valgrind: fclean debug
	@echo -e "\033[0;36mExecuting valgrind...\033[0m"
	@valgrind $(VALGRINDFLAGS) ./$(NAME) 2> $(OUTPUT)

# Documentation
doc:
	@mkdir -p docs/html
	@doxygen Doxyfile
	@echo -e "\033[1;33mDocumentation generated.\033[0m"
	@google-chrome docs/html/index.html
