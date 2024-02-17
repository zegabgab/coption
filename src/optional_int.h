// This is an optional monad for integers (the int type, whatever that might be on your system).
// Because reasons.

// The basic type
typedef struct optional_int optional_int;

// Basic constructor with data
optional_int optional_int_with(int value);

// Basic constructor without data
optional_int optional_int_empty();

// Constructor that attempts to parse a string for its data and returns an empty on failure
optional_int optional_int_parse(const char *source);

// Returns a boolean value that indicates whether the optional has any data
int optional_int_has(optional_int optional);

// Returns the contained value if there is one. Calling this on a value whose
// optional_int_has returns 0 is undefined behaviour.
int optional_int_unwrap(optional_int optional);

// Maps a raw function pointer to optional's data, if it exists
optional_int optional_int_map(optional_int optional, int (*function)(int));

// Prints the optional_int to the given buffer, for up to n characters.
// Returns the number of characters printed.
int optional_int_snprint(char *buffer, size_t buffer_size, optional_int optional);
