#DIR_PATH="../C02"
DIR_PATH="../../C02"
TEST_FILES="test_ft_strcpy.c \
    test_ft_strncpy.c \
    test_ft_str_is_alpha.c \
    test_ft_str_is_numeric.c \
    test_ft_str_is_lowercase.c \
    test_ft_str_is_uppercase.c \
    test_ft_str_is_printable.c \
    test_ft_strupcase.c \
    test_ft_strlowcase.c \
    test_ft_strcapitalize.c \
    test_ft_strlcpy.c \
    test_ft_putstr_non_printable.c \
    test_ft_print_memory.c"
EXO_FILES="${DIR_PATH}/ex00/ft_strcpy.c \
    ${DIR_PATH}/ex01/ft_strncpy.c \
    ${DIR_PATH}/ex02/ft_str_is_alpha.c \
    ${DIR_PATH}/ex03/ft_str_is_numeric.c \
    ${DIR_PATH}/ex04/ft_str_is_lowercase.c \
    ${DIR_PATH}/ex05/ft_str_is_uppercase.c \
    ${DIR_PATH}/ex06/ft_str_is_printable.c \
    ${DIR_PATH}/ex07/ft_strupcase.c \
    ${DIR_PATH}/ex08/ft_strlowcase.c \
    ${DIR_PATH}/ex09/ft_strcapitalize.c \
    ${DIR_PATH}/ex10/ft_strlcpy.c \
    ${DIR_PATH}/ex11/ft_putstr_non_printable.c \
    ${DIR_PATH}/ex12/ft_print_memory.c"

norminette ${DIR_PATH}/ex{00..12}
#cc -Wall -Wextra -Werror main.c assert.c $EXO_FILES $TEST_FILES && ./a.out
cc main.c assert.c $TEST_FILES $EXO_FILES && ./a.out
#gcc -Wall -Wextra -Werror main.c assert.c $EXO_FILES $TEST_FILES && ./a.exe
