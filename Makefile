NAME    = runner-v2.out

SRC_DIR = src
OBJ_DIR = build
INC_DIR = include

SRCS    = $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS  = -Wall -Wextra -Werror -I$(INC_DIR)
LDFLAGS = -llapin -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lstdc++ -lm -lavcall

CC      = gcc
RM      = rm -vf

ifdef RELEASE
CFLAGS += -O2
endif

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

format:
	clang-format -i $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c $(INC_DIR)/*.h

.PHONY: all clean fclean re format
