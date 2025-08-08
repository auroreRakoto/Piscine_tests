DIR_PATH="../exos/temp_C04/ex"

EX_FILES="${DIR_PATH}03/ft_atoi.c \
    ${DIR_PATH}04/ft_putnbr_base.c \
    ${DIR_PATH}05/ft_atoi_base.c"
TEST_FILES="test_ft_atoi.c \
    test_ft_putnbr_base.c \
    test_ft_atoi_base.c"

norminette ${EX_FILES}
#gcc -Wall -Wextra -Werror main.c assert.c ${EX_FILES} ${TEST_FILES} && ./a.exe
cc -Wall -Wextra -Werror main.c assert.c ${EX_FILES} ${TEST_FILES} && ./a.out
