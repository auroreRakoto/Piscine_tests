#include "test_framework.h"

void run_test_ft_print_memory()
{
    printf("======= ex12 =======\n");

    char *addr;
    size_t size;

    // 1. Basic string
    char data1[] = "Hello, World!";
    addr = data1;
    size = 13;
    printf(ORANGE "Test 1 - Basic string:\n" RESET);
    ft_print_memory(addr, size);
    printf("\n\n");

    // 2. Empty buffer
    char data2[] = "";
    addr = data2;
    size = 0;
    printf(ORANGE "Test 2 - Empty buffer:\n" RESET);
    ft_print_memory(addr, size);
    printf("\n\n");

    // 3. Exact 16 bytes
    char data3[] = "1234567890abcdef";
    addr = data3;
    size = 16;
    printf(ORANGE "Test 3 - Exactly 16 bytes:\n" RESET);
    ft_print_memory(addr, size);
    printf("\n\n");

    // 4. Non-printable characters
    char data4[] = {0x00, 0x01, 0x02, 0x10, 0x7F, 0xFF, 'A', 'B', '\n', '\t', 'Z', 0x0B, 0x0C, 0x1F, 0x20, 0x21};
    addr = data4;
    size = 16;
    printf(ORANGE "Test 4 - Non-printable characters:\n" RESET);
    ft_print_memory(addr, size);
    printf("\n\n");

    // 5. Long buffer (more than 32 bytes)
    char data5[64];
    for (int i = 0; i < 64; i++)
        data5[i] = (i % 26) + 'A';  // A B C ...
    addr = data5;
    size = 64;
    printf(ORANGE "Test 5 - 64 bytes buffer:\n" RESET);
    ft_print_memory(addr, size);
    printf("\n\n");

    // 6. Binary-like content
    char data6[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xCA, 0xFE, 0xBA, 0xBE};
    addr = data6;
    size = sizeof(data6);
    printf(ORANGE "Test 6 - Binary-looking data:\n" RESET);
    ft_print_memory(addr, size);
    printf("\n\n");	
}


