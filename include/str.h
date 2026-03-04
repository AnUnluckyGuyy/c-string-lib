#ifndef STR_H
#define STR_H

#include <stddef.h>
#include <stdbool.h>

typedef struct String {
    size_t size;
    char *data;
} str;

str str_new(const char* s);
void str_destroy(str *string);
str str_empty(void);
str str_copy(const str *src);
const char *str_data(const str *string);
void str_write(str *str_dest, const char* src);
size_t str_len(const str *string);
bool str_is_empty(const str *string);

#endif