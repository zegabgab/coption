#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include "optional_int.h"

OptionalInt optional_int_with(int value) {
    return (OptionalInt) { .value = value, .has = 1 };
}

OptionalInt optional_int_empty() {
    return (OptionalInt) { .value = 0, .has = 0 };
}

OptionalInt optional_int_parse(const char *source) {
    char *end;
    errno = 0;
    long result = strtol(source, &end, 0);
    return (errno == 0 && result <= INT_MAX && result >= INT_MIN && end != source) ?
        optional_int_with((int) result) :
        optional_int_empty();
}

int optional_int_has(OptionalInt optional) {
    return optional.has;
}

int optional_int_unwrap(OptionalInt optional) {
    return optional.value;
}

OptionalInt optional_int_map(OptionalInt optional, int (*function)(int)) {
    return optional_int_has(optional) ?
        optional_int_with(function(optional_int_unwrap(optional))) :
        optional;
}

int optional_int_snprint(char *buffer, size_t buffer_size, OptionalInt optional) {
    return optional_int_has(optional) ?
        snprintf(buffer, buffer_size, "%d", optional.value) :
        snprintf(buffer, buffer_size, "Empty");
}
