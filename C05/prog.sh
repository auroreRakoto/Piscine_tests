#DIR_PATH="../exos/temp_C05/ex"
DIR_PATH="../ex"

EX_FILES="${DIR_PATH}01/ft_recursive_factorial.c \
    ${DIR_PATH}06/ft_is_prime.c \
    ${DIR_PATH}07/ft_find_next_prime.c \
    ${DIR_PATH}08/ft_ten_queens_puzzle.c"
TEST_FILES="test_ft_recursive_factorial.c \
    test_ft_is_prime.c \
    test_ft_find_next_prime.c \
    test_ft_ten_queens_puzzle.c"

norminette ${EX_FILES}
#gcc -Wall -Wextra -Werror main.c assert.c ${EX_FILES} ${TEST_FILES} && ./a.exe
cc -Wall -Wextra -Werror main.c assert.c ${EX_FILES} ${TEST_FILES} && ./a.out
