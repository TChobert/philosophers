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
SRCS_DIR += ./sources/run_diner

# main #

MAIN += main.c

# parsing #

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

# run diner #

SRCS += diner_host.c
SRCS += host_set_the_table_for_the_diner.c
SRCS += host_get_diner_informations.c
SRCS += host_launch_the_diner.c

SRCS += update_last_meal_time.c

vpath %.c $(SRCS_DIR)

## SOURCES TESTS ##

TESTS_NAME := unit_tests

TESTS_SRCS_DIR += ./tests
TESTS_SRCS_DIR += ./tests/parsing
TESTS_SRCS_DIR += ./tests/diner

TESTS_SRCS += main_tests.c
TESTS_SRCS += tests_check_and_get_meals_number.c
TESTS_SRCS += tests_check_and_get_philos_number.c
TESTS_SRCS += test_host_get_diner_informations.c
TESTS_SRCS += test_host_set_the_table_for_the_diner.c

UNITY_SRC := Unity/src/unity.c

vpath %.c $(TESTS_SRCS_DIR)

## TESTS INCLUDES ##

TESTS_HEADERS := tests.h

TESTS_INCLUDES_DIR := ./tests/tests_includes

UNITY_HEADER := unity.HEADERS

UNITY_INCLUDES_DIR := ./Unity/src

## HEADERS ##

HEADERS := philosophers.h

INCLUDES_DIR := ./includes

vpath %.h $(INCLUDES_DIR)

## OBJECTS ##

OBJS_DIR := ./objs

OBJS += $(patsubst %.c, $(OBJS_DIR)/%.o, $(MAIN))
OBJS += $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

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
	$(CC) $(CFLAGS) -I $(TESTS_INCLUDES_DIR) -I $(INCLUDES_DIR) -I $(UNITY_INCLUDES_DIR) -o $(TESTS_NAME) $^

clean:
	@$(RM) -r $(OBJS_DIR)
	@echo "$(GREEN)Clean completed!$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(TESTS_NAME)
	@echo "$(GREEN)Full clean completed !$(RESET)"

re: fclean all

.PHONY: all clean fclean re tests
