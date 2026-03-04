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

    str_destroy(&name);
    str_destroy(&empty);

    return 0;
}