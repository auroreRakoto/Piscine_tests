#include "test_framework.h"

void run_test_ft_strlcpy()
{
	printf("========= ex10 =========\n");

	char src1[] = "Hello world!";
	char dst1[20];
	unsigned int ret1 = ft_strlcpy(dst1, src1, 20);
	assert_str(src1, dst1, "Test 1 - normal copy");
	assert_uint(strlen(src1), ret1, "Test 1 - return value");

	char src2[] = "Short";
	char dst2[3];
	unsigned int ret2 = ft_strlcpy(dst2, src2, 3);
	assert_str("Sh", dst2, "Test 2 - truncate");
	assert_uint(strlen(src2), ret2, "Test 2 - return value");

	char src3[] = "Nothing";
	char dst3[1];
	char dest3_ref[1];
	unsigned int ret3 = ft_strlcpy(dst3, src3, 0);
	//assert_str("", dst3, "Test 3 - size 0 means no copy");
	assert_uint(strlen(src3), ret3, "Test 3 - size 0 return value");

	char src4[] = "";
	char dst4[10];
	unsigned int ret4 = ft_strlcpy(dst4, src4, 10);
	assert_str("", dst4, "Test 4 - empty source");
	assert_uint(0, ret4, "Test 4 - return value");
}
