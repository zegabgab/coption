#include <stdio.h>
#include "optional_int.c"

int square(int number) {
    return number * number;
}

int square_times(void *context, int number) {
    return number * number * *(int*) context;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Please supply an argument");
        return 1;
    }
    const int context = 69;
    OptionalInt optional = optional_int_map_closure(
            (void*) &context,
            optional_int_parse(argv[1]),
            square_times
            );
    char buffer[32];
    int ignored = optional_int_snprint(buffer, sizeof buffer, optional);
    printf("Square of supplied number times %d: %s\n", context, buffer);
    const int DEFAULT = 69;
    printf("Defaulted to %d\n", optional_int_or(optional, DEFAULT));
}
