#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "str.h"

str str_new(const char* s) {
    if (!s) { return (str) {.size = 0, .data = NULL}; }
    str string = {.size = 0, .data = NULL};
    size_t str_size = strlen(s);
    string.data = malloc(str_size+1);
    if (string.data == NULL) { return string; }
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
    if (!string->data) { return ""; }
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
    if (string->size == 0) { return true; }
    return false;
}

bool str_equals(const str *s1, const str *s2) {
    if (!s1->data || !s2->data) { return false; }
    if (s1->size != s2->size) { return false; }
    size_t len = str_len(s1);
    for (size_t i = 0; i<len; i++) {
        char c1 = str_at(s1, i);
        char c2 = str_at(s2, i);
        if (c1 != c2) { return false; }
    }
    return true;
}

char str_at(const str *string, size_t index) {
    if (index >= string->size) { return '\0'; }
    if (!string->data) { return '\0'; }
    return string->data[index];
}

void str_append(str *dest, const str *append_string) {
    size_t dest_len = str_len(dest);
    size_t append_len = str_len(append_string);
    size_t new_size = dest_len+append_len;
    char *temp = malloc(new_size+1);

    size_t temp_index = 0;

    for (size_t i = 0; i<dest_len; i++) {
        temp[temp_index] = str_at(dest, i);
        temp_index++;
    }

    for (size_t i = 0; i<dest_len; i++) {
        temp[temp_index] = str_at(append_string, i);
        temp_index++;
    }
    // printf("temp: %s\n", temp);
    str_destroy(dest);
    *dest = str_new(temp);
    free(temp);
}

bool str_startswith(const str *string, const str *prefix) {
    size_t str_length = str_len(string);
    size_t prefix_length= str_len(prefix);
    if (prefix_length > str_length) { return false; }

    for (size_t i = 0; i<str_length; i++) {
        if (i >= prefix_length) {
            break;
        }
        if (str_at(prefix, i) != str_at(string, i)) {
            return false;
        }
    }
    return true;
}

bool str_endswith(const str *string, const str *sufix) {
    if (str_len(sufix) > str_len(string)) { return false; }

    size_t str_index = str_len(string)-1;
    size_t sufix_index = str_len(sufix)-1;

    while (str_index != 0 || sufix_index != 0) {
        if (str_index == 0 || sufix_index == 0) { break; }
        if (str_at(sufix, sufix_index) != str_at(string, str_index)) {
            printf("sufix: %c, string: %c\n", str_at(sufix, sufix_index), str_at(string, str_index));
            return false;
        }
        str_index--;
        sufix_index--;
    }
    return true;
}