#include <stdio.h>
#include "str.h"

int main(void) {
    str name = str_new("john");
    printf("name: %s\n", str_data(&name));

    str empty = str_empty();
    printf("empty: %s\n", str_data(&empty));
    
    str_write(&empty, str_data(&name));
    printf("after copy, empty: %s\n", str_data(&empty));
    
    str_equals(&empty, &name);

    str_write(&name, "alice");
    printf("name after write: %s\n", str_data(&name));

    str_equals(&empty, &name);

    str text = str_new("a");
    str prefix = str_new("abcdef");
    if (str_startswith(&text, &prefix)) {
        printf("Starts with: %s\n", str_data(&prefix));
    } else {
        printf("It does not start with: %s\n", str_data(&prefix));
    }

    str_destroy(&text);
    str_destroy(&prefix);

    text = str_new("alice");
    str sufix = str_new("ice");
    if (str_endswith(&text, &sufix)) {
        printf("Ends with: %s\n", str_data(&sufix));
    } else {
        printf("It does not end with: %s\n", str_data(&sufix));
    }

    str_destroy(&text);
    str_destroy(&sufix);

    str x = str_new("abc");
    str y = str_new("def");
    str_append(&x, &y);
    printf("x: %s\n", str_data(&x));

    str_destroy(&name);
    str_destroy(&empty);
    str_destroy(&x);
    str_destroy(&y);

    return 0;
}