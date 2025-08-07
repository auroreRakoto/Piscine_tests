#include "C03_lib.h"

void run_test_ft_strstr()
{
    printf("======= ex04 - ft_strstr =======\n");
    char *s1;
    char *s2;

    // 1. Substring in middle
    s1 = "This is a simple string";
    s2 = "simple";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 1 - Substring in middle\n");

    // 2. Substring at start
    s1 = "Hello world";
    s2 = "Hello";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 2 - Substring at start\n");

    // 3. Substring at end
    s1 = "Look for this!";
    s2 = "this!";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 3 - Substring at end\n");

    // 4. Needle not found
    s1 = "abcdefg";
    s2 = "xyz";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 4 - Needle not found\n");

    // 5. Empty needle
    s1 = "Non-empty string";
    s2 = "";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 5 - Empty needle\n");

    // 6. Empty haystack
    s1 = "";
    s2 = "test";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 6 - Empty haystack\n");

    // 7. Both empty
    s1 = "";
    s2 = "";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 7 - Both empty\n");

    // 8. Full match
    s1 = "matchme";
    s2 = "matchme";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 8 - Full string match\n");

    // 9. Repeated patterns
    s1 = "ababababab";
    s2 = "abab";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 9 - Repeated pattern\n");

    // 10. Special characters
    s1 = "!@#$$%^&*()";
    s2 = "$%^";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 10 - Special characters\n");

    // 11. Long string
    char long_str[2001];
    char *needle = "end!";
    memset(long_str, 'a', 1996);
    long_str[1996] = 'e';
    long_str[1997] = 'n';
    long_str[1998] = 'd';
    long_str[1999] = '!';
    long_str[2000] = '\0';
    s1 = long_str;
    s2 = needle;
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 11 - Long haystack, needle at end\n");

    // 12. Needle longer than haystack
    s1 = "short";
    s2 = "longneedle";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 12 - Needle longer than haystack\n");

    // 13. Needle is a single char
    s1 = "abcdefg";
    s2 = "e";
    assert_str(strstr(s1, s2), ft_strstr(s1, s2), "Test 13 - Single character match\n");
}
