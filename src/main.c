#include <stdio.h>
#include "optional_int.h"
#include "optional_int.c"

int square(int number) {
    return number * number;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Please supply an argument");
        return 1;
    }
    optional_int optional = optional_int_map(
        optional_int_parse(argv[1]),
        square
    );
    char buffer[32];
    int ignored = optional_int_snprint(buffer, sizeof buffer, optional);
    printf("Square of supplied number: %s\n", buffer);
}
