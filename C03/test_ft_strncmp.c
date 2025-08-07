#include "C03_lib.h"

void run_test_ft_strncmp()
{
    printf("======= ex01 - ft_strncmp =======\n");
    int ref, ft, n;
    char *s1;
    char *s2;

    // 1. Identical strings, n = full length
    s1 = "Hello";
    s2 = "Hello";
    n = 5;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 1 - Identical strings, full length\n");

    // 2. Identical strings, n = 3
    s1 = "Hello";
    s2 = "Hello";
    n = 3;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 2 - Identical strings, len < size\n");

    // 3. Different strings, diff after n
    s1 = "abcdef";
    s2 = "abcxyz";
    n = 3;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 3 - Difference after n\n");

    // 4. Different strings, diff at n
    s1 = "abcdef";
    s2 = "abcxyz";
    n = 4;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 4 - Difference at n\n");

    // 5. One empty string
    s1 = "";
    s2 = "abc";
    n = 3;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 5 - First string empty\n");

    // 6. Second empty string
    s1 = "abc";
    s2 = "";
    n = 3;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 6 - Second string empty\n");

    // 7. Both empty
    s1 = "";
    s2 = "";
    n = 1;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 7 - Both strings empty\n");

    // 8. Special characters
    s1 = "abc!";
    s2 = "abc@";
    n = 4;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 8 - Special characters\n");

    // 9. Case sensitivity
    s1 = "abc";
    s2 = "ABC";
    n = 3;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 9 - Case sensitivity\n");

    /*
    // 10. Extended ASCII
    s1 = "café";
    s2 = "cafe";
    n = 4;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 10 - Extended ASCII\n");
    
    // 11. Long identical strings, large n
    char long1[1001];
    char long2[1001];
    memset(long1, 'a', n);
    memset(long2, 'a', n);
    long1[1000] = '\0';
    long2[1000] = '\0';
    s1 = long1;
    s2 = long2;
    n = 1000;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 11 - Long identical strings\n");

    // 12. Long strings, diff at end
    long2[999] = 'b';
    s1 = long1;
    s2 = long2;
    n = 1000;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 12 - Long strings, last char diff\n");
    */

    // 13. Control characters
    s1 = "abc\n";
    s2 = "abc\t";
    n = 4;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 13 - Control characters\n");

    // 14. n = 0 should always return 0
    s1 = "abc";
    s2 = "xyz";
    n = 0;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 14 - n = 0\n");

    // 15. One string shorter than n
    s1 = "abc";
    s2 = "abcde";
    n = 5;
    ref = strncmp(s1, s2, n);
    ft = ft_strncmp(s1, s2, n);
    assert_int(ref, ft, "Test 15 - Shorter string vs longer\n");
}