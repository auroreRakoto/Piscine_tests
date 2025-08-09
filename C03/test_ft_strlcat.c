#include "C03_lib.h"

void run_test_ft_strlcat()
{
    printf("======= ex05 - ft_strlcat =======\n");
    char *dst1;
    char *dst2;
    char *src;
    size_t size;
    size_t ref, ft;

    // 1. Basic append
    char buf1a[100] = "Hello, ";
    char buf2a[100] = "Hello, ";
    dst1 = buf1a;
    dst2 = buf2a;
    src = "World!";
    size = 100;
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 1 - Basic append return\n");
    assert_str(dst1, dst2, "Test 1 - Basic append result\n");

    // 2. Exact fit
    char buf1b[13] = "12345";
    char buf2b[13] = "12345";
    dst1 = buf1b;
    dst2 = buf2b;
    src = "67890";
    size = 11; // 5 existing + 5 from src + 1 null = 11 total
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 2 - Exact fit return\n");
    assert_str(dst1, dst2, "Test 2 - Exact fit result\n");

    // 3. Not enough space
    char buf1c[10] = "1234";
    char buf2c[10] = "1234";
    dst1 = buf1c;
    dst2 = buf2c;
    src = "56789";
    size = 7;
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 3 - Not enough space return\n");
    assert_str(dst1, dst2, "Test 3 - Not enough space result\n");

    // 4. Size = 0
    char buf1d[10] = "start";
    char buf2d[10] = "start";
    dst1 = buf1d;
    dst2 = buf2d;
    src = "add";
    size = 0;
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 4 - Size zero return\n");
    assert_str(dst1, dst2, "Test 4 - Size zero result\n");

    // 5. Destination already full
    char buf1e[6] = "1234";
    char buf2e[6] = "1234";
    dst1 = buf1e;
    dst2 = buf2e;
    src = "abc";
    size = 5;
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 5 - Destination full return\n");
    assert_str(dst1, dst2, "Test 5 - Destination full result\n");

    // 6. Empty src
    char buf1f[20] = "already";
    char buf2f[20] = "already";
    dst1 = buf1f;
    dst2 = buf2f;
    src = "";
    size = 20;
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 6 - Empty src return\n");
    assert_str(dst1, dst2, "Test 6 - Empty src result\n");

    // 7. Empty dst
    char buf1g[20] = "";
    char buf2g[20] = "";
    dst1 = buf1g;
    dst2 = buf2g;
    src = "fill";
    size = 10;
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 7 - Empty dst return\n");
    assert_str(dst1, dst2, "Test 7 - Empty dst result\n");

    // 8. Both empty
    char buf1h[5] = "";
    char buf2h[5] = "";
    dst1 = buf1h;
    dst2 = buf2h;
    src = "";
    size = 5;
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 8 - Both empty return\n");
    assert_str(dst1, dst2, "Test 8 - Both empty result\n");

    // 9. Long src, small dst
    char buf1i[15] = "head:";
    char buf2i[15] = "head:";
    dst1 = buf1i;
    dst2 = buf2i;
    char long_src[1001];
    memset(long_src, 'x', 1000);
    long_src[1000] = '\0';
    src = long_src;
    size = 15;
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 9 - Long src return\n");
    assert_str(dst1, dst2, "Test 9 - Long src result\n");

    // 10. Add space character
    char buf1j[20] = "Hello";
    char buf2j[20] = "Hello";
    dst1 = buf1j;
    dst2 = buf2j;
    src = " ";
    size = 20;
    ref = strlcat(dst1, src, size);
    ft = ft_strlcat(dst2, src, size);
    assert_int(ref, ft, "Test 10 - Add space return\n");
    assert_str(dst1, dst2, "Test 10 - Add space result\n");
}
