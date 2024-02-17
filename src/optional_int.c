#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include "optional_int.h"

struct optional_int {
    int value;
    int has;
};

optional_int optional_int_with(int value) {
    return (optional_int) { .value = value, .has = 1 };
}

optional_int optional_int_empty() {
    return (optional_int) { .value = 0, .has = 0 };
}

optional_int optional_int_parse(const char *source) {
    char *end;
    errno = 0;
    long result = strtol(source, &end, 0);
    return (errno == 0 && result <= INT_MAX && result >= INT_MIN && end != source) ?
        optional_int_with((int) result) :
        optional_int_empty();
}

int optional_int_has(optional_int optional) {
    return optional.has;
}

int optional_int_unwrap(optional_int optional) {
    return optional.value;
}

optional_int optional_int_map(optional_int optional, int (*function)(int)) {
    return optional_int_has(optional) ?
        optional_int_with(function(optional_int_unwrap(optional))) :
        optional;
}

int optional_int_snprint(char *buffer, size_t buffer_size, optional_int optional) {
    return optional_int_has(optional) ?
        snprintf(buffer, buffer_size, "%d", optional.value) :
        snprintf(buffer, buffer_size, "Empty");
}
