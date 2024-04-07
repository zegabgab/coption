#include "option.h"

struct Option {
    void *data;
};

Option *opt_empty() {
    return opt_with(NULL);
}

Option *opt_with(
        void *value) {
    Option *opt = malloc(sizeof(Option));
    if (opt != NULL) {
        opt->data = value;
    }
    return opt;
}

int opt_has(const Option *option) {
    return option->data != NULL;
}

void *opt_unwrap(
        const Option *option) {
    return option->data;
}

void *opt_or(
        const Option *option, void *default_value) {
    return opt_has(option) ? option->data : default_value;
}

Option *opt_map(
        const Option *option, void *(*function)(void*)) {
    return opt_has(option) ?
        opt_with(function(option->data)) :
        opt_empty();
}

Option *opt_map_closure(
        const Option *option, void *context, void *(*function)(void*, void*)) {
    return opt_has(option) ?
        opt_with(function(option->data, context)) :
        opt_empty();
}
