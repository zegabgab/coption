#include <stdlib.h>

// This is an optional monad for integers (the int type, whatever that might be on your system).
// Because reasons.

// The basic type
typedef struct OptionalInt OptionalInt;

struct OptionalInt {
    int value;
    int has;
};

// Basic constructor with data
OptionalInt optional_int_with(int value);

// Basic constructor without data
OptionalInt optional_int_empty();

// Constructor that attempts to parse a string for its data and returns an empty on failure
OptionalInt optional_int_parse(const char *source);

// Returns a boolean value that indicates whether the optional has any data
int optional_int_has(const OptionalInt optional);

// Returns the contained value if there is one. Calling this on a value whose
// optional_int_has returns 0 is undefined behaviour.
int optional_int_unwrap(const OptionalInt optional);

// Returns the contained value if there is one, or default_value if there is none.
int optional_int_or(const OptionalInt optional, int default_value);

// Maps a raw function pointer to optional's data, if it exists
OptionalInt optional_int_map(const OptionalInt optional, int (*function)(int));

// Prints the OptionalInt to the given buffer, for up to n characters.
// Returns the number of characters printed.
int optional_int_snprint(char *buffer, size_t buffer_size, const OptionalInt optional);
