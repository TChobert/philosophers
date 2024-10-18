##### VARIABLES #####

## COLORS ##

GREEN =\033[0;32m
YELLOW =\033[0;33m
RESET =\033[0m

## TARGET ##

NAME := philo

## COMPILATION ##

CC := cc

CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

ifeq ($(d), 1)
		CFLAGS += -g3
endif

ifeq ($(d), 2)
		CFLAGS += -fsanitize=address,undefined -g3
endif

ifeq ($(d), 3)
		CC = clang
		CFLAGS = Weverything
endif

## SOURCES ##

SRCS_DIR += ./sources
SRCS_DIR += ./sources/parsing

# parsing #

SRCS += main.c
SRCS += arguments_parser.c
SRCS += arguments_parser_utils.c
SRCS += check_and_get_philos_number.c
SRCS += check_and_get_time_to_die.c
SRCS += check_and_get_time_to_eat.c
SRCS += check_and_get_time_to_sleep.c
SRCS += check_and_get_number_of_meals.c
SRCS += errors_displaying.c
SRCS += errors_displaying_utils.c
SRCS += errors_messages.c
SRCS += ft_atol.c

vpath %.c $(SRCS_DIR)

## SOURCES TESTS ##

TESTS_SRCS_DIR += ./tests/parsing

TESTS_SRCS += tests_parsing.c

UNITY_SRC := Unity/src/unity.c

vpath %.c $(TESTS_SRCS_DIR)

## TESTS INCLUDES ##

TESTS_INCLUDES := Unity/src

## HEADERS ##

HEADERS := philosophers.h

INCLUDES_DIR := ./includes

vpath %.h $(INCLUDES_DIR)

## OBJECTS ##

OBJS_DIR := ./objs

OBJS := $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

##### RULES #####

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) $(OBJS) -o $@
	@echo "$(GREEN)philo_compiled!$(RESET)"

$(OBJS): $(OBJS_DIR)/%.o: %.c $(HEADERS) | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@
	@echo "$(YELLOW)Making object $@$(RESET)"

$(OBJS_DIR):
	@mkdir $@

tests: $(TESTS_SRCS) $(SRCS) $(UNITY_SRC)
	$(CC) $(CFLAGS) -I $(TESTS_INCLUDES) -I $(INCLUDES) -o tests_unit $^

clean:
	@$(RM) -r $(OBJS_DIR)
	@echo "$(GREEN)Clean completed!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)Full clean completed !$(RESET)"

re: fclean all

.PHONY: all clean fclean re tests
