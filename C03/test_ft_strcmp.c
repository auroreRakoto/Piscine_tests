#include "C03_lib.h"

void	run_test_ft_strcmp()
{
	printf("======= ex00 - ft_strcmp =======\n");

	int ref, ft;
    char *s1;
    char *s2;

    // 1. Identical strings
    s1 = "Hello";
    s2 = "Hello";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 1 - Identical strings\n");

    // 2. First is prefix
    s1 = "Hello";
    s2 = "HelloWorld";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 2 - First is prefix\n");

    // 3. Second is prefix
    s1 = "HelloWorld";
    s2 = "Hello";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 3 - Second is prefix\n");

    // 4. Different characters
    s1 = "abc";
    s2 = "abd";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 4 - Different characters\n");

    // 5. First string empty
    s1 = "";
    s2 = "abc";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 5 - First string empty\n");

    // 6. Second string empty
    s1 = "abc";
    s2 = "";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 6 - Second string empty\n");

    // 7. Both strings empty
    s1 = "";
    s2 = "";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 7 - Both strings empty\n");

    // 8. Special characters
    s1 = "abc!";
    s2 = "abc@";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 8 - Special characters\n");

    // 9. Case sensitivity
    s1 = "abc";
    s2 = "ABC";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 9 - Case sensitivity\n");

    // 10. Extended ASCII
    s1 = "café";
    s2 = "cafe";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 10 - Extended ASCII\n");

	// 12. Long strings, last char different
    char long1[1001];
    char long2[1001];
	long2[999] = 'b';  // change last character
    s1 = long1;
    s2 = long2;
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 12 - Long strings, last char diff\n");

    // 13. Control characters
    s1 = "abc\n";
    s2 = "abc\t";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 13 - Control characters\n");

    // 14. Hidden NULL
    s1 = "abc\0def";
    s2 = "abc";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 14 - Hidden NULL\n");

    // 15. Same prefix, different lengths
    s1 = "abc";
    s2 = "abcde";
    ref = strcmp(s1, s2);
    ft = ft_strcmp(s1, s2);
    assert_int(ref, ft, "Test 15 - Same prefix, different lengths\n");
}
