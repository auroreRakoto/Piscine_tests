#DIR_PATH="../C02"
DIR_PATH="../../C02"
TEST_FILES="test_ft_strcpy.c \
    test_ft_strncpy.c \
    test_ft_str_is_alpha.c \
    test_ft_str_is_numeric \
    test_ft_str_is_lowercase.c \
    test_ft_str_is_uppercase.c \
    test_ft_str_is_printable.c"
EXO_FILES="${DIR_PATH}/ex00/ft_strcpy.c \
    ${DIR_PATH}/ex01/ft_strncpy.c"

#norminette ${DIR_PATH}/ex0*
#cc -Wall -Wextra -Werror main.c assert.c $EXO_FILES $TEST_FILES && ./a.out

gcc -Wall -Wextra -Werror main.c assert.c $EXO_FILES $TEST_FILES && ./a.exe
