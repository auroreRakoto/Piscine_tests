#include "C03_lib.h"

void run_test_ft_strncat()
{
    printf("======= ex03 - ft_strncat =======\n");
    char *s1;
    char *s2;
    char *src;
    int n;

    // 1. Basic append
    char buf1a[100] = "Hello, ";
    char buf2a[100] = "Hello, ";
    s1 = buf1a;
    s2 = buf2a;
    src = "World!";
    n = 3;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 1 - Append 3 chars\n");

    // 2. Append 0 chars
    char buf1b[100] = "Hello";
    char buf2b[100] = "Hello";
    s1 = buf1b;
    s2 = buf2b;
    src = "World";
    n = 0;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 2 - Append 0 chars\n");

    // 3. Append full source
    char buf1c[100] = "Hi ";
    char buf2c[100] = "Hi ";
    s1 = buf1c;
    s2 = buf2c;
    src = "there!";
    n = 10;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 3 - Append all chars\n");

    // 4. Empty destination
    char buf1d[100] = "";
    char buf2d[100] = "";
    s1 = buf1d;
    s2 = buf2d;
    src = "New";
    n = 2;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 4 - Empty destination\n");

    // 5. Empty source
    char buf1e[100] = "Test";
    char buf2e[100] = "Test";
    s1 = buf1e;
    s2 = buf2e;
    src = "";
    n = 5;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 5 - Empty source\n");

    // 6. Both empty
    char buf1f[10] = "";
    char buf2f[10] = "";
    s1 = buf1f;
    s2 = buf2f;
    src = "";
    n = 3;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 6 - Both empty\n");

    // 7. Special characters
    char buf1g[100] = "ABC";
    char buf2g[100] = "ABC";
    s1 = buf1g;
    s2 = buf2g;
    src = "!@#";
    n = 2;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 7 - Special chars\n");

    // 8. Append space
    char buf1h[100] = "Name";
    char buf2h[100] = "Name";
    s1 = buf1h;
    s2 = buf2h;
    src = " ";
    n = 1;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 8 - Append space\n");

    // 9. Long source, short append
    char buf1i[100] = "Start:";
    char buf2i[100] = "Start:";
    s1 = buf1i;
    s2 = buf2i;
    char long_src[1001];
    memset(long_src, 'x', 1000);
    long_src[1000] = '\0';
    src = long_src;
    n = 5;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 9 - Long source, short n\n");

    // 10. Append numbers (as string)
    char buf1j[100] = "Val: ";
    char buf2j[100] = "Val: ";
    s1 = buf1j;
    s2 = buf2j;
    src = "1234567890";
    n = 4;
    assert_str(strncat(s1, src, n), ft_strncat(s2, src, n), "Test 10 - Append numbers\n");
}
