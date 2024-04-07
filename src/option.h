#ifndef __OPTION__
#define __OPTION__

#include <stdlib.h>

// This is an optional monad for generic types.
// Because reasons.

typedef struct Option Option;

// Basic constructor without data
Option *opt_empty();

// Basic constructor with data. Returns an empty if value is null
Option *opt_with(
        void *value
        );

// Returns a boolean value that indicates whether the option has any data
void *opt_has(
        const Option option
        );

// Returns the contained value if there is one. Calling this on a value whose
// option_has returns 0 is undefined behaviour.
void *opt_unwrap(
        const Option option
        );

// Returns the contained value if there is one, or default_value if there is none.
void *opt_or(
        const Option option, int default_value
        );

// Maps a raw function pointer to option's data, if it exists
Option *opt_map(
        const Option option, int (*function)(int)
        );

// Maps a function pointer with context to the option
Option *opt_map_closure(
        const Option *option, void *context, int (*function)(void*, void*)
        );

// Prints the Option to the given buffer, for up to n characters.
// Returns the number of characters printed.
int opt_snprint(
        char *buffer, size_t buffer_size, const Option *option
        );

#endif
