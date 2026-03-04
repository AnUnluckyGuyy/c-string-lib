#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "str.h"

str str_new(const char* s) {
    if (!s) return (str) {.size = 0, .data = NULL};
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

bool str_equals(const str *s1, const str *s2) {
    if (!s1->data || !s2->data) return false;
    if (s1->size != s2->size) return false;
    size_t len = str_len(s1);
    for (size_t i = 0; i<len; i++) {
        char c1 = str_at(s1, i);
        char c2 = str_at(s2, i);
        if (c1 != c2) {
            return false;
        }
    }
    return true;
}

char str_at(const str *string, size_t index) {
    if (index >= string->size) return '\0';
    if (!string->data) return '\0';
    return string->data[index];
}