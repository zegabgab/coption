#include "option.h"

struct Option {
    void *data;
};

Option *opt_empty() {
    return opt_with(NULL);
}

Option *opt_with(void *value) {
    Option *opt = malloc(sizeof(Option));
    if (opt != NULL) {
        opt-> data = value;
    }
    return opt;
}
