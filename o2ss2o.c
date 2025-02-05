#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

const char *codes[8] = {
    "---",
    "--x",
    "-w-",
    "-wx",
    "r--",
    "r-x",
    "rw-",
    "rwx"
};

void o2s(const char *input) {
    for (size_t i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
            printf("%s", codes[input[i] - '0']);
    }
    printf("\n");
}

void s2o(const char *input) {
    char fnc_name[4] = {0};
    for (size_t i = 0; i < strlen(input); i += 3) {
        strncpy(fnc_name, input + i, 3);
        fnc_name[3] = '\0';
        for (int j = 0; j < 8; j++) {
            if (strcmp(codes[j], fnc_name) == 0) {
                printf("%d", j);
                break;
            }
        }
    }
    printf("\n");
}

void print_help() {
    printf("NAME\n");
    printf("    o2ss2o [o2s|s2o] - convert file's permissions between octal and symbolic formats'\n");
    printf("\n");
    printf("SYNOPSIS\n");
    printf("    ./o2ss2o [OPTION]... [ARGUMENT]...\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("    -h, --help display this help and exit\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help();
        return 0;
    }

    if (strcmp(argv[0], "./o2s") == 0) {
        o2s(argv[1]);
    } else if (strcmp(argv[0], "./s2o") == 0) {
        s2o(argv[1]);
    } else if (strcmp(argv[1], "s2o") == 0) {
        s2o(argv[2]);
    } else if (strcmp(argv[1], "o2s") == 0) {
        o2s(argv[2]);
    } else {
        print_help();
        return 1;
    }

    return 0;
}
