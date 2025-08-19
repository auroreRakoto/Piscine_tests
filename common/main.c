
#include <stdio.h>
#include "tests.h"

/* Build-time selector: -DTEST_TARGET=C04 (token, not string) */
#ifndef TEST_TARGET
# define TEST_TARGET C00
#endif

/* token pasting: test_ + C04 -> test_C04 */
#define CAT(a,b) a##b
#define XCAT(a,b) CAT(a,b)
#define TEST_FN XCAT(test_, TEST_TARGET)

/* stringification for pretty title */
#define STR1(x) #x
#define STR(x)  STR1(x)

int main(void)
{
    printf("===== Tests %s =====\n", STR(TEST_TARGET));
    TEST_FN();
    return 0;
}
