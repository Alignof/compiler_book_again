#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        int ret = fprintf(stderr, "invalid number of arguments\n");
        if (ret < 0) exit(1);
        return 1;
    }

    char *p = argv[1];

    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");

    // rax = first number
    printf("  mov rax, %ld\n", strtol(p, &p, 10));

    while (*p) {
        if (*p == '+') {
            // consume '+'
            p++;
            // read and print numbers and increment the pointer
            printf("  add rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        if (*p == '-') {
            // consume '-'
            p++;
            // read and print numbers and increment the pointer
            printf("  sub rax, %ld\n", strtol(p, &p, 10));
            continue;
        }

        fprintf(stderr, "unexpected characters: '%c'\n", *p);  // NOLINT(cert-err33-c)
        return 1;
    }

    printf("    ret\n");

    return 0;
}
