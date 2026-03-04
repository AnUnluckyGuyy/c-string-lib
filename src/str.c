#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "str.h"

str str_new(const char* s) {
    str string = { .size = 0 };
    size_t str_size = strlen(s);
    string.data = malloc(str_size+1);
    if (string.data == NULL) return string;
    strcpy(string.data, s);
    string.size = str_size;
    return string;
}

void str_destroy(str *string) {
    free(string->data);
    string->data = NULL;
    string->size = 0;
}

str str_empty(void) {
    return str_new("");
}

str str_copy(const str *src) {
    str new = str_new(src->data);
    return new;
}

const char *str_data(const str *string) {
    if (!string->data) return "";
    return string->data;
}

void str_write(str *str_dest, const char* src) {
    str_destroy(str_dest);
    *str_dest = str_new(src);
}

size_t str_len(const str *string) {
    return string->size;
}

bool str_is_empty(const str *string) {
    if (string->size == 0) {
        return true;
    }
    return false;
}