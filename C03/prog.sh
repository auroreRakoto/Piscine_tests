DIR_PATH="../../C03/ex"
TEST_PATH="test_ft_"

TEST_FILES="assert.c \
	${TEST_PATH}strcmp.c \
	${TEST_PATH}strncmp.c \
	${TEST_PATH}strcat.c \
	${TEST_PATH}strncat.c \
	${TEST_PATH}strstr.c \
	${TEST_PATH}strlcat.c"

EX_FILES="${DIR_PATH}00/ft_strcmp.c \
	${DIR_PATH}01/ft_strncmp.c \
	${DIR_PATH}02/ft_strcat.c \
	${DIR_PATH}03/ft_strncat.c \
	${DIR_PATH}04/ft_strstr.c \
	${DIR_PATH}05/ft_strlcat.c"

#cc -Wall -Wextra -Werror main.c ${TEST_FILES} ${EX_FILES} -o testing ./testing.exe
gcc main.c ${TEST_FILES} ${EX_FILES} -o testing ./testing.exe
