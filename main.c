#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include "ft_printf.h"

int main(void)
{
    int ret_libc, ret_ft;
    void *ptr = (void *)ULONG_MAX;

    // %p - ponteiros
    printf("=== Teste %%p ===\n");
    ret_libc = printf("libc: %p\n", NULL);
    ret_ft   = ft_printf("ft  : %p\n", NULL);
    printf("ret libc=%d | ret ft=%d\n\n", ret_libc, ret_ft);

    ret_libc = printf("libc: %p\n", ptr);
    ret_ft   = ft_printf("ft  : %p\n", ptr);
    printf("ret libc=%d | ret ft=%d\n\n", ret_libc, ret_ft);

    // %u - unsigned int
    printf("=== Teste %%u ===\n");
    ret_libc = printf("libc: %u\n", 0u);
    ret_ft   = ft_printf("ft  : %u\n", 0u);
    printf("ret libc=%d | ret ft=%d\n\n", ret_libc, ret_ft);

    ret_libc = printf("libc: %u\n", UINT_MAX);
    ret_ft   = ft_printf("ft  : %u\n", UINT_MAX);
    printf("ret libc=%d | ret ft=%d\n\n", ret_libc, ret_ft);

    ret_libc = printf("libc: %u\n", (unsigned int)INT_MAX + 1);
    ret_ft   = ft_printf("ft  : %u\n", (unsigned int)INT_MAX + 1);
    printf("ret libc=%d | ret ft=%d\n\n", ret_libc, ret_ft);

    // mix simples
    printf("=== Teste MIX simples ===\n");
    ret_libc = printf("libc: %c %s %p %d %i %u %x %X %%\n",
                      'A', "teste", ptr, INT_MIN, INT_MAX,
                      UINT_MAX, 0xabcdef, 0xABCDEF);
    ret_ft   = ft_printf("ft  : %c %s %p %d %i %u %x %X %%\n",
                      'A', "teste", ptr, INT_MIN, INT_MAX,
                      UINT_MAX, 0xabcdef, 0xABCDEF);
    printf("ret libc=%d | ret ft=%d\n\n", ret_libc, ret_ft);

    // mix EXTREMO — muitos especificadores
    printf("=== Teste MIX extremo ===\n");
    ret_libc = printf(
        "libc: %c%s%p%d%i%u%x%X%%%c%s%p%d%i%u%x%X%%\n",
        'A', "abc", ptr, INT_MIN, INT_MAX, UINT_MAX, 0xabc, 0xABC,
        'Z', "xyz", (void *)0x42, -42, 42, 424242, 0x123, 0x456
    );
    ret_ft = ft_printf(
        "ft  : %c%s%p%d%i%u%x%X%%%c%s%p%d%i%u%x%X%%\n",
        'A', "abc", ptr, INT_MIN, INT_MAX, UINT_MAX, 0xabc, 0xABC,
        'Z', "xyz", (void *)0x42, -42, 42, 424242, 0x123, 0x456
    );
    printf("ret libc=%d | ret ft=%d\n\n", ret_libc, ret_ft);

    return 0;
}

