#DIR_PATH="../../temp_C03/"
DIR_PATH="../exos/temp_C03/"
TEST_PATH="test_ft_"

TEST_FILES="test_ft_strcmp.c \
	test_ft_strncmp.c \
	test_ft_strcat.c \
	test_ft_strncat.c \
	test_ft_strstr.c \
	test_ft_strlcat.c"

EX_FILES="${DIR_PATH}ex*/*.c"

#cc -Wall -Wextra -Werror -lbsd main.c ${TEST_FILES} ${EX_FILES} -o testing ./testing.exe
gcc -Wall -Wextra -Werror main.c assert.c ${TEST_FILES} ${EX_FILES} -o testing && ./testing.exe
#gcc main.c assert.c ${TEST_FILES} ${EX_FILES} -o testing && ./testing.exe && echo "NO FLAG"
