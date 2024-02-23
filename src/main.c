#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        int ret = fprintf(stderr, "invalid number of arguments\n");
        if (ret < 0) exit(1);
        return 1;
    }

    int exit_code = (long) strtol(argv[1], NULL, 10);
    if (errno == ERANGE) {
        int ret = fprintf(stderr, "invalid exit code\n");
        if (ret < 0) exit(1);
        return 1;
    }

    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
    printf("    mov rax, %d\n", exit_code);
    printf("    ret\n");

    return 0;
}
