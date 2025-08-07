NAME="run_C04_tests"

DIR_PATH="../ex"

TEST_FILES="test_ft_*.c"

EX_FILES="${DIR_PATH}*/ft_*.c"

norminette ${EX_FILES}
cc -Wall -Wextra -Werror main.c ${TEST_FILES} ${EX_FILES} -o ${NAME} && ./${NAME}
