#include "C03_lib.h"

void run_test_ft_strcat()
{
    printf("======= ex02 - ft_strcat =======\n");
    char *s1;
    char *s2;
    char *src;

    // 1. Basic concatenation
    char buf1a[100] = "Hello, ";
    char buf2a[100] = "Hello, ";
    s1 = buf1a;
    s2 = buf2a;
    src = "World!";
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 1 - Basic concat\n");

    // 2. Append empty string
    char buf1b[100] = "Hello";
    char buf2b[100] = "Hello";
    s1 = buf1b;
    s2 = buf2b;
    src = "";
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 2 - Append empty string\n");

    // 3. Destination is empty
    char buf1c[100] = "";
    char buf2c[100] = "";
    s1 = buf1c;
    s2 = buf2c;
    src = "World";
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 3 - Empty destination\n");

    // 4. Append to single char
    char buf1d[100] = "A";
    char buf2d[100] = "A";
    s1 = buf1d;
    s2 = buf2d;
    src = "B";
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 4 - Single char destination\n");

    // 5. Append special characters
    char buf1e[100] = "123";
    char buf2e[100] = "123";
    s1 = buf1e;
    s2 = buf2e;
    src = "!@#";
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 5 - Special characters\n");

    // 6. Append space
    char buf1f[100] = "Hello";
    char buf2f[100] = "Hello";
    s1 = buf1f;
    s2 = buf2f;
    src = " ";
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 6 - Append space\n");

    // 7. Long source append
    char long_src[1001];
    memset(long_src, 'x', 1000);
    long_src[1000] = '\0';

    char buf1g[2000] = "Start:";
    char buf2g[2000] = "Start:";
    s1 = buf1g;
    s2 = buf2g;
    src = long_src;
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 7 - Long source append\n");

    // 8. Both strings empty
    char buf1h[10] = "";
    char buf2h[10] = "";
    s1 = buf1h;
    s2 = buf2h;
    src = "";
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 8 - Both strings empty\n");

    // 9. Source with hidden null
    char hidden_null_src[10] = {'a', 'b', 'c', '\0', 'd', 'e', 'f'};
    char buf1i[20] = "X:";
    char buf2i[20] = "X:";
    s1 = buf1i;
    s2 = buf2i;
    src = hidden_null_src;
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 9 - Source with hidden null\n");

    // 10. Append numeric string
    char buf1j[100] = "Number: ";
    char buf2j[100] = "Number: ";
    s1 = buf1j;
    s2 = buf2j;
    src = "1234567890";
    assert_str(strcat(s1, src), ft_strcat(s2, src), "Test 10 - Append digits\n");
}
